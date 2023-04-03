#include <iostream>
#include <list>
#include "task.hpp"


// Account
void handleViewAccount();
void handleUpdateAccount();
void handleDeleteAccount();
void handleCreateAccount(int userType);
void handleLogin();



// Task
void handleCreateTask();
void handleDeleteTask();
void handleEditTask();

void handleViewAllTasks();
void handleViewTask();

void handleSortTasks();
void handleSortByWeight();
void handleSortByName();
void handleSortByType();

void handleFilterTasks();
void handleFilterByType(int type);
void handleFilterByCourse();

// Course
void handleCreateCourse();
void handleDeleteCourse();
void handleEditCourse();
void handleViewCourse();

void handleSubscribeCourse();
void handleUnsubscribeCourse();



// extra
void handleViewConsolidatedDeadlines();


// helper functions

void printTaskList(const list<Task>& taskList);