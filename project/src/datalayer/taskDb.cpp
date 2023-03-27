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

    string query = "INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES ("
        + to_string(task.getTaskId()) + ", "
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
list<Task> getFilteredTasks(string filters) {

}

