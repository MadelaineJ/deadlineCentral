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
        static TaskController* getInstance(); // gets the single instance of this class
        ~TaskController();
        
        void createTask();

        void addTask();

        void editTask();

        void getTaskInfo();

    private:
        TaskController(); // private to prevent direct instantiation
        static TaskController* instance; // Pointer to the single instance of SubscriptionDB
};

#endif