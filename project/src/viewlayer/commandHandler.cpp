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
		        handleHelp();
	        case 5:
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

////////////////////////login/////////////////////////////

void CommandHandler::handleLogin(){
    string userId, password;

    cout << "Enter 'create' to create a new user, or press enter to login: ";
    string createOption;
    getline(cin, createOption);

    if (createOption == "create") {
        cout << "Enter the new user ID: ";
        getline(cin, userId);
        cout << "Enter the new password: ";
        getline(cin, password);

        /*
        // Created new user using the UserController
        if (userId < 1000) {
            userController->createStudent(userId, password);
            cout<<"student created"<<endl;
        }
        else {
            userController->createInstructor(userId, password);
            cout<<"Instructor created"<<endl;
        }*/
    }
    else {
        cout << "Enter your user ID: ";
        getline(cin, userId);
        cout << "Enter your password: ";
        getline(cin, password);

        /*
        // Validating the user ID and password
        if (userController->validateCredentials(userId, password)) {
            cout << "Login successful!" << endl;
        }
        else {
            cout << "Invalid user ID or password." << endl;
        }*/
    }

    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

// menu printers:

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
    cout << "1. Create Task" << std::endl;
    cout << "2. View Tasks" << std::endl;
    cout << "3. Delete Task" << std::endl;
    cout << "4. Main Menu" << std::endl;
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


//handle commands
void CommandHandler::handleCreateCourse(){
    string name, description, code;

    
    cout << "Enter the course name: ";
    getline(cin, name);
    cout << "Enter the calendar description: ";
    getline(cin, description);
    cout << "Enter the course code: ";
    getline(cin, code);

    /*
    if (courseController->createCourse(name, description, code)) {
        cout << "Course created successfully!" << endl;
    }
    else {
        cout << "Error creating course. Please try again." << endl;
    }*/

    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void CommandHandler::handleCreateTask(){
    string name, description, dueDate;
    double weight;
    int type;

    
    cout << "Enter the task name: ";
    getline(cin, name);
    cout << "Enter the task description: ";
    getline(cin, description);
    cout << "Enter the task due date (YYYY-MM-DD): ";
    getline(cin, dueDate);
    cout << "Enter the task weight (as a decimal): ";
    cin >> weight;
    cout << "Enter the task type (0 = Participation 1 = Assignment, 2 = Project, 3 = Quiz, 4 = MidTerm 5 = FinalExam 10 = Personal): ";//double check
    cin >> type;

    /*
    if (taskController->createTask(name, description, dueDate, weight, type)) {
        cout << "Task created successfully!" << endl;
    }
    else {
        cout << "Error creating task. Please try again." << endl;
    }*/

    
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void CommandHandler::handleEditTask(){
    int taskId;
    string name, description, dueDate;
    double weight;
    int type;

    
    cout << "Enter the ID of the task to edit: ";
    cin >> taskId;
    cout << "Enter the new task name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the new task description: ";
    getline(cin, description);
    cout << "Enter the new task due date (YYYY-MM-DD): ";
    getline(cin, dueDate);
    cout << "Enter the new task weight (as a decimal): ";
    cin >> weight;
    cout << "Enter the new task type (1 = Homework, 2 = Quiz, 3 = Exam, 4 = Project): ";
    cin >> type;

    /*
    if (taskController->editTask(taskId, name, description, dueDate, weight, type)) {
        cout << "Task edited successfully!" << endl;
    }
    else {
        cout << "Error editing task. Please try again." << endl;
    }*/

    
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void CommandHandler::handleEditCourse(){

    int courseId;
    string name, description, code;

    
    cout << "Enter the ID of the course to edit: ";
    cin >> courseId;
    cout << "Enter the new course name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the new calendar description: ";
    getline(cin, description);
    cout << "Enter the new course code: ";
    getline(cin, code);

    /*
    if (courseController->editCourse(courseId, name, description, code)) {
        cout << "Course edited successfully!" << endl;
    }
    else {
        cout << "Error editing course. Please try again." << endl;
    }
    */
    
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void CommandHandler::handleSubscribeCourse(){

    string courseCode;

    cout << "Enter the course code to subscribe to: ";
    getline(cin, courseCode);

    /*
    if (subscriptionController->addSubscription(courseCode)) {
        cout << "Subscribed to course successfully!" << endl;
    }
    else {
        cout << "Error subscribing to course. Please try again." << endl;
    }
    */

    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void CommandHandler::handleUnsubscribeCourse(){
    string courseCode;

    cout << "Enter the course code to unsubscribe from: ";
    getline(cin, courseCode);

    /*
    if (subscriptionController->removeSubscription(courseCode)) {
        cout << "Unsubscribed from course successfully!" << endl;
    }
    else {
        cout << "Error unsubscribing from course. Please try again." << endl;
    }
    */
}


void CommandHandler::handleDeleteCourse(){
    int courseId;

    cout << "Enter the ID of the course to delete: ";
    cin >> courseId;

    /*
    if (courseController->deleteCourse(courseId)) {
        cout << "Course deleted successfully!" << endl;
    }
    else {
        cout << "Error deleting course. Please try again." << endl;
    }
    */

    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void CommandHandler::handleDeleteTask(){

    int taskId;

    cout << "Enter the ID of the task to delete: ";
    cin >> taskId;

    /*
    if (taskController->deleteTask(taskId)) {
        cout << "Task deleted successfully!" << endl;
    }
    else {
        cout << "Error deleting task. Please try again." << endl;
    }
    */

    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void CommandHandler::handleViewTask(){}
void CommandHandler::handleViewCourse(){}
void CommandHandler::handleSortTasks(){}
void CommandHandler::handleViewConsolidatedDeadlines(){}