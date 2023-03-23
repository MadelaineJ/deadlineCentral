#ifndef TASKCONTROLLER_H
#define TASKCONTROLLER_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>




using namespace std;


class TaskController 
{
    public:
        TaskController();
        ~TaskController();
        
        void createTask();

        void addTask();

        void editTask();

        void getTaskInfo();


};

#endif