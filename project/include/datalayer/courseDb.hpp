#ifndef COURSE_DB_H
#define COURSE_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include "course.hpp"
#include "student.hpp"

using namespace std;
using namespace oracle::occi;

class CourseDB 
{
    public:
        CourseDB(){}
        ~CourseDB(){}
        bool createCourse(Course C);
        bool updateCourse(Course C);
        bool deleteCourse(Course C);
        //TODO change return type to list<Student> when implemented
        void getEnrollmentList(int courseID);
        //TODO change return type to Course when implemented
        void getCourseInfo(int courseID);
        //return type tbd
        void aggregateDeadlines(int courseID);
    private:
};

#endif 
