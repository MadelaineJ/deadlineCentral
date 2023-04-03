#ifndef FILTERTASKCONTROLLER_H
#define FILTERTASKCONTROLLER_H

// Required Libraries
#include <list>

// Custom header files
#include "task.hpp"
#include "taskDb.hpp"
#include "userController.hpp"
#include "subscriptionController.hpp"
#include "courseController.hpp"

using namespace std;

class FilterTaskController 
{
    public:
        static FilterTaskController* getInstance(); // gets the single instance of this class
        ~FilterTaskController();

        // task filters
       void findAllUserTasks();
       void filterTasksByCourse(int courseId);
       void filterTasksByType(int type);
       void filterTasksByDate(int daysFuture);
       void filterTasksByDone(int done);

        // sort tasks
       void sortTasksByName();
       void sortTasksByOwner();
       void sortTasksByType();
       void sortTasksByDate();
       void sortTasksByWeight();


        // Printing the task list
        void printTaskList();
        string getCourseOwnerName(int owner, int type);
        

    private:
        FilterTaskController(); // private to prevent direct instantiation
        static FilterTaskController* instance; // Pointer to the single instance of FilterTaskController

        list<Task> taskList; //
        TaskDB *taskDb = TaskDB::getInstance();
        UserController *userController = UserController::getInstance();
        SubscriptionController *subscriptionController = SubscriptionController::getInstance();
        CourseController *courseController = CourseController::getInstance();

        // sort toggle variables
        bool sortName = true;
        bool sortOwner = true;
        bool sortType = true;
        bool sortDate = true;
        bool sortWeight = true;

        void toggleSortName();
        void toggleSortOwner();
        void toggleSortType();
        void toggleSortDate();
        void toggleSortWeight();

        bool getSortName();
        bool getSortOwner();
        bool getSortType();
        bool getSortDate();
        bool getSortWeight();

        // sort helper comparison functions
        bool compareTaskByName(Task task1, Task task2);
        bool compareTaskByOwner(Task task1, Task task2);
        bool compareTaskByType(Task task1, Task task2);
        bool compareTaskByDate(Task task1, Task task2);
        bool compareTaskByWeight(Task task1, Task task2);


};


#endif // FILTERTASKCONTROLLER_H