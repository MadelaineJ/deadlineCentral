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
int CourseController::createCourse(string name, string description, string code) {
    CourseDB* courseDB = CourseDB::getInstance();
    UserController* userController = UserController::getInstance();

    Course newCourse(-1, userController->getCurrentUser(), name, code, description);
    return courseDb->createCourse(newCourse); 
}

// editCourse
bool CourseController::editCourse(int courseId, int instructorId, string courseName, string courseCode, string calendarDescription) {

    Course updatedCourse(courseId, instructorId, courseName, courseCode, calendarDescription);

    return courseDb->updateCourse(updatedCourse);
}

// deleteCourse
bool CourseController::deleteCourse(int courseId) {
    UserController* userController = UserController::getInstance();
    Course delCourse;
    bool deleted = false;

    list<int> students = courseDb->getEnrollmentList(courseId);

    // removed all student subscription
    for (int studentId: students) {
        cout << "removing subscription for " << studentId << endl;
        if (this->subscriptionController->removeSubscription(courseId, studentId)) {
            cout << "successfully deleted subscription" << endl;
        } else {
            cout << "susbcrpition was not delted" << endl;
        }
    }
    // TODO: we should not have to pass a userID to filter tasks by user

    // Delete all tasks associated with the course
    // TODO: decide if this should associate the tasks with the instructor instead of deleting them
    cout << "removing tasks" << endl;
    list<Task> taskList = taskDb->getFilteredTasks(-1, courseId, -1, -1, -1, userController->getCurrentUser());
    cout << taskList.size() << endl;
    for (Task task : taskList) {
        cout << "removing course task " << task.getTaskName() << endl;
        this->taskController->deleteTask(task.getTaskId());
    }

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
// TODO: this function should be part of subscriptionController
vector<Course> CourseController::getAvailableCourses() {
    CourseDB* courseDB = CourseDB::getInstance();
    list<int> courseIdList = courseDB->getAllCourseIDs();
    vector<Course> courseList;
    for (int id : courseIdList) {
        courseList.push_back(this->getCourseInfo(id));
    }

    return courseList;
}