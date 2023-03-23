#ifndef TASK_DB_H
#define TASK_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include "../models/task.hpp"

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
        //TODO change return type to Task when implemented
        void getTaskInfo(int taskID);
    private:
};

#endif 
