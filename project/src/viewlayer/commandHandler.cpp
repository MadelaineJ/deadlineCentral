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
    do {
        taskMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                printf("\033[2J\033[H");
                handleViewAllTasks();
                manageAllTasks();
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
void CommandHandler::manageAllTasks() {
    int input;
    do {
        viewAllTasksMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                manageSortTasks();
                break;
            case 2:
                manageFilterTasks();
                break;
            case 3:
                return;
            default:
                cout << "Invalid input\n";
                break;
        }
    } while(1);
}

void CommandHandler::manageFilterTasks() {
    int input;
    int type = -1;
    do {
        filterTasksMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                handleFilterByCourse();
                break;
            case 2:
                type = manageChooseTaskType();
                handleFilterByType(type);
                break;
            case 3:
                filterTasksByOneWeek();
                break;
            case 4:
                filterTasksByOneMonth();
                break;
            case 5:
                filterTasksByFuture();
                break;
            case 6:
                handleViewAllTasks();
                break;
            case 7:
                return;
            default:
                cout << "Invalid input\n";
                break;
        }
    } while(1);
}

int CommandHandler::manageChooseTaskType() {
    int input;
    do {
        chooseTaskTypeMenu();
        input = getUserInput();
 //       printf("\033[2J\033[H");
        switch (input) {
            case 1:
                return 0;
            case 2:
                return 1;
            case 3:
                return 2;
            case 4:
                return 3;
            case 5:
                return 4;
            case 6:
                return 5;
            case 7:
                return 10;
            default:
                cout << "Invalid input\n";
                break;
        }
    } while(1);
}

void CommandHandler::manageSortTasks() {
    int input;
    do {
        sortTasksMenu();
        input = getUserInput();
        switch (input) {
            case 1:
                handleSortByWeight();
                break;
            case 2:
                handleSortByName();
                break;
            case 3:
                handleSortByType();
                break;
            case 4:
                handleSortByOwner();
                break;
            case 5:
                handleSortByDate();
                break;
            case 6:
                return;
            default:
                cout << "Invalid input\n";
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
                handleAddExistingTask();
                break;
            case 2:
                handleCreateCourseTask();
                break;
            case 3:
                return;
            default:
                cout << "Invalid input\n";
                addTaskMenu();
                
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
                        printf("\033[2J\033[H");
                        handleViewCourses();
                        break;
                    case 2:
                        handleSubscribeCourse();
                        break;
                    case 3:
                        handleUnsubscribeCourse();
                        break;
                    case 4:                                             
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
                        handleViewCourses();
                        break;
                    case 4:
                        handleDeleteCourse();
                        break;
                    case 5:
                        addTask();
                        break;
                    case 6:
                        handleViewConsolidatedDeadlines();
                        break;
                    case 7:
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
    cout << "3. Task Menu" << std::endl;
}

// Task Related
void CommandHandler::taskMenu() {
    cout << "===== TASK MENU =====" << std::endl;
    cout << "1. View All Tasks" << std::endl;
    cout << "2. Edit a Task" << std::endl;
    cout << "3. Delete a Task" << std::endl;
    cout << "4. Create a Task" << std::endl;
    cout << "5. Main Menu" << std::endl;
}

void CommandHandler::viewAllTasksMenu() {
    cout << "===== SORT OR FILTER TASKS =====" << std::endl;
    cout << "1. Sort" << std::endl;
    cout << "2. Filter" << std::endl;
    cout << "3. Task Menu" << std::endl;
}

void CommandHandler::filterTasksMenu() {
    cout << "===== FILTER BY =====" << std::endl;
    cout << "1. Course" << std::endl;
    cout << "2. Type" << std::endl;
    cout << "3. Due This Week" << std::endl;
    cout << "4. Due This Month" << std::endl;
    cout << "5. Future Tasks" << std::endl;
    cout << "6. Clear Filters" << std::endl;
    cout << "7. BACK" << std::endl;
    
}

void CommandHandler::sortTasksMenu() {
    cout << "===== SORT BY =====" << std::endl;
    cout << "1. Weight" << std::endl;
    cout << "2. Name" << std::endl;
    cout << "3. Type" << std::endl;
    cout << "4. Course" << std::endl;
    cout << "5. Date" << std::endl;
    cout << "6. BACK" << std::endl;
}

void CommandHandler::chooseTaskTypeMenu() {
    cout << "===== CHOOSE TASK TYPE =====" << std::endl;
    cout << "1. Participation" << std::endl;
    cout << "2. Assignment" << std::endl;
    cout << "3. Project" << std::endl;
    cout << "4. Quiz" << std::endl;
    cout << "5. Test" << std::endl;
    cout << "6. Exam" << std::endl;
    cout << "7. Personal" << std::endl;
}

void CommandHandler::courseMenu() {
    if(userController->getCurrentUser() <= 1000){ // if the current user's id is less than 1001 they are a student
        cout << "===== COURSE MENU =====" << std::endl;
        cout << "1. View Courses" << std::endl;
        cout << "2. Subscribe to Course" << std::endl;
        cout << "3. Unsubscribe from Course" << std::endl;
        cout << "4. Main Menu" << std::endl;
    }else{  // else they are an instructor
        cout << "===== COURSE MENU =====" << std::endl;
        cout << "1. Create Course" << std::endl;
        cout << "2. Update Course" << std::endl;
        cout << "3. View Courses" << std::endl;
        cout << "4. Remove Course" << std::endl;
        cout << "5. Add Task" << std::endl;
        cout << "6. View Conflicting Student Deadlines" << std::endl;
        cout << "7. Main Menu" << std::endl;
    }
}

void CommandHandler::addTaskMenu() {
    cout << "===== ADD TASK =====" << endl;
    cout << "1. Add Existing Tasks" << endl;
    cout << "2. Create a new Task" << endl;
    cout << "3. Course Menu" << endl;
}

void CommandHandler::handleHelp() {
    cout << "===== HELP =====" << std::endl;
    cout << "To navigate through the menus, enter the number corresponding to the option you want to select and press Enter." << std::endl;
    cout << "For example, to choose the 'Manage Account' option in the main menu, enter '1' and press Enter." << std::endl;
    cout << "To return to the main menu from any submenu, select the option that says 'Main Menu' or enter the corresponding number and press Enter." << std::endl;
    cout << "To quit the application, enter '5' from the main menu and press Enter." << std::endl;
    cout << "The only valid commands in the menus are numbers 1-4 and 5 to quit from the main menu." << std::endl;
}

