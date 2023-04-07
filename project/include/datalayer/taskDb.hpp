#ifndef TASK_DB_H
#define TASK_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include <list>
#include <sstream> // for string building the SQL query

// custom header files
#include "task.hpp"
#include "controllerDb.hpp"

using namespace std;
using namespace oracle::occi;

class TaskDB 
{
    public:
        static TaskDB* getInstance(); // gets the single instance of this class
        ~TaskDB();
        bool createTask(Task task);
        bool updateTask(Task T);
        bool updateTaskOwner(Task T);
        bool deleteTask(Task T);
        Task getTaskInfo(int taskID);
        list<Task> getFilteredTasks(int typeFilter, int courseFilter, int completedFilter, int daysPriorFilter, int daysFutureFilter, int userID);
    private:
        TaskDB(); // private to prevent direct instantiation
        static TaskDB* instance; // Pointer to the single instance of TaskDB
};

#endif 
