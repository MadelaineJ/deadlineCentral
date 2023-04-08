#ifndef SUBSCRIPTION_CONTROLLER_DB_H
#define SUBSCRIPTION_CONTROLLER_DB_H

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>
#include <list>
#include <string>
#include <sstream> // for string building the SQL query


// custom header files
#include "course.hpp"

using namespace std;
using namespace oracle::occi;

class SubscriptionDB 
{
    public:
        static SubscriptionDB* getInstance(); // gets the single instance of this class
        ~SubscriptionDB();

        vector<Course> getAvailableCourseList(int studentId);
        list<Course> getCourseSubscriptions(int studentID);
        bool deleteSubscription(int studentID, int courseID);
        bool createSubscription(int studentID, int courseID);
    private:
        SubscriptionDB(); // private to prevent direct instantiation
        static SubscriptionDB* instance; // Pointer to the single instance of SubscriptionDB
        
};

#endif