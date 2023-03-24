#ifndef TASK_DB_H
#define TASK_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>

// custom header files
#include "task.hpp"
#include "controllerDb.hpp"

using namespace std;
using namespace oracle::occi;

class TaskDB 
{
    public:
        TaskDB();
        ~TaskDB();
        bool createTask(Task task);
        bool updateTask(Task T);
        bool deleteTask(Task T);
        Task getTaskInfo(string taskID);
    private:
        ControllerDb controllerDb;
};

#endif 
