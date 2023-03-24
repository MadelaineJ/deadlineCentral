#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

// Required Libraries
#include <iostream>
#include <string>

// custom header files

#include "userController.hpp"
#include "taskController.hpp"
#include "filterTaskController.hpp"
#include "subscriptionController.hpp"
#include "courseController.hpp"


using namespace std;


class CommandHandler 
{
    public:
        CommandHandler(){}
        ~CommandHandler(){}
        
        int getUserInput();

        // printed menus
        void mainMenu();
        void accountMenu();
        void taskMenu();
        void courseMenu();
        void handleHelp();

        // menu input handlers
        void manageMain();
        void manageAccount();
        void manageTask();
        void manageCourse();

        //handle commands
        void handleCreateCourse();
        void handleCreateTask();
        void handleEditTask();
        void handleEditCourse();
        void handleLogin();
        void handleSubscribeCourse();
        void handleUnsubscribeCourse();
        void handleViewTask();
        void handleViewCourse();
        void handleSortTasks();
        void handleViewConsolidatedDeadlines();
        void handleDeleteCourse();
        void handleDeleteTask();

    private:
        UserController *userController = UserController::getInstance();
        TaskController *taskController = TaskController::getInstance();
        FilterTaskController *filterTaskController = FilterTaskController::getInstance();
        SubscriptionController *subscriptionController = SubscriptionController::getInstance();
        CourseController *courseController = CourseController::getInstance();

};

#endif
