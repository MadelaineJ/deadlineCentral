#ifndef TASKCONTROLLER_H
#define TASKCONTROLLER_H
#pragma once

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


// custom header files
#include "taskDb.hpp"


using namespace std;

class TaskController 
{
    public:
        static TaskController* getInstance(); // gets the single instance of this class
        ~TaskController();
        
        bool createUserTask(int userId, string name, string description, string dueDate, float weight);
        bool createCourseTask(string name, int type, int course, string description, string dueDate, float weight);
        bool updateTask(int ownerId, int taskId, string name, string description, string dueDate, float weight, int type);
        bool deleteTask(int courseId);
        Task getTaskInfo(int id);

        void getAllTasks();

    private:
        TaskController(); // private to prevent direct instantiation
        static TaskController* instance; // Pointer to the single instance of TaskController
        TaskDB *taskDb = TaskDB::getInstance();
};

#endif