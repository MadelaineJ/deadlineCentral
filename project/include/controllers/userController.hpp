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
        UserController();
        ~UserController();
        
        void createStudent();

        void createInstructor();

        void deleteUser();

        void getUserInfo();
};

#endif
