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

// TODO: implement ability to change password (have to deal with re-hashing it)
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
    cout << "Warning, this cannot be undone" << endl;
    cout << "Are you sure you want to delete your account? (y/n): ";

    string answer;
    cin >> answer;
    if (answer == "y") {
        cout << "This may take a moment. Please wait..." << endl;
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


void handleLogout() {
    userController->setCurrentUser(-1);
    cout << "You have been logged out" << endl;
}

// Task commands
// Creates a personal Task
void handleCreateTask(){
    string name, description, dueDate;
    double weight;

    cout << "Enter the new task name: ";
    getline(cin, name);
    cout << "Enter the task description: ";
    getline(cin, description);

    bool validDate = false;
    while (!validDate) {
        cout << "Enter the task due date (MM/DD/YYYY): ";
        getline(cin, dueDate);      
        if (dateValidator(dueDate)) {
            validDate = true;
        } else {
            cout << "Error: Invalid Date Format. Please Try Again" << endl;
        }
    }

    cout << "Enter the task weight (as a decimal): ";
    cin >> weight;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (taskController->createUserTask(userController->getCurrentUser(), name, description, dueDate, weight)) 
    {
        cout << "Successfully Create task: '" << name << "'" << endl;
    } else {
        cout << "Error Creating task: '" << name << "'" << endl;
        cout << "Please Try again" << endl;
    }

}


void handleCreateCourseTask() {
    
    string name, description, dueDate;
    double weight;
    int type, courseId;
    
    cout << "Enter the task name: ";
    getline(cin, name);
    cout << "Enter the task description: ";
    getline(cin, description);

    bool validDate = false;
    while (!validDate) {
        cout << "Enter the task due date (MM/DD/YYYY): ";
        getline(cin, dueDate);      
        if (dateValidator(dueDate)) {
            validDate = true;
        } else {
            cout << "Error: Invalid Date Format. Please Try Again" << endl;
        }
    }

    cout << "Enter the task weight (as a decimal): ";
    cin >> weight;
            
    cout << "Choose Task Type" << endl;
    CommandHandler commandHandler;
    type = commandHandler.manageChooseTaskType();
    cout << "Which course would you like to add the task to?" << endl;
    vector<Course> courseList = courseController->getInstructorCourses(userController->getCurrentUser());
    if(courseList.size() != 0) {
        courseId = chooseCourse(courseList);    
    } else {
        cout << "You have no courses to add the task to" << endl;
        cout << "You can create a course in the course menu" << endl;
    }

    if (taskController->createCourseTask(name, type, courseList[courseId].getCourseId(), description, dueDate, weight)) {
        cout << "Successfully added task: '" << name << "' to course: '" << courseList[courseId].getCourseName() << "'" << endl;
    } else {
        cout << "Error adding task: '" << name << "' to course: '" << courseList[courseId].getCourseName() << "'" << endl;
        cout << "Please Try again" << endl;
    }
    
}

void handleSortByWeight() {
    filterTaskController->sortTasksByWeight();
    filterTaskController->printTaskList();
}
void handleSortByName() {
    filterTaskController->sortTasksByName();
    filterTaskController->printTaskList();
}
void handleSortByType() {
    filterTaskController->sortTasksByType();
    filterTaskController->printTaskList();
}

void handleSortByDate() {
    cout << "handleSortByDate" << endl;
    filterTaskController->sortTasksByDate();
    filterTaskController->printTaskList();
}
void handleSortByOwner() {
    filterTaskController->sortTasksByOwner();
    filterTaskController->printTaskList();
}

void handleFilterByType(int type) {
    filterTaskController->filterTasksByType(type);
    filterTaskController->printTaskList();
}

void handleFilterByCourse() {
    vector<Course> courseList;
    int courseId;
    if (userController->getCurrentUser() > 1000) {
        courseList = courseController->getInstructorCourses(userController->getCurrentUser());
    } else {
        courseList = subscriptionController->viewCurrentSubscriptions(userController->getCurrentUser());
    }

    if (courseList.size() != 0) {
        courseId = chooseCourse(courseList);
    } else {
        if (userController->getCurrentUser() > 1000) {
            cout << "You have no courses to filter by" << endl;
        } else {
            cout << "You are not subscribed to any courses" << endl;
        }
    }
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
    cout << "Enter the ID of the task to delete: " << endl;
    list<Task> tasks = filterTaskController->getTaskList();
    vector<Task> taskList = vector<Task>(tasks.begin(), tasks.end());
    if (taskList.size() != 0) {
        cout << "Which Task would you like to Delete?" << endl;
        taskId = chooseTask(taskList);
    } else {
        cout << "You haven no courses" << endl;
    }

    if (taskController->deleteTask(taskId)) {
        cout << "Task deleted successfully!" << endl;
    }
    else {
        cout << "Error deleting task. Please try again." << endl;
    }
}

void handleEditTask(){
    int taskId;
    string name, description, dueDate;
    float weight;
    int type;

    // show all user tasks
    if (userController->getCurrentUser() > 1000) {
        filterTaskController->findAllUserTasks();
    } else {
        // studnets can only edit personal tasks
        filterTaskController->filterTasksByType(10);
    }
    
    filterTaskController->printTaskList();
    list<Task> tasks = filterTaskController->getTaskList();
    vector<Task> taskList = vector<Task>(tasks.begin(), tasks.end());
    if (filterTaskController->getTaskList().size() > 0) {
        cout << "Enter the ID of the task to edit: " << endl;
        taskId = chooseTask(taskList);

        Task task = taskController->getTaskInfo(taskId);
        type = task.getTaskType();
        // TODO: add check if task doesn't exist or if they enter a string
        // TODO: user should be able to choose which values they want to edit
        cout << "Enter the new task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the new task description: ";
        getline(cin, description);
        bool validDate = false;
        while (!validDate) {
            cout << "Enter the task due date (MM/DD/YYYY): ";
            getline(cin, dueDate);      
            if (dateValidator(dueDate)) {
                validDate = true;
            } else {
                cout << "Error: Invalid Date Format. Please Try Again" << endl;
            }
        }
        cout << "Enter the new task weight (as a decimal): ";
        cin >> weight;
        if (task.getTaskType() != 10) {
            CommandHandler commandHandler;
            cout << "Choose Task Type" << endl;
            type = commandHandler.manageChooseTaskType();
        } 


        if (taskController->updateTask(userController->getCurrentUser(), taskId, name, description, dueDate, weight, type)) {
            cout << "Task edited successfully!" << endl;
        }
        else {
            cout << "Error editing task. Please try again." << endl;
        }
    } else {
        cout << "You have no Tasks to Edit" << endl;
    }
}

// course commands
// TODO: add error checking fot incorrect course or task ids
// TODO: add validation checking "are you sure" etc
void handleAddExistingTask() {
    cout << "handleAddExistingTask" << endl;

    int courseId, taskId;
    handleViewAllTasks();
    cout << "Which Task would you like to add?" << endl;
    list<Task> tasks = filterTaskController->getTaskList();
    vector<Task> taskList = vector<Task>(tasks.begin(), tasks.end());

    // Choose Task
    if (taskList.size() != 0) {
        taskId = chooseTask(taskList);
    } else {
        cout << "You have no existing tasks" << endl;
    }

    Task task = taskController->getTaskInfo(taskId);
    task.printTaskInfo();

    // If it was a personal Task then choose task type
    if (task.getTaskType() >= 10) {
        CommandHandler commandHandler;
        cout << "Choose Task Type" << endl;
        int type = commandHandler.manageChooseTaskType();
        task.setTaskType(type);
    }
    // Choose course
    cout << "Which course would you like to add the task to?" << endl;
    vector<Course> courseList = courseController->getInstructorCourses(userController->getCurrentUser());
    if (courseList.size() != 0) {
        courseId = chooseCourse(courseList);
    } else {
        cout << "You have no courses to delete" << endl;
    }

    if (taskController->createCourseTask(task.getTaskName(), task.getTaskType(), courseId, 
        task.getTaskDescription(), task.getDueDate(), task.getWeight())) 
    {
        cout << "Successfully added task: '" << task.getTaskName() << "' to course: '" << courseList[courseId].getCourseName() << "'" << endl;
    } else {
        cout << "Error adding task: '" << task.getTaskName() << "' to course: '" << courseList[courseId].getCourseName() << "'" << endl;
        cout << "Please Try again" << endl;
    }
}

void handleCreateCourse(){
    string name, description, code;

    cout << "Enter the course name: ";
    getline(cin, name);
    cout << "Enter the calendar description: ";
    getline(cin, description);
    cout << "Enter the course code: ";
    getline(cin, code);

    if (courseController->createCourse(name, description, code, userController->getCurrentUser())) {
        cout << "Course created successfully!" << endl;
    }
    else {
        cout << "Error creating course. Please try again." << endl;
    }
}

void handleDeleteCourse(){
    int courseId;
    
    cout << "Choose the course to delete" << endl;
    vector<Course> courseList = courseController->getInstructorCourses(userController->getCurrentUser());
    if (courseList.size() != 0) {
        courseId = chooseCourse(courseList);
    } else {
        cout << "You have no courses to delete" << endl;
    }

    if (courseController->deleteCourse(courseId, userController->getCurrentUser())) {
        cout << "Course deleted successfully!" << endl;
    }
    else {
        cout << "Error deleting course. Please try again." << endl;
    }
}


void handleEditCourse(){

    int courseId;
    string name, description, code;

    vector<Course> courseList = courseController->getInstructorCourses(userController->getCurrentUser());
    if (courseList.size() != 0) {
        courseId = chooseCourse(courseList);
    } else {
        cout << "You have no courses to edit" << endl;
    }

    // TODO: user should be able to choose which values they want to edit
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the new course name: ";
    getline(cin, name);
    cout << "Enter the new calendar description: ";
    getline(cin, description);
    cout << "Enter the new course code: ";
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

    int courseId;
    cout << "Which course do you want to subscribe to?" << endl;

    vector<Course> courseList = subscriptionController->viewAvailableSubscriptions(userController->getCurrentUser());
    if (courseList.size() != 0) {
        courseId = chooseCourse(courseList);
    } else {
        cout << "There are Currently no Courses to Subscribe to" << endl;
    }

    // TODO: add error checking on Course Code
    if (subscriptionController->addSubscription(courseId, userController->getCurrentUser())) {
        cout << "Subscribed to course successfully!" << endl;
    }
    else {
        cout << "Error subscribing to course. Please try again." << endl;
    }
}

void handleUnsubscribeCourse(){
    int courseId;
    cout << "which course do you want to unsubscribe from?" << endl;
    // let user choose course
    vector<Course> courseList = subscriptionController->viewCurrentSubscriptions(userController->getCurrentUser());
    if (courseList.size() != 0) {
        courseId = chooseCourse(courseList);
    } else {
        cout << "There are Currently no Courses to Subscribe to" << endl;
    }

    // Validate that the subscription was removed
    if (subscriptionController->removeSubscription(courseId, userController->getCurrentUser())) {
        cout << "Unsubscribed from course successfully!" << endl;
    }
    else {
        cout << "Error unsubscribing from course. Please try again." << endl;
    }

}

void handleViewConsolidatedDeadlines() {
    int courseId, taskId;
    cout << "For which COURSE would you like to see the conflicting deadlines?" << endl;
    vector<Course> courseList = courseController->getInstructorCourses(userController->getCurrentUser());
    if (courseList.size() != 0) {
        courseId = chooseCourse(courseList);
    } else {
        cout << "You have no courses" << endl;
    }

    filterTaskController->filterTasksByCourse(courseId);
    filterTaskController->printTaskList();
    list<Task> tasks = filterTaskController->getTaskList();
    vector<Task> taskList = vector<Task>(tasks.begin(), tasks.end());
    cout << "For which TASK would you like to see the conflicting deadlines?" << endl;
    if (taskList.size() != 0) {
        taskId = chooseTask(taskList);
    } else {
        cout << "This course has no tasks to filter by" << endl;
    }

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
    cout << setw(nameWidth) << "Course Name" << " | ";
    cout << setw(courseCode) << "Course Code" << " | ";
    cout << setw(instructorWidth) << "Instructor" << " | ";
    cout << setw(descriptionWidth) << "Description" << endl;

    // Print the separator
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
        cout << setw(nameWidth) << course.getCourseName() << " | ";
        cout << setw(courseCode) << course.getCourseCode() << " | ";
        cout << setw(instructorWidth) << getInstructorName(course.getInstructorId()) << " | ";
        cout << setw(descriptionWidth) << description << endl;
    }
}

