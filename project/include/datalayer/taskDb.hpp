#ifndef TASK_DB_H
#define TASK_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include "task.hpp"

using namespace std;
using namespace oracle::occi;

class TaskDB 
{
    public:
        TaskDB(){}
        ~TaskDB(){}
        bool createCourse(Task T);
        bool updateCourse(Task T);
        bool deleteCourse(Task T);
        Task getTaskInfo(int taskID);
    private:
};

#endif 
