#include <iostream>

using namespace std;


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
void handleLogin(){
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

void handleViewAllTasks() {
    cout << "handling handleViewAllTasks()" << endl;
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
