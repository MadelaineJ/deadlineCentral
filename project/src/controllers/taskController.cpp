// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

// Custom header files
#include "taskController.hpp"
#include "taskDb.hpp"
#include "task.hpp"

using namespace std;

TaskController *TaskController::instance = nullptr; // initialize the static pointer

// returns a pointer to the single instance of TaskController, if there is no instance it creates a new one
TaskController* TaskController::getInstance() {
    if(instance == nullptr) {
        instance = new TaskController();
    }
    return instance;
}

// constructor is private to avoid multiple instances of TaskController, instead use static method getInstance 
TaskController::TaskController(){}

// destructor
TaskController::~TaskController() { }

// createTask
bool TaskController::createUserTask(int userId, string name, string description, string dueDate, float weight) {
    Task task(-1, name, 10, userId, description, dueDate, false, weight);
    return this->taskDb->createTask(task);
} 

// createTask
bool TaskController::createCourseTask(string name, int type, int course, string description, string dueDate, float weight) {
    Task task(-1, name, type, course, description, dueDate, false, weight);
    return this->taskDb->createTask(task);
}

// editTask
bool TaskController::updateTask(int ownerId, int taskId, string name, string description, string dueDate, float weight, int type) {
    
    Task task(taskId, name, type, ownerId, description, dueDate, false, weight);
    return taskDb->updateTask(task);
}

bool TaskController::deleteTask(int taskId) {
    
    Task task = getTaskInfo(taskId);
    return taskDb->deleteTask(task);
}

// getTaskInfo
Task TaskController::getTaskInfo(int id) {
    return this->taskDb->getTaskInfo(id);
}
