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
        list<Student> getEnrollmentList(int courseID);
        Course getCourseInfo(int courseID);
        //TODO return type tbd
        void aggregateDeadlines(int courseID);
    private:
};

#endif 
