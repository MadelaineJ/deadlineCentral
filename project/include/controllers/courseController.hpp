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
        static CourseController* getInstance(); // gets the single instance of this class
        ~CourseController();
        
        void createCourse();

        void editCourse();

        void deleteCourse();

        void getCourseInfo();

        void addTask();

        void removeTask();

        void aggregateDeadlines();
        
    private:    
        CourseController(); // private to prevent direct instantiation
        static CourseController* instance; // Pointer to the single instance of CourseController
};

#endif
