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


void displayTitle();

int main() {


    // instantiate all static controllers
    UserController::getInstance();
    TaskController::getInstance();
    FilterTaskController::getInstance();
    SubscriptionController::getInstance();
    CourseController::getInstance();

    // Display start up message
    displayTitle();

    // start Deadline Central
    CommandHandler commandHandler;
    commandHandler.manageMain();

    cout << "Bye!" << endl;
}


void displayTitle(){

    string title =
    "  ________                     .___.__  .__                _________                __                .__   \n"
    "  \\______ \\   ____ _____     __| _/|  | |__| ____   ____   \\_   ___ \\  ____   _____/  |_____________  |  |  \n"
    "    |    |  \\_/ __ \\__  \\   / __ | |  | |  |/    \\_/ __ \\  /    \\  \\/_/ __ \\ /    \\   __\\_  __ \\__  \\ |  |  \n"
    "    |____|  \\  ___/ / __ \\_/ /_/ | |  |_|  |   |  \\  ___/  \\     \\___\\  ___/|   |  \\  |  |  | \\// __ \\|  |__\n"
    "  /_______  /\\___  >____  /\\____ | |____/__|___|  /\\___  >  \\______  /\\___  >___|  /__|  |__|  (____  /____/\n"
    "          \\/     \\/     \\/      \\/              \\/     \\/          \\/     \\/     \\/                 \\/      \n";

    cout<<title<<endl;

}


