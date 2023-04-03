#include "subscriptionController.hpp"
#include "filterTaskController.hpp"
#include "userController.hpp"
#include "taskDb.hpp"
#include "course.hpp"
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


// int typeFilter, int courseFilter, int completedFilter, int daysPriorFilter, int daysFutureFilter
list<Task> FilterTaskController::viewAllUserTasks() {
    int userId = userController->getCurrentUser();
    return taskDb->getFilteredTasks(-1, -1, -1, -1, -1, userId);
}

list<Task> FilterTaskController::filterTasksByCourse(int courseId) {
    // get course ID
    int userId = userController->getCurrentUser();
    return taskDb->getFilteredTasks(-1, courseId, -1, -1, -1, userId);
}

list<Task> FilterTaskController::filterTasksByType(int type) {
    int userId = userController->getCurrentUser();
    return taskDb->getFilteredTasks(type, -1, -1, -1, -1, userId);
}

list<Task> FilterTaskController::filterTasksDate(int daysFuture) {
    int userId = userController->getCurrentUser();
    return taskDb->getFilteredTasks(-1, -1, -1, 1, daysFuture, userId);
}

list<Task> FilterTaskController::filterTasksByDone(int done) {
    int userId = userController->getCurrentUser();
    return taskDb->getFilteredTasks(-1, -1, done, -1, -1, userId);
}