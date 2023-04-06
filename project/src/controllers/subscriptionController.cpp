// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

// Custom header files
#include "subscriptionController.hpp"
#include "subscriptionDb.hpp"

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
void SubscriptionController::addSubscription(int courseId, int userId) {
	this->subscriptionDB->createSubscription(userId, courseId);
}

// removeSubscription
void SubscriptionController::removeSubscription(int courseId, int userId) {
    this->subscriptionDB->deleteSubscription(userId, courseId);
}

// viewCurrentSubscriptions
vector<Course> SubscriptionController::viewCurrentSubscriptions(int userId) {
    list<Course> courseList = this->subscriptionDB->getCourseSubscriptions(userId);
    std::vector<Course> courseVector(courseList.begin(), courseList.end()); 
    return courseVector;
}

// viewAvailableSubscriptions
void SubscriptionController::viewAvailableSubscriptions() {

}
