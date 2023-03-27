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
        static SubscriptionController* getInstance(); // gets the single instance of this class
        ~SubscriptionController();
        
        void addSubscription();

        void removeSubscription();

        void viewCurrentSubscriptions();

        void viewAvailableSubscriptions();
    
    private:
        SubscriptionController();
        static SubscriptionController* instance; // Pointer to the single instance of SubscriptionController
};

#endif
