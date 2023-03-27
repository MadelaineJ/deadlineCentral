// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


// Custom header files
#include "courseController.hpp"

using namespace std;

CourseController *CourseController::instance = nullptr; // initialize the static pointer

// returns a pointer to the single instance of CourseController, if there is no instance it creates a new one
CourseController* CourseController::getInstance() {
    if(instance == nullptr) {
        instance = new CourseController();
    }
    return instance;
}

// constructor
CourseController::CourseController() {}

// destructor
CourseController::~CourseController() { }

// createCourse
void CourseController::createCourse() {
	
}

// editCourse
void CourseController::editCourse() {
    
}

// deleteCourse
void CourseController::deleteCourse() {

}

// getCourseInfo
void CourseController::getCourseInfo() {

}

// addTask
void CourseController::addTask() {

}

// removeTask
void CourseController::removeTask() {

}

// aggregateDeadlines
void CourseController::aggregateDeadlines() {

}

