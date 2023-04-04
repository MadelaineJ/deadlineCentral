#include <iostream>
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

// TODO: enable creating a course task if you're a professor somehow
void handleCreateTask(){
    // personal task only
    string name, description, dueDate;
    double weight;
    
    cout << "Enter the task name: ";
    getline(cin, name);
    cout << "Enter the task description: ";
    getline(cin, description);
    cout << "Enter the task due date (MM/DD/YYYY): ";
    getline(cin, dueDate);
    cout << "Enter the task weight (as a decimal): ";
    cin >> weight;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

 //   cout << "Enter the task type (0 = Participation 1 = Assignment, 2 = Project, 3 = Quiz, 4 = MidTerm 5 = FinalExam 10 = Personal): "; //double check
   // cin >> type;
    taskController->createUserTask(name, description, dueDate, weight);
}

void handleSortByWeight() {
    cout << "handleSortByWeight" << endl;
    filterTaskController->sortTasksByWeight();
    filterTaskController->printTaskList();
}
void handleSortByName() {
    cout << "handleSortByName" << endl;
    filterTaskController->sortTasksByName();
    filterTaskController->printTaskList();
}
void handleSortByType() {
    cout << "handleSortByType" << endl;
    filterTaskController->sortTasksByType();
    filterTaskController->printTaskList();
}

void handleSortByDate() {
    cout << "handleSortByDate" << endl;
    filterTaskController->sortTasksByDate();
    filterTaskController->printTaskList();
}
void handleSortByOwner() {
    cout << "handleSortByOwner" << endl;
    filterTaskController->sortTasksByOwner();
    filterTaskController->printTaskList();
}

// void handleFilterTasks() {
//     cout << "handling a task thing" << endl;
// }
void handleFilterByType(int type) {
    cout << "handleFilterByType" << endl;
    filterTaskController->filterTasksByType(type);
    filterTaskController->printTaskList();
}

// TODO: add error checking to courseId input
void handleFilterByCourse() {
    cout << "handleFilterByCourse" << endl;
    vector<Course> courseList = subscriptionController->viewCurrentSubscriptions();
    cout << "==== Choose Course ====" << endl;
    for (int i = 0; i < courseList.size(); i++) {
        cout << i+1 << ". " << courseList[i].getCourseName() << endl;
    }
    bool validInput = false;
    int courseId;
    while (!validInput) {
        cout << ">>> "; 
        cin >> courseId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if ((courseId < courseList.size()+1) && (courseId > 0)) {
            validInput = true;
        } else {
            cout << "Invalid choice, please try again" << endl;
        }
    }
    
    filterTaskController->filterTasksByCourse(courseList[courseId-1].getCourseId());
    filterTaskController->printTaskList();
   // printf("\033[2J\033[H");
}

void handleViewAllTasks() {
    filterTaskController->findAllUserTasks();
    filterTaskController->printTaskList();
}


// TODO -> this should list all the tasks
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

    handleViewAllTasks();
    cout << "Enter the ID of the task to edit: ";
    cin >> taskId;
    Task task = taskController->getTaskInfo(taskId);
    // TODO: add check if task doesn't exist or if they enter a string
    // TODO: should be that they can choose which values they want to edit
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

    
    if (courseController->createCourse(name, description, code)) {
        cout << "Course created successfully!" << endl;
    }
    else {
        cout << "Error creating course. Please try again." << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    int courseId;
    bool fail = false;

    cout << "Enter the ID of the course to view: ";
    cin >> courseId;
    cin.ignore();
    
    Course result = courseController->getCourseInfo(courseId);

    if(result.getCourseId() != 0){
        cout << "Course ID: " << result.getCourseId() << endl; 
        cout << "Course name: " << result.getCourseName() << endl;
        cout << "Course code: " << result.getCourseCode() << endl;
        cout << "Description: " << result.getCalendarDescription() << endl;
        cout << "Instructor ID: " << result.getInstructorId() << endl;
    }
    else{
        cout << "Invalid choice, please try again" << endl;
    }
    
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

