#ifndef COURSE_DB_H
#define COURSE_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include <list>

#include "course.hpp"
#include "student.hpp"

using namespace std;
using namespace oracle::occi;

class CourseDB 
{
    public:
        static CourseDB* getInstance(); // gets the single instance of this class
        ~CourseDB();
        bool createCourse(Course C);
        bool updateCourse(Course C);
        bool deleteCourse(Course C);
        list<Student> getEnrollmentList(int courseID);
        Course getCourseInfo(int courseID);
        //TODO return type tbd
        void aggregateDeadlines(int courseID);
    private:
        CourseDB(); // private to avoid direct instantiation
        static CourseDB* instance; // pointer to single instanece of CourseDB
};

#endif 
