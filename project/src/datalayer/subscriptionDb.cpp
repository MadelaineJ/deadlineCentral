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

// returns a list of all courses not currently subscribed to by the student
list<Course> SubscriptionDB::getAvailableCourseList(int studentId) {
    // query DB table Courses to return list of all courses
    ControllerDb *controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "SELECT * FROM "
                 << "Courses "
                 << "WHERE courseID NOT IN ( "
                 << "SELECT courseID "
                 << "FROM StudentCourses "
                 << "WHERE studentID = :1)";

    string query = queryBuilder.str();
    Statement *stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setInt(1, studentId);

    ResultSet *rs = stmt->executeQuery();

    list<Course> availableCourses = {};
    while(rs->next()){
        Course course(-1, -1, "", "", "");
        course.setCourseId(rs->getInt(1));
        course.setCourseCode(rs->getString(2));
        course.setCourseName(rs->getString(3));
        course.setCalendarDescription(rs->getString(4));
        course.setInstructorId(rs->getInt(5));

        availableCourses.push_back(course);
    }
    return availableCourses;
}

// returns a list of courses that the student is currently subscribed to 
list<Course> SubscriptionDB::getCourseSubscriptions(int studentId) {
    // query DB table StudentCourses using studentID to get all courses subscribed to
    ControllerDb *controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "SELECT * FROM "
                 << "Courses "
                 << "WHERE courseID IN ( "
                 << "SELECT courseID "
                 << "FROM StudentCourses "
                 << "WHERE studentID = :1)";

    string query = queryBuilder.str();
    Statement *stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setInt(1, studentId);

    ResultSet *rs = stmt->executeQuery();

    list<Course> subscriptionCourses = {};
    while(rs->next()){
        Course course(-1, -1, "", "", "");
        course.setCourseId(rs->getInt(1));
        course.setCourseCode(rs->getString(2));
        course.setCourseName(rs->getString(3));
        course.setCalendarDescription(rs->getString(4));
        course.setInstructorId(rs->getInt(5));

        subscriptionCourses.push_back(course);
    }
    return subscriptionCourses;
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