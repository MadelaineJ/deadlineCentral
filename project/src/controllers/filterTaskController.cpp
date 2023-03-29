#include "filterTaskController.hpp"
#include "taskDb.hpp"
#include <iostream>

FilterTaskController *FilterTaskController::instance = nullptr; // initialize the static pointer

// returns a pointer to the single instance of FilterTaskController, if there is no instance it creates a new one
FilterTaskController* FilterTaskController::getInstance() {
    if(instance == nullptr) {
        instance = new FilterTaskController();
    }
    return instance;
}

// constructor is private to avoid multiple instances of FilterTaskController, instead use static method getInstance 
FilterTaskController::FilterTaskController() {}

// destructor
FilterTaskController::~FilterTaskController() {}

list<Task> FilterTaskController::filterTasks() {
    return taskDb->getFilteredTasks(-1, -1, -1, -1, -1, 101);
}