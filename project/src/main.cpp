// Custom Header files
#include "courseController.hpp"
#include "commandHandler.hpp"
#include "userController.hpp"
#include "taskController.hpp"
#include "filterTaskController.hpp"
#include "subscriptionController.hpp"
#include "courseController.hpp"
// Required Libraries
#include <iostream>
#include <string>
#include <list>


using namespace std;

int main() {


    // instantiate all static controllers
    UserController::getInstance();
    TaskController::getInstance();
    FilterTaskController::getInstance();
    SubscriptionController::getInstance();
    CourseController::getInstance();

    // start Deadline Central
    CommandHandler commandHandler;
    commandHandler.manageMain();

    cout << "bye!" << endl;
}
