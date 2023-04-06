#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#pragma once

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include "userDb.hpp"


#include "taskController.hpp"
#include "subscriptionController.hpp"


// forward declaration
class TaskController;

using namespace std;

class UserController 
{
    public:
        static UserController* getInstance(); // gets the single instance of this class
        ~UserController();

        string generate_hash(const std::string& password);
        
        void createStudent(string name, string email, string passwordOriginal);

        void createInstructor(string name, string email, string passwordOriginal);

        void deleteUser(int userId);

        User getUserInfo(int userId, string email);

        void updateUser(string name, string email);

        bool validateCredentials(string email, string password);

        int getCurrentUser();
        void setCurrentUser(int userId);
    
    private:
        UserController(); // private to prevent direct instantiation
        static UserController* instance; // Pointer to the single instance of UserController
        int currentUser; // the currently logged in user
        UserDB* userDb = UserDB::getInstance();
        TaskController *taskController;
        SubscriptionController *subscriptionController;
};

#endif
