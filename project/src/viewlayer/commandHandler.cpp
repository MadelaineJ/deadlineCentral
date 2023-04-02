#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
// custom header files
#include "commandHandler.hpp"
#include "commands.hpp"
#include "userController.hpp"


using namespace std;

// todo, update this to be one "start deadline central function"
void CommandHandler::manageMain() {
    int input;
    do {
        if (userController->getCurrentUser() == -1) // then no one is logged in
        {
            manageLogin();
        }
     //   printf("\033[2J\033[H");
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
                return;
            default:
                cout << "Invalid input\n";
                break;
        }        
    } while(1);
}

void CommandHandler::manageLogin() {
    int input;
    do {
        loginMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                handleLogin();
                return;
            case 2:
                manageCreateAccount();
                break;
            case 3:
		        handleHelp();
                break;
	        case 4:
                cout << "Quitting...\n";
                exit(0);
            default:
                cout << "Invalid input\n";
                break;
        }        
    } while(1);
}

void CommandHandler::manageCreateAccount() {
    int input;
    do {
        userTypeMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                handleCreateAccount(input);
                return;
            case 2:
                handleCreateAccount(input);
                return;
            case 3:
                return;
            default:
                cout << "Invalid input\n";
                break;
        }        
    } while(1);
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
                return;
                break;
            default:
                cout << "Invalid input\n";
                break;
            
        }
    } while(1);
}


void CommandHandler::manageTask() {
    int input;
    bool notDone = false;
    do {
        notDone = false;
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
                return;
            default:
                cout << "Invalid input\n";
                manageTask();
                break;
        }
    } while(1);
}

void CommandHandler::addTask() {
    int input;
    do {
        addTaskMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                handleViewAllTasks();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                return;
            default:
                cout << "Invalid input\n";
                addTaskMenu();
                break;
        } 
    }while(1);
}

void CommandHandler::manageCourse() {
    int input;
    do {
        courseMenu();
        input = getUserInput();
            // if student display student's choices
            if(userController->getCurrentUser() <= 1000){
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
                        return;
                    default:
                        cout << "Invalid input\n";
                        manageCourse();
                        break;
                }
            }else{ // then the user is an instructor so display instructor's choices
                switch (input) {
                    case 1:
                        handleCreateCourse();
                        break;
                    case 2:
                        handleEditCourse();
                        break;
                    case 3:
                        handleViewCourse();
                        break;
                    case 4:
                        handleDeleteCourse();
                        break;
                    case 5:
                        addTask();
                        break;
                    case 6:
                        return;
                    default:
                        cout << "Invalid input\n";
                        manageCourse();
                        break;                
                }
            }
    } while(1);
}


int CommandHandler::getUserInput() {
    int input;
    std::cout << ">>> ";
    std::cin >> input;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}


// menu printers:
// The following were mostly written by chat GPT by asking it to create a help menu 
// for the associated switch statement

void CommandHandler::mainMenu() {
    cout << "===== MENU =====" << std::endl;
    cout << "1. Manage Account" << std::endl;
    cout << "2. Manage Tasks" << std::endl;
    cout << "3. Manage Courses" << std::endl;
    cout << "4. Help" << std::endl;
    cout << "5. Quit" << std::endl;
}

void CommandHandler::loginMenu() {
    cout << "===== LOGIN MENU =====" << std::endl;
    cout << "1. Login" << std::endl;
    cout << "2. Create Account" << std::endl;
    cout << "3. Help" << std::endl;
    cout << "4. Quit" << std::endl;
}

void CommandHandler::accountMenu() {
    cout << "===== ACCOUNT MENU =====" << std::endl;
    cout << "1. View Account Info" << std::endl;
    cout << "2. Update Account Info" << std::endl;
    cout << "3. Delete Account" << std::endl;
    cout << "4. Main Menu" << std::endl;
}

void CommandHandler::userTypeMenu() {
    cout << "Are you an Instructor or Student?" << std::endl;
    cout << "1. Student" << std::endl;
    cout << "2. Instructor" << std::endl;
    cout << "3. Main Menu" << std::endl;
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
    if(userController->getCurrentUser() <= 1000){ // if the current user's id is less than 1001 they are a student
        cout << "===== COURSE MENU =====" << std::endl;
        cout << "1. View Course Info" << std::endl;
        cout << "2. Enroll in Course" << std::endl;
        cout << "3. View Enrolled Courses" << std::endl;
        cout << "4. Unenroll from Course" << std::endl;
        cout << "5. Main Menu" << std::endl;
    }else{  // else they are an instructor
        cout << "===== COURSE MENU =====" << std::endl;
        cout << "1. Create Course" << std::endl;
        cout << "2. Update Course" << std::endl;
        cout << "3. View Course" << std::endl;
        cout << "4. Remove Course" << std::endl;
        cout << "5. Add Task" << std::endl;
        cout << "6. Main Menu" << std::endl;
    }
}

void CommandHandler::addTaskMenu() {
    cout << "===== ADD TASK =====" << endl;
    cout << "1. View Existing Tasks" << endl;
    cout << "2. Add Task by Name" << endl;
    cout << "3. Create a new Task" << endl;
    cout << "4. Main Menu" << endl;
}

void CommandHandler::handleHelp() {
    cout << "===== HELP =====" << std::endl;
    cout << "To navigate through the menus, enter the number corresponding to the option you want to select and press Enter." << std::endl;
    cout << "For example, to choose the 'Manage Account' option in the main menu, enter '1' and press Enter." << std::endl;
    cout << "To return to the main menu from any submenu, select the option that says 'Main Menu' or enter the corresponding number and press Enter." << std::endl;
    cout << "To quit the application, enter '5' from the main menu and press Enter." << std::endl;
    cout << "The only valid commands in the menus are numbers 1-4 and 5 to quit from the main menu." << std::endl;
}

