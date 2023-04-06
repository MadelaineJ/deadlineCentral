#ifndef SUBSCRIPTIONCONTROLLER_H
#define SUBSCRIPTIONCONTROLLER_H
#pragma once

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

// custom header files
#include "subscriptionDb.hpp"

using namespace std;


class SubscriptionController 
{
    public:
        static SubscriptionController* getInstance(); // gets the single instance of this class
        ~SubscriptionController();
        
        void addSubscription(int courseId, int userId);

        bool removeSubscription(int courseId, int userId);

        vector<Course> viewCurrentSubscriptions(int userId);

        void viewAvailableSubscriptions();
    
    private:
        SubscriptionController();
        static SubscriptionController* instance; // Pointer to the single instance of SubscriptionController
        SubscriptionDB *subscriptionDB = SubscriptionDB::getInstance();
};

#endif
