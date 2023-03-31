#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

// Required Libraries
#include <iostream>
#include <string>

// custom header files
#include "userController.hpp"


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
        void loginMenu();

        // menu input handlers
        void manageMain();
        void manageAccount();
        void manageTask();
        void manageCourse();
        void manageLogin();

        //handle commands
        // void handleCreateCourse();
        // void handleCreateTask();
        // void handleEditTask();
        // void handleEditCourse();
        // void handleLogin();
        // void handleSubscribeCourse();
        // void handleUnsubscribeCourse();
        // void handleViewTask();
        // void handleViewCourse();
        // void handleSortTasks();
        // void handleViewConsolidatedDeadlines();
        // void handleDeleteCourse();
        // void handleDeleteTask();

    private:
        UserController *userController = UserController::getInstance();

};

#endif
