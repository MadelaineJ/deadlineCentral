#include "subscriptionDb.hpp"


SubscriptionDB::SubscriptionDB(){

}

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
    return false;
}

// helper functions
int SubscriptionDB::getCourseID(std::string courseCode, std::string instructorName) {
    // query DB table Courses using courseCode & instructor name to find courseID
    return false;
}