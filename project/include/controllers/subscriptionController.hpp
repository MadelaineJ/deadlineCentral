#ifndef SUBSCRIPTIONCONTROLLER_H
#define SUBSCRIPTIONCONTROLLER_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

// custom header files
#include "subscriptionDb.hpp"
#include "userController.hpp"
using namespace std;


class SubscriptionController 
{
    public:
        static SubscriptionController* getInstance(); // gets the single instance of this class
        ~SubscriptionController();
        
        void addSubscription();

        void removeSubscription();

        vector<Course> viewCurrentSubscriptions();

        void viewAvailableSubscriptions();
    
    private:
        SubscriptionController();
        static SubscriptionController* instance; // Pointer to the single instance of SubscriptionController
        SubscriptionDB *subscriptionDB = SubscriptionDB::getInstance();
        UserController *userController = UserController::getInstance();
};

#endif
