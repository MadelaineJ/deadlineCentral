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

// TODO: prepare query
bool TaskDB::createTask(Task task){
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    string query = "INSERT INTO Tasks (type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES ("
        + to_string(task.getTaskType()) + ", '"
        + task.getTaskName() + "', '"
        + task.getTaskDescription() + "', TO_DATE('"
        + task.getDueDate() + "', 'YYYY-MM-DD HH24:MI:SS'), "
        + to_string(task.getWeight()) + ", "
        + to_string(task.getCompletionStatus()) + ", NULL, "
        + to_string(task.getTaskOwner()) + ", NULL)";

    int rowCount = controllerDB->getStatement()->executeUpdate(query);
    controllerDB->disconnect();
    return rowCount;
}

bool TaskDB::updateTask(Task T){
   return 0;
}

bool TaskDB::deleteTask(Task T){
   return 0;
}
// TODO: prepare query???
Task TaskDB::getTaskInfo(string taskId) {
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();
    string query = "SELECT taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID FROM Tasks WHERE taskID = " + taskId;
    ResultSet *rs = controllerDB->getStatement()->executeQuery(query);
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
                << "SELECT taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID "
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
        filteredTasks.push_back(task);
    }
    controllerDB->disconnect();
    return filteredTasks;
}

