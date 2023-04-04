// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


// Custom header files
#include "taskController.hpp"
#include "userController.hpp"
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
void TaskController::createUserTask(string name, string description, string dueDate, float weight) {
    Task task(-1, name, 10, this->userController->getCurrentUser(), description, dueDate, false, weight);
    this->taskDb->createTask(task);
}
// addTask
void TaskController::addTask() {
}

// editTask
void TaskController::editTask() {

}

// getTaskInfo
Task TaskController::getTaskInfo(int id) {
    return this->taskDb->getTaskInfo(id);
}
