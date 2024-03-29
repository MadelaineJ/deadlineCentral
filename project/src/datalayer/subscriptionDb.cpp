// custom header files
#include "subscriptionDb.hpp"
#include "controllerDb.hpp"

// required libraries
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
SubscriptionDB::SubscriptionDB() {}

SubscriptionDB::~SubscriptionDB() {}

// returns a list of all courses not currently subscribed to by the student
vector<Course> SubscriptionDB::getAvailableCourseList(int studentId) {
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

    vector<Course> availableCourses = {};
    while(rs->next()){
        Course course(-1, -1, "", "", "");
        course.setCourseId(rs->getInt(1));
        course.setCourseCode(rs->getString(2));
        course.setCourseName(rs->getString(3));
        course.setCalendarDescription(rs->getString(4));
        course.setInstructorId(rs->getInt(5));

        availableCourses.push_back(course);
    }
    controllerDB->disconnect();
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
    controllerDB->disconnect();
    return subscriptionCourses;
}

bool SubscriptionDB::deleteSubscription(int studentID, int courseID) {
    // query DB table StudentCourses to remove subscription
    ControllerDb *controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "DELETE FROM StudentCourses "
                 << "WHERE studentID = :studentID "
                 << "AND courseID = :courseID ";
    
    string query = queryBuilder.str();
    Statement *stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setInt(1, studentID);
    stmt->setInt(2, courseID);

    int rowCount = stmt->executeUpdate();

    // Commit the transaction or changes will revert after connection is closed
    controllerDB->getConnection()->commit();

    controllerDB->disconnect();

    if(rowCount == 1){
        return true;
    }
    return false;
}

bool SubscriptionDB::createSubscription(int studentID, int courseID) {
    // query DB table StudentCourses to create subscription
    ControllerDb* controllerDB = ControllerDb::getInstance();
    controllerDB->connect();

    stringstream queryBuilder;
    queryBuilder << "INSERT INTO StudentCourses(studentID, courseID) "
                 << "VALUES (:1, :2)";
    
    string query = queryBuilder.str();
    Statement *stmt = controllerDB->getConnection()->createStatement(query);

    stmt->setInt(1, studentID);
    stmt->setInt(2, courseID);

    int rowCount = stmt->executeUpdate();

    // Commit the transaction or changes will revert after connection is closed
    controllerDB->getConnection()->commit();

    controllerDB->disconnect();
    
    if(rowCount == 1){
        return true;
    }
    return false;
}
