#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;


class UserController 
{
    public:
        static UserController* getInstance(); // gets the single instance of this class
        ~UserController();
        
        void createStudent();

        void createInstructor();

        void deleteUser();

        void getUserInfo();

        void validateCredentials();

        int getCurrentUser();
        void setCurrentUser(int userId);
    
    private:
        UserController(); // private to prevent direct instantiation
        static UserController* instance; // Pointer to the single instance of UserController
        int currentUser; // the currently logged in user
};

#endif
