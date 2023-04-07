// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


// Custom header files
#include "courseController.hpp"
#include "aggregateDeadline.hpp"
#include "subscriptionController.hpp"
#include "taskDb.hpp"
#include "taskController.hpp"

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
bool CourseController::createCourse(string name, string description, string code, int ownerId) {

    Course newCourse(-1, ownerId, name, code, description);
    return courseDb->createCourse(newCourse); 
}

// editCourse
bool CourseController::editCourse(int courseId, int instructorId, string courseName, string courseCode, string calendarDescription) {

    Course updatedCourse(courseId, instructorId, courseName, courseCode, calendarDescription);

    return courseDb->updateCourse(updatedCourse);
}

// deleteCourse
bool CourseController::deleteCourse(int courseId, int userId) {
    Course delCourse;
    bool deleted = false;

    list<int> students = courseDb->getEnrollmentList(courseId);

    // removed all student subscription
    for (int studentId: students) {
        this->subscriptionController->removeSubscription(courseId, studentId);
    }
    // TODO: we should not have to pass a userID to filter tasks by course

    // Delete all tasks associated with the course
    // TODO: decide if this should associate the tasks with the instructor as personal instead of deleting themclearclera
    list<Task> taskList = taskDb->getFilteredTasks(-1, courseId, -1, -1, -1, userId);
    for (Task task : taskList) {
        this->taskController->deleteTask(task.getTaskId());
    }

    delCourse = courseDb->getCourseInfo(courseId);
    deleted = courseDb->deleteCourse(delCourse);

    return deleted;
}

// getCourseInfo
Course CourseController::getCourseInfo(int courseId) {
    return courseDb->getCourseInfo(courseId);
}

// addTask
bool CourseController::addTask(Task task) {
    return taskDb->updateTaskOwner(task);
    
}

// aggregateDeadlines
list<AggregateDeadline> CourseController::aggregateDeadlines(int courseId, string date) {

    return courseDb->aggregateDeadlines(courseId, date);
}

vector<Course> CourseController::getInstructorCourses(int instructorId) {
    list<int> courseIdList = courseDb->getInstructorCourses(instructorId);
    vector<Course> courseList;
    for (int id: courseIdList) {
        courseList.push_back(this->getCourseInfo(id));
    }

    return courseList;
}