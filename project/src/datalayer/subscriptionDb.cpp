#include "subscriptionDb.hpp"
#include "controllerDb.hpp"


#include <iostream>
#include <string>

SubscriptionDB *SubscriptionDB::instance = nullptr; // initialize the static pointer

// returns a pointer to the single instance of SubscriptionDB, if there is no instance it creates a new one
SubscriptionDB* SubscriptionDB::getInstance() {
    if(instance == nullptr) {
        instance = new SubscriptionDB();
    }
    return instance;
}

// constructor is private to avoid multiple instances of SubscriptionDB, instead use static method getInstance 
SubscriptionDB::SubscriptionDB(){}

SubscriptionDB::~SubscriptionDB(){

}

Course* SubscriptionDB::getAvailableCourseList(int courseID) {
    // query DB table Courses to return list of all courses
    return NULL;
}

Course* SubscriptionDB::getCourseSubscriptions(int studentID) {
    // query DB table StudentCourses using studentID to get all courses subscribed to
    return NULL;
}

bool SubscriptionDB::deleteSubscription(int studentID, int courseID) {
    // query DB table StudentCourses to remove subscription
    return false;
}

bool SubscriptionDB::createSubscription(int studentID, int courseID) {
    // query DB table StudentCourses to create subscription

    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    string query = "INSERT INTO studentcourses (studentID, courseID) VALUES ("
        + to_string(studentID) + ", "
        + to_string(courseID) + "')";

    int rowCount = controllerDB->getStatement()->executeUpdate(query);
    controllerDB->disconnect();
    return rowCount;
}

// helper functions
int SubscriptionDB::getCourseID(std::string courseCode, std::string instructorName) {
    // query DB table Courses using courseCode & instructor name to find courseID
    return false;
}