#ifndef USER_DB_H
#define USER_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>

// custom header files
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
        int createUser(Student U);
        int createUser(Instructor U);
        bool updateUser(User U, int userID);
        bool deleteUser(int userID);
        User getUserInfoById(int userID);
        User getUserInfoByEmail(string email);
        list<int> getTaskList(int userID);
    private:
        UserDB();
        static UserDB* instance;
        bool isStudent(int userID);
};

#endif 

