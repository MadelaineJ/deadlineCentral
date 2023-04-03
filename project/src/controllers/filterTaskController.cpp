// custom header files
#include "subscriptionController.hpp"
#include "filterTaskController.hpp"
#include "courseController.hpp"
#include "userController.hpp"
#include "taskDb.hpp"
#include "course.hpp"

// required libraries
#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>


FilterTaskController *FilterTaskController::instance = nullptr; // initialize the static pointer

// returns a pointer to the single instance of FilterTaskController, if there is no instance it creates a new one
FilterTaskController* FilterTaskController::getInstance() {
    if(instance == nullptr) {
        instance = new FilterTaskController();
    }
    return instance;
}

// constructor is private to avoid multiple instances of FilterTaskController, instead use static method getInstance 
FilterTaskController::FilterTaskController() {}

// destructor
FilterTaskController::~FilterTaskController() {}

void FilterTaskController::findAllUserTasks() {
    int userId = userController->getCurrentUser();
    this->taskList = taskDb->getFilteredTasks(-1, -1, -1, -1, -1, userId);
}

void FilterTaskController::filterTasksByCourse(int courseId) {
    int userId = userController->getCurrentUser();
    this->taskList = taskDb->getFilteredTasks(-1, courseId, -1, -1, -1, userId);
}

void FilterTaskController::filterTasksByType(int type) {
    int userId = userController->getCurrentUser();
    this->taskList = taskDb->getFilteredTasks(type, -1, -1, -1, -1, userId);
}

void FilterTaskController::filterTasksByDate(int daysFuture) {
    int userId = userController->getCurrentUser();
    this->taskList = taskDb->getFilteredTasks(-1, -1, -1, 1, daysFuture, userId);
}

void FilterTaskController::filterTasksByDone(int done) {
    int userId = userController->getCurrentUser();
    this->taskList = taskDb->getFilteredTasks(-1, -1, done, -1, -1, userId);
}

void FilterTaskController::sortTasksByName() {
    this->toggleSortName(); 
    this->taskList.sort([this](Task task1, Task task2) {
        return this->compareTaskByName(task1, task2);
    });
    this->toggleSortOwner(); 
    this->toggleSortType();
    this->toggleSortDate();
    this->toggleSortWeight(); 
}
void FilterTaskController::sortTasksByOwner() {
    this->toggleSortOwner(); 
    this->taskList.sort([this](Task task1, Task task2) {
        return this->compareTaskByOwner(task1, task2);
    });
    this->toggleSortName();
    this->toggleSortType();
    this->toggleSortDate();
    this->toggleSortWeight(); 
}
void FilterTaskController::sortTasksByType() {
    this->toggleSortType(); 
    this->taskList.sort([this](Task task1, Task task2) {
        return this->compareTaskByType(task1, task2);
    });
    this->toggleSortName();
    this->toggleSortOwner();
    this->toggleSortDate();
    this->toggleSortWeight();
}
void FilterTaskController::sortTasksByDate() {
    this->toggleSortDate(); 
    this->taskList.sort([this](Task task1, Task task2) {
        return this->compareTaskByDate(task1, task2);
    });
    this->toggleSortName();
    this->toggleSortOwner();
    this->toggleSortType(); 
    this->toggleSortWeight();
}

void FilterTaskController::sortTasksByWeight() {
    this->toggleSortWeight(); 
    int userId = userController->getCurrentUser();
    this->taskList.sort([this](Task task1, Task task2) {
        return this->compareTaskByWeight(task1, task2);
    });
    this->toggleSortName();
    this->toggleSortOwner();
    this->toggleSortType(); 
    this->toggleSortDate();
}

// sort toggle getters and setters
void FilterTaskController::toggleSortName() {
    this->sortName = !this->sortName;
}
void FilterTaskController::toggleSortOwner() {
    this->sortOwner = !this->sortOwner;
}
void FilterTaskController::toggleSortType() {
    this->sortType = !this->sortType;
}
void FilterTaskController::toggleSortDate() {
    this->sortDate = !this->sortDate;
}
void FilterTaskController::toggleSortWeight() {
    this->sortWeight = !this->sortWeight;
}

bool FilterTaskController::getSortName() {
    return this->sortName;
}
bool FilterTaskController::getSortOwner() {
    return this->sortOwner;
}
bool FilterTaskController::getSortType() {
    return this->sortType;
}
bool FilterTaskController::getSortDate() {
    return this->sortDate;
}
bool FilterTaskController::getSortWeight() {
    return this->sortWeight;
}


