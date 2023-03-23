#ifndef SUBSCRIPTIONCONTROLLER_H
#define SUBSCRIPTIONCONTROLLER_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;


class SubscriptionController 
{
    public:
        SubscriptionController();
        ~SubscriptionController();
        
        void addSubscription();

        void removeSubscription();

        void viewCurrentSubscriptions();

        void viewAvailableSubscriptions();
};

#endif
