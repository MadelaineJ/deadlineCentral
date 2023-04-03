#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <string>
#include "task.hpp"
// custom header files
#include "commands.hpp"
#include "userController.hpp"
#include "taskController.hpp"
#include "filterTaskController.hpp"
#include "subscriptionController.hpp"
#include "courseController.hpp"
// models
#include "task.hpp"

using namespace std;

UserController *userController = UserController::getInstance();
TaskController *taskController = TaskController::getInstance();
FilterTaskController *filterTaskController = FilterTaskController::getInstance();
SubscriptionController *subscriptionController = SubscriptionController::getInstance();
CourseController *courseController = CourseController::getInstance();

// Account commands
void handleViewAccount() {
    cout << "handling viewAccount" << endl;
}
void handleUpdateAccount() {
    cout << "handling updateAccount" << endl;
}
void handleDeleteAccount() {
    cout << "handling deleteAccount" << endl;
}
void handleCreateAccount(int userType) {
    cout << "handling createAccount" << endl;

    bool goodPassword = false;

    string name, passwordOriginal, passwordNew, email;
    cout << "Enter your name: ";
    cin >> name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    
    cout << "Enter your email: ";
    cin >> email;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (!goodPassword) {
        cout << "Enter your password: ";
        cin >> passwordOriginal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Confirm your password: ";
        cin >> passwordNew;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goodPassword = (passwordOriginal == passwordNew);
        if (!goodPassword) cout << "ERROR: Passwords do not match. Try again" << endl;
    }

    if (userType == 1) { // student
        userController->createStudent(name, email, passwordOriginal);
        cout<<"Student Account Created"<<endl;
    } else { // instructor
        userController->createInstructor(name, email, passwordOriginal);
        cout<<"Instructor Account Created"<<endl;
    }
}
void handleLogin(){
    cout << "handling login" << endl;

    string password, email;
    bool successfulLogin = false;
    while (!successfulLogin) {
        cout << "Enter your email: ";
        cin >> email;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter your password: ";
        cin >> password;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // verify credentials
        successfulLogin = userController->validateCredentials(email, password);
        if (successfulLogin) {
            cout << "You are now logged in" << endl;
        } else {
            cout << "Error, invalid username or password, please try again" << endl;
        }      
    }
}


// task commands
void handleCreateTask(){
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
//int typeFilter, int courseFilter, int completedFilter, int daysPriorFilter, int daysFutureFilter
// void handleSortTasks() {
//     cout << "handling a task thing" << endl;
// }
void handleSortByWeight() {
    cout << "handleSortByWeight" << endl;
    
}
void handleSortByName() {
    cout << "handleSortByName" << endl;
}
void handleSortByType() {
    cout << "handleSortByType" << endl;
}

// void handleFilterTasks() {
//     cout << "handling a task thing" << endl;
// }
void handleFilterByType(int type) {
    cout << "handleFilterByType" << endl;

    list<Task> filteredList = filterTaskController->filterTasksByType(type);
    printTaskList(filteredList);
}

// TODO: add error checking to courseId input
void handleFilterByCourse() {
    cout << "handleFilterByCourse" << endl;
    vector<Course> courseList = subscriptionController->viewCurrentSubscriptions();
    cout << "==== Choose Course ====" << endl;
    for (int i = 0; i < courseList.size(); i++) {
        cout << i << ". " << courseList[i].getCourseName() << endl;
    }
    cout << ">>> ";
    int courseId;
    cin >> courseId;
    
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // TODO: print all courses the user is subscribed to and have them pick in a menu
    // OR
    // TODO: check to see if the course exists first
    
    list<Task> filteredList = filterTaskController->filterTasksByCourse(courseList[courseId].getCourseId());
    printTaskList(filteredList);
}

void handleViewAllTasks() {
    cout << "handling handleViewAllTasks()" << endl;
    list<Task> filteredList = filterTaskController->viewAllUserTasks();
    printTaskList(filteredList);
}

void handleDeleteTask(){

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

void handleEditTask(){
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

// course commands

void handleCreateCourse(){
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

void handleDeleteCourse(){
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

void handleEditCourse(){

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

void handleViewCourse() {
    cout << "handling handleViewCourse()" << endl;
}

void handleSubscribeCourse(){

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

void handleUnsubscribeCourse(){
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



// helper functions
// written by chatGPt given the below input with only minor modifications
/*

I have a list of C++ objects, of custom class type "Task".  here is the constructor:

< constructor for Task given>

I need a function that will print a list of tasks in rows. Such that the columbs are the member attributes of task, and each row represents a new task. Everything should be formatted nicely in a terminal output. can you build this function for me? Assume you this list:
list<Task> list = getTaskList();

Minor modifications were requested from chatGPT such as left align
*/

void printTaskList(const list<Task>& taskList) {
    int idWidth = 2;
    int nameWidth = 6;
    int typeWidth = 4;
    int ownerWidth = 5;
    int descriptionWidth = 15;
    int dueDateWidth = 10;
    int completionWidth = 9;
    int weightWidth = 6;

    // Calculate the maximum width of each column
    for (Task task : taskList) {
        idWidth = max(idWidth, (int)to_string(task.getTaskId()).length());
        nameWidth = max(nameWidth, (int)task.getTaskName().length());
        typeWidth = max(typeWidth, (int)task.getTypeName().length());
        ownerWidth = max(ownerWidth, (int)to_string(task.getTaskOwner()).length());
        descriptionWidth = max(descriptionWidth, (int)task.getTaskDescription().length());
        dueDateWidth = max(dueDateWidth, (int)task.getDueDate().length());
        completionWidth = max(completionWidth, (int)to_string(task.getCompletionStatus()).length());
        weightWidth = max(weightWidth, (int)to_string(task.getWeight()).length());
    }

    // Print the table headers
    cout << setw(idWidth) << "ID" << " | ";
    cout << setw(nameWidth) << "Name" << " | ";
    cout << setw(typeWidth) << "Type" << " | ";
    cout << setw(ownerWidth) << "Owner" << " | ";
    cout << setw(descriptionWidth) << "Description" << " | ";
    cout << setw(dueDateWidth) << "Due Date" << " | ";
    cout << setw(completionWidth) << "Completed" << " | ";
    cout << setw(weightWidth) << "Weight" << endl;

    // Print the separator
    cout << string(idWidth, '-') << "-+-";
    cout << string(nameWidth, '-') << "-+-";
    cout << string(typeWidth, '-') << "-+-";
    cout << string(ownerWidth, '-') << "-+-";
    cout << string(descriptionWidth, '-') << "-+-";
    cout << string(dueDateWidth, '-') << "-+-";
    cout << string(completionWidth, '-') << "-+-";
    cout << string(weightWidth, '-') << "-" << endl;

    // Print the table rows
    for (Task task : taskList) {
        cout << setw(idWidth) << task.getTaskId() << " | ";
        cout << setw(nameWidth) << task.getTaskName() << " | ";
        cout << setw(typeWidth) << task.getTypeName() << " | ";
        cout << setw(ownerWidth) << task.getTaskOwner() << " | ";
        cout << setw(descriptionWidth) << task.getTaskDescription() << " | ";
        cout << setw(dueDateWidth) << task.getDueDate() << " | ";
        cout << setw(completionWidth) << (task.getCompletionStatus() ? "Yes" : "No") << " | ";
        cout << setw(weightWidth) << task.getWeight() << endl;
    }
}

