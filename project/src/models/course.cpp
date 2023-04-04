// Required Libraries
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <list>

// Custom header files
#include "course.hpp"

using namespace std;

// constructor
Course::Course(int courseId, int instructorId, string courseName, string courseCode, string calendarDescription)
{
    this->courseId = courseId;
    this->instructorId = instructorId;
    this->courseName = courseName;
    this->courseCode = courseCode;
    this->calendarDescription = calendarDescription;

}

// destructor
Course::~Course() { }

// getCourseId
int Course::getCourseId() {
    return this->courseId;
}

// setCourseId
void Course::setCourseId(int courseId) {
    this->courseId = courseId;
}

// getInstructorId
int Course::getInstructorId() {
    return this->instructorId;
}

// setInstructorId
void Course::setInstructorId(int instructorId) {
    this->instructorId = instructorId;
}

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

std::ostream& operator<< (std::ostream& out, const Course& c) {
    out << "Course: " << c.courseId << " " << c.courseCode << " " << c.courseName << " " \
        << c.instructorId << "(instructorID) " << "some desc..."; // c.calendarDescription;
    return out;
}
