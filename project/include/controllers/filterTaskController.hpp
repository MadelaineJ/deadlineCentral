#ifndef FILTERTASKCONTROLLER_H
#define FILTERTASKCONTROLLER_H

// Required Libraries
#include <list>
#include "task.hpp"

using namespace std;

class FilterTaskController 
{
    public:
        static FilterTaskController* getInstance(); // gets the single instance of this class
        ~FilterTaskController();

        // TODO: add params ; return type?
        Task* filterTasks();

    private:
        FilterTaskController(); // private to prevent direct instantiation
        static FilterTaskController* instance; // Pointer to the single instance of FilterTaskController

        list<Task> taskList;

};

#endif // FILTERTASKCONTROLLER_H