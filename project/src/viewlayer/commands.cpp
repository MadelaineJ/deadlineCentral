#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iomanip>

// custom header files
#include "commands.hpp"
#include "commandHandler.hpp"
#include "userController.hpp"
#include "taskController.hpp"
#include "filterTaskController.hpp"
#include "subscriptionController.hpp"
#include "courseController.hpp"
#include "aggregateDeadline.hpp"

// models
#include "task.hpp"
#include "course.hpp"

using namespace std;

UserController *userController = UserController::getInstance();
TaskController *taskController = TaskController::getInstance();
FilterTaskController *filterTaskController = FilterTaskController::getInstance();
SubscriptionController *subscriptionController = SubscriptionController::getInstance();
CourseController *courseController = CourseController::getInstance();

// Account commands
void handleViewAccount() {
    // TODO: refactor getUserInfo function
    // it doesn't make sense to call userController twice here.
    // getUserInfo shouldn't have to take an ID
    User user = userController->getUserInfo(userController->getCurrentUser(), "");
    cout << "The Current User is: ";
    user.printUserInfo();
}

// TODO: implement ability to change password
void handleUpdateAccount() {
    cout << "handling updateAccount" << endl;
    handleViewAccount();
    string name, email;
    cout << "Enter new Name: ";
    getline(cin, name);
    cout << "Enter new email: ";
    cin >> email;


    userController->updateUser(name, email);

}
void handleDeleteAccount() {
    cout << "handling deleteAccount" << endl;
    cout << "are you sure you want to delete your account? (y/n): ";
    string answer;
    cin >> answer;
    if (answer == "y") {
        userController->deleteUser(userController->getCurrentUser());
        cout << "You account Has been deleted" << endl;
        cout << "Goodbye" << endl;
        userController->setCurrentUser(-1);
    } else {
        cout << "You account has NOT been deleted" << endl;
    }
}
void handleCreateAccount(int userType) {

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

// Creates a personal Task
void handleCreateTask(){
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

    taskController->createUserTask(userController->getCurrentUser(), name, description, dueDate, weight);
}


void handleCreateCourseTask() {
    
    string name, description, dueDate;
    double weight;
    int type, courseId;
    
    cout << "Enter the task name: ";
    getline(cin, name);
    cout << "Enter the task description: ";
    getline(cin, description);
    cout << "Enter the task due date (MM/DD/YYYY): ";
    getline(cin, dueDate);
    cout << "Enter the task weight (as a decimal): ";
    cin >> weight;
            
    cout << "Choose Task Type" << endl;
    CommandHandler commandHandler;
    type = commandHandler.manageChooseTaskType();
    handleViewCourses();
    cout << "Which course would you like to add the task to?" << endl;
    cout << "Enter Course Id: ";
    cin >> courseId;

    taskController->createCourseTask(name, type, courseId, description, dueDate, weight);
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

void handleFilterByType(int type) {
    cout << "handleFilterByType" << endl;
    filterTaskController->filterTasksByType(type);
    filterTaskController->printTaskList();
}

void handleFilterByCourse() {
    cout << "handleFilterByCourse" << endl;
    vector<Course> courseList = subscriptionController->viewCurrentSubscriptions(userController->getCurrentUser());
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
}

void filterTasksByOneWeek() {
    filterTaskController->filterTasksByDate(7);
    filterTaskController->printTaskList();
}

void filterTasksByFuture() {
    filterTaskController->filterTasksByDate(9999);
    filterTaskController->printTaskList();
}

void filterTasksByOneMonth() {
    filterTaskController->filterTasksByDate(30);
    filterTaskController->printTaskList();
}

void handleViewAllTasks() {
    filterTaskController->findAllUserTasks();
    filterTaskController->printTaskList();
}


void handleDeleteTask(){

    int taskId;

    handleViewAllTasks();
    cout << "Enter the ID of the task to delete: ";
    cin >> taskId;

    if (taskController->deleteTask(taskId)) {
        cout << "Task deleted successfully!" << endl;
    }
    else {
        cout << "Error deleting task. Please try again." << endl;
    }

    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void handleEditTask(){
    int taskId;
    string name, description, dueDate;
    float weight;
    int type;

    // show all user tasks
    filterTaskController->filterTasksByType(10);
    filterTaskController->printTaskList();
    if (filterTaskController->getTaskList().size() > 0) {
        cout << "Enter the ID of the task to edit: ";
        cin >> taskId;
        Task task = taskController->getTaskInfo(taskId);
        // TODO: add check if task doesn't exist or if they enter a string
        // TODO: user should be able to choose which values they want to edit
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

        if (taskController->updateTask(userController->getCurrentUser(), taskId, name, description, dueDate, weight, type)) {
            cout << "Task edited successfully!" << endl;
        }
        else {
            cout << "Error editing task. Please try again." << endl;
        }
    } else {
        cout << "you can only edit personal tasks" << endl;
    }
    

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// course commands

// TODO: add error checking fot incorrect course or task ids
// TODO: add validation checking "are you sure" etc
void handleAddExistingTask() {
    cout << "handleAddExistingTask" << endl;

    int courseId, taskId;
    handleViewAllTasks();
    cout << "Enter Task Id for Task to be added: ";
    cin >> taskId;
    
    Task task = taskController->getTaskInfo(taskId);
    task.printTaskInfo();
    
    if (task.getTaskType() >= 10) {
        CommandHandler commandHandler;
        cout << "Choose Task Type" << endl;
        int type = commandHandler.manageChooseTaskType();
        task.setTaskType(type);
    }
    task.printTaskInfo();
    handleViewCourses();
    cout << "Which course would you like to add the task to?" << endl;
    cout << "Enter Course Id: ";
    cin >> courseId;

    task.setTaskOwner(courseId);
    courseController->addTask(task);
}

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

    vector<Course> courseList = courseController->getInstructorCourses(userController->getCurrentUser());
    printCourseList(courseList);
   
    cout << "Enter the ID of the course to delete: ";
    cin >> courseId;

    if (courseController->deleteCourse(courseId)) {
        cout << "Course deleted successfully!" << endl;
    }
    else {
        cout << "Error deleting course. Please try again." << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void handleEditCourse(){

    int courseId;
    string name, description, code;

    vector<Course> courseList = courseController->getInstructorCourses(userController->getCurrentUser());
    printCourseList(courseList);
    // TODO: user should be able to choose which values they want to edit
    cout << "Enter the ID of the course to edit: ";
    cin >> courseId;
    cout << "Enter the new course name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the new calendar description: ";
    cin.ignore();
    getline(cin, description);
    cout << "Enter the new course code: ";
    cin.ignore();
    getline(cin, code);


    if (courseController->editCourse(courseId, userController->getCurrentUser(), name, code, description)) {
        cout << "Course edited successfully!" << endl;
    }
    else {
        cout << "Error editing course. Please try again." << endl;
    }
}

// Displays a list of all courses (either subscribed to if a student or created if an instructor)
void handleViewCourses() {
    cout << "handling handleViewCourse()" << endl;

    if (userController->getCurrentUser() <= 1000) {
        // student
        vector<Course> courseList = subscriptionController->viewCurrentSubscriptions(userController->getCurrentUser());
        printCourseList(courseList);
    } else
    {
        // instructor
        vector<Course> courseList = courseController->getInstructorCourses(userController->getCurrentUser());
        printCourseList(courseList);
    }
    
}

void handleSubscribeCourse(){

    int courseCode;
    vector<Course> courseList = courseController->getAvailableCourses();
    printCourseList(courseList);

    cout << "which course do you want to subscribe to?" << endl;
    cout << "Enter the course id: ";
    cin >> courseCode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // TODO: add error checking on Course Code

    subscriptionController->addSubscription(courseCode, userController->getCurrentUser());
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
    int courseCode;

    vector<Course> courseList = subscriptionController->viewCurrentSubscriptions(userController->getCurrentUser());
    printCourseList(courseList);
    cout << "which course do you want to unsubscribe from?" << endl;
    cout << "Enter the courseId: " ;
    cin >> courseCode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    subscriptionController->removeSubscription(courseCode, userController->getCurrentUser());
}


void handleViewConsolidatedDeadlines() {
    int courseId, taskId;
    handleViewCourses();
    cout << "For which COURSE would you like to see the conflicting deadlines?" << endl;
    cout << "Enter CourseId: ";
    cin >> courseId;

    filterTaskController->filterTasksByCourse(courseId);
    filterTaskController->printTaskList();
    cout << "For which TASK would you like to see the conflicting deadlines?" << endl;
    cout << "Enter TaskId: ";
    cin >> taskId;



    // TODO: add error checking for courseID
    Task task = taskController->getTaskInfo(taskId);
    string date = task.getDueDate();
    list<AggregateDeadline> deadlines = courseController->aggregateDeadlines(courseId, date);
    printAggregateDeadlines(deadlines);
    cout << endl;

}



// TODO: Display Description
// TODO : implement viewing an individual course and showing description
void printCourseList(vector<Course> courseList) {
    int idWidth = 4;
    int instructorWidth = 20;
    int nameWidth = 43;
    int courseCode = 15;
    int descriptionWidth = 65;


    // Print the table headers
    cout << setw(idWidth) << "ID" << " | ";
    cout << setw(nameWidth) << "Course Name" << " | ";
    cout << setw(courseCode) << "Course Code" << " | ";
    cout << setw(instructorWidth) << "Instructor" << " | ";
    cout << setw(descriptionWidth) << "Description" << endl;

    // Print the separator
    cout << string(idWidth, '-') << "-+-";
    cout << string(nameWidth, '-') << "-+-";
    cout << string(courseCode, '-') << "-+-";
    cout << string(courseCode, '-') << "-+-";
    cout << string(descriptionWidth, '-') << endl;


    if (courseList.size() <= 0) {
        cout << endl << setw(idWidth+nameWidth) << "No Courses To Display" << endl;
    }
    // Print the table rows
    for (Course course : courseList) {
        string description = trimString(course.getCalendarDescription(), descriptionWidth);
        cout << setw(idWidth) << course.getCourseId() << " | ";
        cout << setw(nameWidth) << course.getCourseName() << " | ";
        cout << setw(courseCode) << course.getCourseCode() << " | ";
        cout << setw(instructorWidth) << getInstructorName(course.getInstructorId()) << " | ";
        cout << setw(descriptionWidth) << description << endl;
    }
}


/* 
* Written by chatGPT-3.5 by asking:
* in c++ how can I trim a string so that if it's longer than 50 chars I cut everything after that and add "..." to it
*/ 
string trimString(string str, int maxLength) {
    if (str.length() > maxLength) {
        str = str.substr(0, maxLength);
        str.append("...");
    }
    return str;
}

string getInstructorName(int id) {
    User instructor = userController->getUserInfo(id, "");
    return instructor.getName();
}

void printAggregateDeadlines(list<AggregateDeadline> deadlineList) {
    int typeWidth = 14;
    int dateWidth = 12;
    int courseWidth = 30;
    int studentsWidth = 18;

    // Print the table headers
    cout << setw(typeWidth) << "Type" << " | ";
    cout << setw(dateWidth) << "Due Date" << " | ";
    cout << setw(courseWidth) << "Course Name" << " | ";
    cout << setw(studentsWidth) << "Affected Students" << endl;

    // Print the separator
    cout << string(typeWidth, '-') << "-+-";
    cout << string(dateWidth, '-') << "-+-";
    cout << string(courseWidth, '-') << "-+-";
    cout << string(studentsWidth, '-') << endl;

    // Print the table rows
    if (deadlineList.size() <= 0) {
        cout << endl << setw(typeWidth+dateWidth+courseWidth+studentsWidth) << "No Deadlines To Display" << endl;
    } else {
        for (AggregateDeadline deadline : deadlineList) {
            cout << setw(typeWidth) << getTypeName(deadline.type) << " | ";
            cout << setw(dateWidth) << deadline.dueDate << " | ";
            cout << setw(courseWidth) << deadline.courseName << " | ";
            cout << setw(studentsWidth) << deadline.affectedStudents << endl;
        }
    }
}
// Note, this function is duplicated in task.cpp and should be refactored to avoid duplication
string getTypeName(int type) {
    switch (type) {
        case 0:
            return "Participation";
        case 1:
            return "Assignment";
        case 2:
            return "Project";
        case 3:
            return "Quiz";
        case 4:
            return "Test";
        case 5:
            return "Exam";
        default:
            return "Personal";

    }
}

