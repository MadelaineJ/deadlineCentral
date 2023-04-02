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
int CourseController::createCourse(string name, string description, string code) {
    CourseDB* courseDB = CourseDB::getInstance();
    UserController* userController = UserController::getInstance();

    Course newCourse(-1, userController->getCurrentUser(), name, code, description);
    return courseDB->createCourse(newCourse); 
}

// editCourse
void CourseController::editCourse() {
    
}

// deleteCourse
void CourseController::deleteCourse() {

}

// getCourseInfo
Course CourseController::getCourseInfo(int courseId) {
    CourseDB* courseDB = CourseDB::getInstance();
    return courseDB->getCourseInfo(courseId);
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

