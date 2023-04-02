#ifndef COURSECONTROLLER_H
#define COURSECONTROLLER_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include "course.hpp"
#include "courseDb.hpp"
#include "userController.hpp"
using namespace std;


class CourseController 
{
    public:
        static CourseController* getInstance(); // gets the single instance of this class
        ~CourseController();
        
        int createCourse(string name, string description, string code);

        void editCourse();

        void deleteCourse();

        Course getCourseInfo(int courseId);

        void addTask();

        void removeTask();

        void aggregateDeadlines();
        
    private:    
        CourseController(); // private to prevent direct instantiation
        static CourseController* instance; // Pointer to the single instance of CourseController
};

#endif
