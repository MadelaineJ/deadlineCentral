#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
// custom header files
#include "commandHandler.hpp"
#include "commands.hpp"


using namespace std;

// Todo, set this to be null or -1 and get updated on login.
// CommandHandler::CommandHandler() {
//     int currentUser = 101;
// }

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
		        handleHelp();
                break;
	        case 5:
                cout << "Quitting...\n";
                exit(0); // TODO: figure out if this is bad
            default:
                cout << "Invalid input\n";
                break;
        }
    } while (input != 5);
}


void CommandHandler::manageAccount() {
    int input;
    do {
        accountMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                handleViewAccount();
                break;
            case 2:
                handleUpdateAccount();
                break;
            case 3:
                handleDeleteAccount();
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
                handleViewAllTasks();
                break;
            case 2:
                handleEditTask();
                break;
            case 3:
                handleDeleteTask();
                break;
            case 4:
                handleCreateTask();
                break;
            case 5:
                manageMain();
                break;
            default:
                cout << "Invalid input\n";
                break;
        }
    } while (input != 5);
} 

void CommandHandler::manageCourse() {
    int input;
    do {
        courseMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                handleViewCourse();
                break;
            case 2:
                handleEditCourse();
                break;
            case 3:
                handleSubscribeCourse();
                break;
            case 4:
                handleUnsubscribeCourse();
                break;
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
// The following were written by chat GPT by asking it to create a help menu 
// for the associated switch statement

void CommandHandler::mainMenu() {
    cout << "===== MENU =====" << std::endl;
    cout << "1. Manage Account" << std::endl;
    cout << "2. Manage Tasks" << std::endl;
    cout << "3. Manage Courses" << std::endl;
    cout << "4. Help" << std::endl;
    cout << "5. Quit" << std::endl;
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
    cout << "1. View All Tasks" << std::endl;
    cout << "2. Edit a Task" << std::endl;
    cout << "3. Delete a Task" << std::endl;
    cout << "4. Create a Task" << std::endl;
    cout << "5. Main Menu" << std::endl;
}

void CommandHandler::courseMenu() {
    //if(User->currUser.userId){
        cout << "===== COURSE MENU =====" << std::endl;
        cout << "1. View Course Info" << std::endl;
        cout << "2. Enroll in Course" << std::endl;
        cout << "3. View Enrolled Courses" << std::endl;
        cout << "4. Unenroll from Course" << std::endl;
        cout << "5. Main Menu" << std::endl;
    //}else{
        /*
        cout << "===== COURSE MENU =====" << std::endl;
        cout << "1. Create Course" << std::endl;
        cout << "2. Update Course" << std::endl;
        cout << "3. View Course" << std::endl;
        cout << "4. Remove Course" << std::endl;
        cout << "5. Add Task" << std::endl;
        cout << "6. Main Menu" << std::endl;
        */
    //}
}

void CommandHandler::handleHelp() {
    cout << "===== HELP =====" << std::endl;
    cout << "To navigate through the menus, enter the number corresponding to the option you want to select and press Enter." << std::endl;
    cout << "For example, to choose the 'Manage Account' option in the main menu, enter '1' and press Enter." << std::endl;
    cout << "To return to the main menu from any submenu, select the option that says 'Main Menu' or enter the corresponding number and press Enter." << std::endl;
    cout << "To quit the application, enter '5' from the main menu and press Enter." << std::endl;
    cout << "The only valid commands in the menus are numbers 1-4 and 5 to quit from the main menu." << std::endl;
}