// comparison helper functions
bool FilterTaskController::compareTaskByName(Task task1, Task task2) {
    if (this->getSortName()) {    
        return task1.getTaskName() > task2.getTaskName();  
    } else {
        return task1.getTaskName() < task2.getTaskName();
    }
}

bool FilterTaskController::compareTaskByOwner(Task task1, Task task2) {
UserController *userController = UserController::getInstance();
CourseController *courseController = CourseController::getInstance();

    //get owner name instead of id
    string owner1, owner2;
    if (task1.getTaskType() >= 10) {
        //personal task
        owner1 = userController->getUserInfo(task1.getTaskOwner(), "").getName();
    } else {
        owner1 = courseController->getCourseInfo(task1.getTaskOwner()).getCourseName();
    }

    if (task2.getTaskType() >= 10) {
        owner2 = userController->getUserInfo(task2.getTaskOwner(), "").getName();  
    } else {
        owner2 = courseController->getCourseInfo(task2.getTaskOwner()).getCourseName();
    }

    if (this->getSortOwner()) {
        return owner1 > owner2;    
    } else {
        return owner1 < owner2;
    }
}
bool FilterTaskController::compareTaskByType(Task task1, Task task2) {
    if (this->getSortType()) {
        return task1.getTypeName() > task2.getTypeName();    
    } else {
        return task1.getTypeName() < task2.getTypeName();
    }

}
bool FilterTaskController::compareTaskByDate(Task task1, Task task2) {
    if (this->getSortDate()) {
        return task1.getDueDate() > task2.getDueDate();
    } else {
        return task1.getDueDate() < task2.getDueDate();
    }
}

bool FilterTaskController::compareTaskByWeight(Task task1, Task task2) {
    if (this->getSortWeight()) {
        return task1.getWeight() > task2.getWeight();
    } else {
        return task1.getWeight() < task2.getWeight();
    }
}

void FilterTaskController::printTaskList() {
    printf("\033[2J\033[H");
    int idWidth = 2;
    int nameWidth = 25;
    int typeWidth = 13;
    int ownerWidth = 43;
    int descriptionWidth = 50;
    int dueDateWidth = 10;
    int completionWidth = 9;
    int weightWidth = 8;

    // Todo: decide if this chunk of code is worth the speed loss
    // Calculate the maximum width of each column
    // for (Task task : taskList) {
    //     idWidth = max(idWidth, (int)to_string(task.getTaskId()).length());
    //     nameWidth = max(nameWidth, (int)task.getTaskName().length());
    //     typeWidth = max(typeWidth, (int)task.getTypeName().length());
    //     ownerWidth = max(ownerWidth, (int)getCourseOwnerName(task.getTaskOwner(), task.getTaskType()).length());
    //     descriptionWidth = max(descriptionWidth, (int)task.getTaskDescription().length());
    //     dueDateWidth = max(dueDateWidth, (int)task.getDueDate().length());
    //     completionWidth = max(completionWidth, (int)to_string(task.getCompletionStatus()).length());
    //     weightWidth = max(weightWidth, (int)to_string(task.getWeight()).length());
    // }

    // Print the table headers
    cout << setw(idWidth) << "ID" << " | ";
    cout << setw(nameWidth) << "Name" << " | ";
    cout << setw(typeWidth) << "Type" << " | ";
    cout << setw(ownerWidth) << "Course" << " | ";
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
    for (Task task : this->taskList) {
        cout << setw(idWidth) << task.getTaskId() << " | ";
        cout << setw(nameWidth) << task.getTaskName() << " | ";
        cout << setw(typeWidth) << task.getTypeName() << " | ";
        cout << setw(ownerWidth) << getCourseOwnerName(task.getTaskOwner(), task.getTaskType()) << " | ";
        cout << setw(descriptionWidth) << task.getTaskDescription() << " | ";
        cout << setw(dueDateWidth) << task.getDueDate() << " | ";
        cout << setw(completionWidth) << (task.getCompletionStatus() ? "Yes" : "No") << " | ";
        cout << setw(weightWidth) << task.getWeight() << endl;
    }
}

// TODO: improve the speed of this function
    string FilterTaskController::getCourseOwnerName(int owner, int type) {
    if (type >= 10) {
        return this->userController->getUserInfo(owner, "").getName();
    } else {
        return this->courseController->getCourseInfo(owner).getCourseName();
    }
}


