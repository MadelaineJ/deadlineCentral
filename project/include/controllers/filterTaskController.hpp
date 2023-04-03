#ifndef FILTERTASKCONTROLLER_H
#define FILTERTASKCONTROLLER_H

// Required Libraries
#include <list>

// Custom header files
#include "task.hpp"
#include "taskDb.hpp"
#include "userController.hpp"
#include "subscriptionController.hpp"

using namespace std;

class FilterTaskController 
{
    public:
        static FilterTaskController* getInstance(); // gets the single instance of this class
        ~FilterTaskController();

        // TODO: add params ; return type?
        list<Task> viewAllUserTasks();
        list<Task> filterTasksByCourse(int courseId);
        list<Task> filterTasksByType(int type);
        list<Task> filterTasksDate(int daysFuture);
        list<Task> filterTasksByDone(int done);

    private:
        FilterTaskController(); // private to prevent direct instantiation
        static FilterTaskController* instance; // Pointer to the single instance of FilterTaskController

        list<Task> taskList;
        TaskDB *taskDb = TaskDB::getInstance();
        UserController *userController = UserController::getInstance();
        SubscriptionController *subscriptionController = SubscriptionController::getInstance();

};

#endif // FILTERTASKCONTROLLER_H