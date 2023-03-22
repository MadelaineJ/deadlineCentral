// Required Libraries
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <list>

// Custom header files
#include "course.hpp"

using namespace std;

// constructor
Course::Course(string courseName, string courseCode, string calendarDescription, list<int> enrollmentList)
{
    this->courseName = courseName;
    this->courseCode = courseCode;
    this->calendarDescription = calendarDescription;
    this->enrollmentList = enrollmentList;

}

// destructor
Course::~Course() { }

// getCourseName
string Course::getCourseName() {
    return this->courseName;
}

// setCourseName
void Course::setCourseName(string courseName) {
    this->courseName = courseName;
}

// getCourseCode
string Course::getCourseCode() {
    return this->courseCode;
}

// setCourseCode
void Course::setCourseCode(string courseCode) {
    this->courseCode = courseCode;
}

// getCalendarDescription
string Course::getCalendarDescription() {
    return this->calendarDescription;
}

// setCalendarDescription
void Course::setCalendarDescription(string calendarDescription) {
    this->calendarDescription = calendarDescription;
}

// getEnrollmentList
list<int> Course::getEnrollmentList() {
    return this->enrollmentList;
}

// setEnrollmentList
void Course::setEnrollmentList(list<int> enrollmentList) {
    this->enrollmentList = enrollmentList;
}
