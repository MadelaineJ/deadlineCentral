#ifndef USER_DB_H
#define USER_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include "instructor.hpp"
#include "student.hpp"
#include "controllerDb.hpp"
#include "user.hpp"

using namespace std;
using namespace oracle::occi;

class UserDB 
{
    public:
        static UserDB* getInstance();
        ~UserDB();
        bool createUser(Student U);
        bool createUser(Instructor U);
        bool updateUser(User U, int userID);
        bool deleteUser(int userID);
        User getUserInfo(int userID);
    private:
        UserDB();
        static UserDB* instance;
        bool isStudent(int userID);
};

#endif 

