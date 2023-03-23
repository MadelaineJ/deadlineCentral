#ifndef CONTROLLER_DB_H
#define CONTROLLER_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include <list>
#include <string>

#include "course.hpp"

using namespace std;
using namespace oracle::occi;

class SubscriptionDB 
{
    public:
        SubscriptionDB();
        ~SubscriptionDB();

        Course* getAvailableCourseList(int courseID);
        Course* getCourseSubscriptions(int studentID);
        bool deleteSubscription(int studentID, int courseID);
        bool createSubscription(int studentID, int courseID);
    private:
        // helper functions
        int getCourseID(std::string courseCode, std::string instructorName);
};

#endif // CONTROLLER_DB_H