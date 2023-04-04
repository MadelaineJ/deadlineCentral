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
        void userTypeMenu();
        void addTaskMenu();
        void viewAllTasksMenu();
        void filterTasksMenu();
        void sortTasksMenu();
        void chooseTaskTypeMenu();
        

        // menu input handlers
        void manageMain();
        void manageAccount();
        void manageCreateAccount();
        void manageTask();
        void manageCourse();
        void manageLogin();
        void manageAllTasks();
        void manageFilterTasks();
        void manageSortTasks();
        int manageChooseTaskType();

        //handle commands
        //void handleCreateCourse();
        //void handleCreateTask();
        // void handleEditTask();
        void addTask();
        //void handleEditCourse();
        // void handleLogin();
        // void handleSubscribeCourse();
        // void handleUnsubscribeCourse();
        // void handleViewTask();
        //void handleViewCourse();
        // void handleSortTasks();
        // void handleViewConsolidatedDeadlines();
        //void handleDeleteCourse();
        // void handleDeleteTask();

    private:
        UserController *userController = UserController::getInstance();

};

#endif
