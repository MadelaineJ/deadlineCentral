// custom header files
#include "taskDb.hpp"
#include "task.hpp"
#include "controllerDb.hpp"

TaskDB *TaskDB::instance = nullptr; // initialize the static pointer

TaskDB* TaskDB::getInstance() {
    if(instance == nullptr) {
        instance = new TaskDB();
    }
    return instance;
}

TaskDB::TaskDB() {}
TaskDB::~TaskDB() {}

// inserts a new task into the db
int TaskDB::createTask(Task task){
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    string ownerColumn; // = courseID, studentID or instructorID

    // determine who owns the task to add id into correct column in DB
    if(task.getTaskOwner() < 1000){ // then it's a student
        ownerColumn = "studentID";
    } else if(task.getTaskType() < 10) {
        ownerColumn = "courseID";
    } else {
        ownerColumn = "instructorID";
    }
    
    queryBuilder << "INSERT INTO "
                 << "Tasks(type, name, description, dueDate, weight, isComplete, "
                 << ownerColumn << ") "
                 << "VALUES(:1, :2, :3, TO_DATE(:4, 'MM-DD-YYYY'), :5, :6, :7) "
                 << "RETURNING taskID INTO :8";

    string query = queryBuilder.str();
    Statement *stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setInt(1, task.getTaskType());
    stmt->setString(2, task.getTaskName());
    stmt->setString(3, task.getTaskDescription());
    stmt->setString(4, task.getDueDate());
    stmt->setDouble(5, task.getWeight());
    stmt->setInt(6, task.getCompletionStatus());
    stmt->setInt(7, task.getTaskOwner());

    stmt->registerOutParam(8, OCCIINT); // Register the return generated ID

    stmt->executeUpdate();

    int gen_taskID = -1; // initialize to centinal value

    // retrieve auto generated ID
    gen_taskID = stmt->getInt(8);

    // Commit the transaction or changes will revert after connection is closed
    controllerDB->getConnection()->commit();

    controllerDB->disconnect();

    return gen_taskID;
}

// updates an existing task in the db
bool TaskDB::updateTask(Task task){
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "UPDATE Tasks "
                 << "SET "
                 << "type = :1, "
                 << "name = :2, "
                 << "description = :3, "
                 << "dueDate = TO_DATE(:4, 'MM-DD-YYYY'), "
                 << "weight = :5, "
                 << "isComplete = :6 "
                 << "WHERE taskID = :7 ";

    string query = queryBuilder.str();
    Statement *stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setInt(1, task.getTaskType());
    stmt->setString(2, task.getTaskName());
    stmt->setString(3, task.getTaskDescription());
    stmt->setString(4, task.getDueDate());
    stmt->setDouble(5, task.getWeight());
    stmt->setInt(6, task.getCompletionStatus());
    
    stmt->setInt(7, task.getTaskId());

    int rowCount = stmt->executeUpdate(); // returns rows affected (should be 1)

    // Commit the transaction or changes will revert after connection is closed
    controllerDB->getConnection()->commit();

    controllerDB->disconnect();

    if(rowCount == 1){
        return true;
    }
    return false;
}

// removes a task entry from the db
bool TaskDB::deleteTask(Task task){
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();  

    stringstream queryBuilder;
    queryBuilder << "DELETE FROM Tasks "
                 << "WHERE taskID = :1 ";

    string query = queryBuilder.str();
    Statement *stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setInt(1, task.getTaskId());

    int rowCount = stmt->executeUpdate();

    // Commit the transaction or changes will revert after connection is closed
    controllerDB->getConnection()->commit();

    controllerDB->disconnect();

    if(rowCount == 1){
        return true;
    }
    return false;
}

// returns one task object from a taskId 
Task TaskDB::getTaskInfo(int taskId) {
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "SELECT "
                 << "taskID, type, name, description, "
                 << "TO_CHAR(dueDate, 'MM/DD/YYYY'), " 
                 << "weight, isComplete, courseID, studentID, instructorID "
                 << "FROM Tasks "
                 << "WHERE taskID = :1 ";

    string query = queryBuilder.str();
    Statement *stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setInt(1, taskId);

    ResultSet *rs = stmt->executeQuery();

    Task task(-1, "", -1, -1, "", "", false, -1.0);
    if (rs->next()) {
        task.setTaskId(rs->getInt(1));
        task.setTaskType(rs->getInt(2));
        task.setTaskName(rs->getString(3));
        task.setTaskDescription(rs->getString(4));
        task.setDueDate(rs->getString(5));
        task.setWeight(rs->getFloat(6));
        task.setCompletionStatus(rs->getInt(7) != 0);

        int courseID = rs->getInt(8);
        int studentID = rs->getInt(9);
        int instructorID = rs->getInt(10);

        if (courseID != 0) {
            task.setTaskOwner(courseID);
        } else if (studentID != 0) {
            task.setTaskOwner(studentID);
        } else if (instructorID != 0) {
            task.setTaskOwner(instructorID);
        }
    }
    controllerDB->disconnect();
    return task;
}

