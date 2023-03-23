#ifndef COURSECONTROLLER_H
#define COURSECONTROLLER_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;


class CourseController 
{
    public:
        CourseController();
        ~CourseController();
        
        void createCourse();

        void editCourse();

        void deleteCourse();

        void getCourseInfo();

        void addTask();

        void removeTask();

        void aggregateDeadlines();
};

#endif
