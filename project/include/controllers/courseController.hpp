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
#include "subscriptionController.hpp"
#include "taskController.hpp"
using namespace std;


class CourseController 
{
    public:
        static CourseController* getInstance(); // gets the single instance of this class
        ~CourseController();
        
        bool createCourse(string name, string description, string code, int ownerId);

        bool editCourse(int cId, int instId, string Name, string Code, string Description);

        bool deleteCourse(int courseId, int userId);

        Course getCourseInfo(int cId);

        bool addTask(Task task);

        bool removeTask(int tId, int cId);

        list<AggregateDeadline> aggregateDeadlines(int courseId, string date);

        vector<Course> getInstructorCourses(int instructorId);
        
    private:    
        CourseController(); // private to prevent direct instantiation
        static CourseController* instance; // Pointer to the single instance of CourseController

        CourseDB *courseDb = CourseDB::getInstance();
        TaskDB *taskDb = TaskDB::getInstance();
        SubscriptionController *subscriptionController = SubscriptionController::getInstance();
        TaskController *taskController = TaskController::getInstance();
};

#endif
