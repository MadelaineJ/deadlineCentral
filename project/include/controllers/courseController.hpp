#ifndef COURSECONTROLLER_H
#define COURSECONTROLLER_H
#pragma once

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

//custom headers
#include "course.hpp"
#include "courseDb.hpp"
#include "taskDb.hpp"
#include "userController.hpp"
using namespace std;


class CourseController 
{
    public:
        static CourseController* getInstance(); // gets the single instance of this class
        ~CourseController();
        
        int createCourse(string name, string description, string code);

        bool editCourse(int cId, int instId, string Name, string Code, string Description);

        bool deleteCourse(int cId);

        Course getCourseInfo(int cId);

        void addTask(Task task);

        void removeTask(int tId, int cId);

        list<AggregateDeadline> aggregateDeadlines(int courseId, string date);

        vector<Course> getInstructorCourses(int instructorId);
        vector<Course> getAvailableCourses();
        
    private:    
        CourseController(); // private to prevent direct instantiation
        static CourseController* instance; // Pointer to the single instance of CourseController

        CourseDB *courseDb = CourseDB::getInstance();
        TaskDB *taskDb = TaskDB::getInstance();
};

#endif
