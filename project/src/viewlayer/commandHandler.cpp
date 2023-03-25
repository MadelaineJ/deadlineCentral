#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
// custom header files
#include "commandHandler.hpp"
#include "commands.hpp"


using namespace std;

// constructor
// CommandHandler::CommandHandler()
// {
// }

// // destructor
// CommandHandler::~CommandHandler() { }


void CommandHandler::manageMain() {
int input;
    do {
        mainMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                manageAccount();
                break;
            case 2:
                manageTask();
                break;
            case 3:
                manageCourse();
                break;
            case 4:
                cout << "Quitting...\n";
                exit(0); // TODO: figure out if this is bad
            default:
                cout << "Invalid input\n";
                break;
        }
    } while (input != 4);
}


void CommandHandler::manageAccount() {
    int input;
    do {
        accountMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                viewAccount();
                break;
            case 2:
                updateAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                manageMain();
                break;
            default:
                cout << "Invalid input\n";
                break;
        }
    } while (input != 4);
}


void CommandHandler::manageTask() {
    int input;
    do {
        taskMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                viewTask();
                break;
            case 2:
                updateTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                manageMain();
                break;
            default:
                cout << "Invalid input\n";
                break;
        }
    } while (input != 4);
} 

void CommandHandler::manageCourse() {
    int input;
    do {
        courseMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                viewCourse();
                break;
            case 2:
                updateCourse();
                break;
            case 3:
                subscribeCourse();
                break;
            case 4:
                unsubscribeCourse();
            case 5:
                manageMain();
                break;
            default:
                cout << "Invalid input\n";
                break;
        }
    } while (input != 4);
}


int CommandHandler::getUserInput() {
    int input;
    std::cout << ">>> ";
    std::cin >> input;
    return input;
}


// menu printers:

void CommandHandler::mainMenu() {
    cout << "===== MENU =====" << std::endl;
    cout << "1. Manage Account" << std::endl;
    cout << "2. Manage Tasks" << std::endl;
    cout << "3. Manage Courses" << std::endl;
    cout << "4. Quit" << std::endl;
}

void CommandHandler::accountMenu() {
    cout << "===== ACCOUNT MENU =====" << std::endl;
    cout << "1. View Account Info" << std::endl;
    cout << "2. Update Account Info" << std::endl;
    cout << "3. Delete Account" << std::endl;
    cout << "4. Main Menu" << std::endl;
}

void CommandHandler::taskMenu() {
    cout << "===== TASK MENU =====" << std::endl;
    cout << "1. Create Task" << std::endl;
    cout << "2. View Tasks" << std::endl;
    cout << "3. Delete Task" << std::endl;
    cout << "4. Main Menu" << std::endl;
}

void CommandHandler::courseMenu() {
    cout << "===== COURSE MENU =====" << std::endl;
    cout << "1. View Course Info" << std::endl;
    cout << "2. Enroll in Course" << std::endl;
    cout << "3. View Enrolled Courses" << std::endl;
    cout << "4. Unenroll from Course" << std::endl;
    cout << "5. Main Menu" << std::endl;
}