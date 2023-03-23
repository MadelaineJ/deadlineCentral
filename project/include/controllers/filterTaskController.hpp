#ifndef FILTERTASKCONTROLLER_H
#define FILTERTASKCONTROLLER_H

// Required Libraries
#include <list>
#include "task.hpp"

using namespace std;

class FilterTaskController 
{
    public:
        FilterTaskController();
        ~FilterTaskController();

        // TODO: add params ; return type?
        Task* filterTasks();

    private:
        list<Task> taskList;

};

#endif // FILTERTASKCONTROLLER_H