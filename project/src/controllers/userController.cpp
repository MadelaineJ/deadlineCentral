// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>


// Custom header files
#include "userController.hpp"
#include "userDb.hpp"
#include "user.hpp"
#include "student.hpp"
#include "instructor.hpp"


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
void UserController::createStudent(string name, string email, string password) {
    list<int> tasks = {};
    Student* student = new Student(-1, name, password, email, tasks);
    userDb->createUser(*student);
}

// createInstructor
void UserController::createInstructor(string name, string email, string password) {
    list<int> tasks = {};
    Instructor* instructor = new Instructor(-1, name, password, email, tasks);
    userDb->createUser(*instructor);
}

// deleteUser
void UserController::deleteUser() {

}

// getUserInfo
User UserController::getUserInfo(int userId, string email) {
    if (userId == -1) {
        return userDb->getUserInfoByEmail(email);
    } else {
        return userDb->getUserInfoById(userId);
    }

}

//validate credentials entered by the users
bool UserController::validateCredentials(string email, string password) {
    User user = this->getUserInfo(-1, email);

    if (user.getPassword() != password) {
        return false;
    } else {
        this->currentUser = user.getUserId();
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