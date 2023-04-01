#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

#include "userDb.hpp"
using namespace std;


class UserController 
{
    public:
        static UserController* getInstance(); // gets the single instance of this class
        ~UserController();
        
        void createStudent(string name, string email, string passwordOriginal);

        void createInstructor(string name, string email, string passwordOriginal);

        void deleteUser();

        User getUserInfo(int userId, string email);

        bool validateCredentials(string email, string password);

        int getCurrentUser();
        void setCurrentUser(int userId);
    
    private:
        UserController(); // private to prevent direct instantiation
        static UserController* instance; // Pointer to the single instance of UserController
        int currentUser; // the currently logged in user
        UserDB* userDb = UserDB::getInstance();
};

#endif
