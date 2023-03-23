#ifndef USER_DB_H
#define USER_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include "../models/instructor.hpp"
#include "../models/student.hpp"
#include "../models/user.hpp"

using namespace std;
using namespace oracle::occi;

class UserDB 
{
    public:
        UserDB(){}
        ~UserDB(){}
        //TODO once Student and Instructor are done, uncomment these
        //bool createUser(Student U);
        //bool createUser(Instructor U);
        bool updateUser(User U);
        bool deleteUser(User U);
        //TODO change return type to User when implemented
        void getUserInfo(int userID);
    private:
};

#endif 

