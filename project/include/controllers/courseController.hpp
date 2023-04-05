#ifndef COURSECONTROLLER_H
#define COURSECONTROLLER_H

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

        void editCourse(int cId, int instId, string Name, string Code, string Description);

        void deleteCourse(int cId);

        Course getCourseInfo(int cId);

        void addTask(int tId, int cId);

        void removeTask(int tId, int cId);

        void aggregateDeadlines(int cId);
        
    private:    
        CourseController(); // private to prevent direct instantiation
        static CourseController* instance; // Pointer to the single instance of CourseController

        CourseDB *courseDb = CourseDB::getInstance();
        TaskDB *taskDb = TaskDB::getInstance();
};

#endif
