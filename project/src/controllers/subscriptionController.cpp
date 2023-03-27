// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

// Custom header files
#include "subscriptionController.hpp"

using namespace std;

SubscriptionController *SubscriptionController::instance = nullptr; // initialize the static pointer

// returns a pointer to the single instance of SubscriptionController, if there is no instance it creates a new one
SubscriptionController* SubscriptionController::getInstance() {
    if(instance == nullptr) {
        instance = new SubscriptionController();
    }
    return instance;
}

// constructor is private to avoid multiple instances of SubscriptionController, instead use static method getInstance 
SubscriptionController::SubscriptionController(){}

// destructor
SubscriptionController::~SubscriptionController() { 
	
}

// addSubscription
void SubscriptionController::addSubscription() {
	
}

// removeSubscription
void SubscriptionController::removeSubscription() {
    
}

// viewCurrentSubscriptions
void SubscriptionController::viewCurrentSubscriptions() {

}

// viewAvailableSubscriptions
void SubscriptionController::viewAvailableSubscriptions() {

}
