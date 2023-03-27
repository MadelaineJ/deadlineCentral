// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


// Custom header files
#include "taskController.hpp"

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
void TaskController::createTask() {
	
}

// addTask
void TaskController::addTask() {
    
}

// editTask
void TaskController::editTask() {

}

// getTaskInfo
void TaskController::getTaskInfo() {

}

