// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


// Custom header files
#include "userController.hpp"
#include "userDb.hpp"
#include "user.hpp"

using namespace std;

UserController *UserController::instance = nullptr; // initialize the static pointer

// returns a pointer to the single instance of UserController, if there is no instance it creates a new one
UserController* UserController::getInstance() {
    if(instance == nullptr) {
        instance = new UserController();
    }
    return instance;
}

// constructor is private to avoid multiple instances of UserController, instead use static method getInstance 
UserController::UserController()
{
    this->currentUser = -1;
}

// destructor
UserController::~UserController() { 
	
}

// createStudent
void UserController::createStudent() {
	
}

// createInstructor
void UserController::createInstructor() {
    
}

// deleteUser
void UserController::deleteUser() {

}

// getUserInfo
void UserController::getUserInfo() {

}

//validate credentials entered by the users
bool UserController::validateCredentials(int userId, string password) {
    User user = userDb->getUserInfo(userId);

    if (user.getPassword() != password) {
        return false;
    } else {
        this->currentUser = userId;
        return true;
    }
    
}


int UserController::getCurrentUser() {
    return this->currentUser;
}

//todo, remove this
void UserController::setCurrentUser(int userId) {
    this->currentUser = userId;
}