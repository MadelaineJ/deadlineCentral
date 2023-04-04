#ifndef TASKCONTROLLER_H
#define TASKCONTROLLER_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


// custom header files
#include "taskDb.hpp"
#include "userController.hpp"


using namespace std;


class TaskController 
{
    public:
        static TaskController* getInstance(); // gets the single instance of this class
        ~TaskController();
        
        void createUserTask(string name, string description, string dueDate, float weight);

        void addTask();

        void editTask();

        Task getTaskInfo(int id);
        void getAllTasks();

    private:
        TaskController(); // private to prevent direct instantiation
        static TaskController* instance; // Pointer to the single instance of TaskController
        TaskDB *taskDb = TaskDB::getInstance();
        UserController *userController = UserController::getInstance();
};

#endif