// HELPER FUNCTIONS

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

int chooseCourse(vector<Course> courseList) {
    int courseId;
    if(courseList.size() != 0) {
        cout << "==== Choose Course ====" << endl;
        for (int i = 0; i < courseList.size(); i++) {
            cout << i+1 << ". " << courseList[i].getCourseName() << endl;
        }
        bool validInput = false;

        while (!validInput) {
            cout << "==== Enter Course Number ====" << endl;
            cout << ">>> "; 
            cin >> courseId;
            if ((courseId < courseList.size()+1) && (courseId > 0)) {
                validInput = true;
            } else if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice, please try again" << endl;
            } else {
                cout << "Invalid choice, please try again" << endl;
            }
        }      
    }
    return courseList[courseId-1].getCourseId();
}

int chooseTask(vector<Task> taskList) {
    int taskId;
    if(taskList.size() != 0) {
        cout << "==== Choose Task ====" << endl;
        for (int i = 0; i < taskList.size(); i++) {
            cout << i+1 << ". " << taskList[i].getTaskName() << endl;
        }
        bool validInput = false;

        while (!validInput) {
            cout << "==== Enter Task Number ====" << endl;
            cout << ">>> "; 
            cin >> taskId;
            if (((taskId < taskList.size()+1) && (taskId > 0))) {
                validInput = true;
            } else if (cin.fail()) { // if they didn't enter an int
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');                
                cout << "Invalid choice, please try again" << endl;
            } else {
                cout << "Invalid choice, please try again" << endl;
            }
        }          
    }
    return taskList[taskId-1].getTaskId();
}

// Returns true if the user entered date is in the correct format, false otherwise
bool dateValidator(string date) {
    regex dateRegex("^(0[1-9]|1[0-2])/([0-2][0-9]|3[0-1])/\\d{4}$");
    if(regex_match(date, dateRegex)) {
        return true;
    } else {
        return false;
    }
}
