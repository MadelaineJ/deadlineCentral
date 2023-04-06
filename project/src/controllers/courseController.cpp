// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


// Custom header files
#include "courseController.hpp"
#include "aggregateDeadline.hpp"

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
    return courseDb->createCourse(newCourse); 
}

// editCourse
bool CourseController::editCourse(int courseId, int instructorId, string courseName, string courseCode, string calendarDescription) {

    Course updatedCourse(courseId, instructorId, courseName, courseCode, calendarDescription);

    //enrollemnet list, to be added 
    /*
    updatedCourse.setCourseId(courseId);
    updatedCourse.setInstructorId(instructorId);
    updatedCourse.setCourseName(courseName);
    updatedCourse.setCourseCode(courseCode);
    updatedCourse.setCalendarDescription(calendarDescription);*/

    return courseDb->updateCourse(updatedCourse);


}

// deleteCourse
bool CourseController::deleteCourse(int courseId) {

    Course delCourse;
    bool deleted = false;

    delCourse = courseDb->getCourseInfo(courseId);
    deleted = courseDb->deleteCourse(delCourse);

    return deleted;

}

// getCourseInfo
Course CourseController::getCourseInfo(int courseId) {
    CourseDB* courseDB = CourseDB::getInstance();
    return courseDB->getCourseInfo(courseId);
}

// addTask
void CourseController::addTask(Task task) {
    taskDb->updateTaskOwner(task);
 
}

// removeTask
void CourseController::removeTask(int taskId, int instId) {

    Task remTask = taskDb->getTaskInfo(taskId);

    remTask.setTaskOwner(instId);
}

// aggregateDeadlines
list<AggregateDeadline> CourseController::aggregateDeadlines(int courseId, string date) {

    return courseDb->aggregateDeadlines(courseId, date);

}

vector<Course> CourseController::getInstructorCourses(int instructorId) {
    CourseDB* courseDB = CourseDB::getInstance();
    list<int> courseIdList = courseDB->getInstructorCourses(instructorId);
    vector<Course> courseList;
    for (int id: courseIdList) {
        courseList.push_back(this->getCourseInfo(id));
    }

    return courseList;
}

// TODO: this should only return courses that the user is not subscribed to
vector<Course> CourseController::getAvailableCourses() {
    CourseDB* courseDB = CourseDB::getInstance();
    list<int> courseIdList = courseDB->getAllCourseIDs();
    vector<Course> courseList;
    for (int id : courseIdList) {
        courseList.push_back(this->getCourseInfo(id));
    }

    return courseList;
}