// returns a list of tasks that match the 'filter' params passed to it
list<Task> TaskDB::getFilteredTasks(int typeFilter, int courseFilter, int completedFilter, int daysPriorFilter, int daysFutureFilter, int userID) {
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    // we need to construct the query based on the type of user, and the filter parameters they have chosen
    stringstream queryBuilder;
    queryBuilder << "SELECT * FROM ( "
                << "SELECT taskID, type, name, description, "
                << "TO_CHAR(dueDate, 'MM/DD/YYYY'), dueDate, "
                << "weight, isComplete, courseID, studentID, instructorID "
                << "FROM Tasks "
                << "WHERE courseID IN ( "
                << "SELECT courseID "
                << "FROM ";

    if(userID < 1000){
        // student user
        queryBuilder << "StudentCourses "
                    << "WHERE studentID = :studentID "
                    << ") OR "
                    << "studentID = :studentID "
                    << ") ";
    } else {
        // instructor user
        queryBuilder << "Courses "
                    << "WHERE instructorID = :instructorID "
                    << ") OR "
                    << "instructorID = :instructorID "
                    << ") ";
    }


    bool hasFilter = false; // flag for adjusting query syntax

    // apply filter modifiers as needed
    if(typeFilter != -1) {
        queryBuilder << "WHERE type = " << typeFilter << " ";
        hasFilter = true;
    }

    if(courseFilter > 0){
        queryBuilder << (hasFilter ? "AND" : "WHERE") << " courseID = " << courseFilter << " ";
        hasFilter = true;
    }
    
    if(completedFilter == 0 || completedFilter == 1){
        queryBuilder << (hasFilter ? "AND" : "WHERE") << " isComplete = " << completedFilter << " ";
        hasFilter = true;
    }

    if(daysPriorFilter > 0 || daysFutureFilter > 0) {
        queryBuilder << (hasFilter ? "AND" : "WHERE")
                     << " dueDate BETWEEN (SYSDATE - " << daysPriorFilter
                     << ") AND (SYSDATE + " << daysFutureFilter << ") ";
    }
        
    string query = queryBuilder.str();
    
    // prepare statement
    Statement *stmt = controllerDB->getConnection()->createStatement(query);
    stmt->setInt(1, userID);
    stmt->setInt(2, userID);

    // SELECT * FROM ( SELECT taskID, type, name, description, TO_CHAR(dueDate, 'MM/DD/YYYY'), dueDate, weight, isComplete, courseID, studentID, instructorID FROM Tasks WHERE courseID IN ( SELECT courseID FROM StudentCourses WHERE studentID = 101 ) 
    // OR studentID = 101) WHERE dueDate BETWEEN (SYSDATE - 1) AND (SYSDATE + 7)


    // get results
    ResultSet *rs = stmt->executeQuery();
    
    list<Task> filteredTasks;
    while(rs->next()) {
        Task task(-1, "", -1, -1, "", "", false, -1.0);
        task.setTaskId(rs->getInt(1));
        task.setTaskType(rs->getInt(2));
        task.setTaskName(rs->getString(3));
        task.setTaskDescription(rs->getString(4));
        task.setDueDate(rs->getString(5));
        task.setWeight(rs->getFloat(7));
        task.setCompletionStatus(rs->getInt(8) != 0);

        int courseID = rs->getInt(9);
        int studentID = rs->getInt(10);
        int instructorID = rs->getInt(11);

        if (courseID != 0) {
            task.setTaskOwner(courseID);
        } else if (studentID != 0) {
            task.setTaskOwner(studentID);
        } else if (instructorID != 0) {
            task.setTaskOwner(instructorID);
        }
        filteredTasks.push_back(task);
    }
    controllerDB->disconnect();
    return filteredTasks;
}

// update the taskID from being an instructor to a courseId
bool TaskDB::updateTaskOwner(Task task) {
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "UPDATE Tasks "
                << "SET "
                << "type = :1, "
                << "instructorId = NULL,"
                << "courseID = :2 "
                << "WHERE taskID = :3 ";

    string query = queryBuilder.str();
    Statement* stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setInt(1, task.getTaskType());
    stmt->setInt(2, task.getTaskOwner());
    stmt->setInt(3, task.getTaskId());

    int rowCount = stmt->executeUpdate(); // returns rows affected (should be 1)
    cout << rowCount << endl;
    // Commit the transaction or changes will revert after connection is closed
    controllerDB->getConnection()->commit();

    controllerDB->disconnect();

    return rowCount;

}