#ifndef TASK_DB_H
#define TASK_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include <list>

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
        bool deleteTask(Task T);
        Task getTaskInfo(string taskID);
        list<Task> getFilteredTasks(string filters);
    private:
        ControllerDb controllerDb;
        TaskDB(); // pvt to prevent direct instanciation
        static TaskDB* instance; // Pointer to the single instance of TaskDB
};

#endif 
