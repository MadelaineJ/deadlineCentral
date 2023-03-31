#include <iostream>
#include <list>
#include "task.hpp"


// Account
void handleViewAccount();
void handleUpdateAccount();
void handleDeleteAccount();
void handleCreateAccount();
void handleLogin();



// Task
void handleCreateTask();
void handleDeleteTask();
void handleEditTask();

void handleViewAllTasks();
void handleViewTask();
void handleSortTasks();
void handleviewAllTasks();

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