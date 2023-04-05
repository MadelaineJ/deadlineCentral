#include <iostream>
#include <list>
#include <vector>
#include "task.hpp"
#include "course.hpp"
#include "aggregateDeadline.hpp"


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
void handleSortByDate();
void handleSortByOwner();

void handleFilterTasks();
void handleFilterByType(int type);
void handleFilterByCourse();
void filterTasksByOneWeek();
void filterTasksByFuture();
void filterTasksByOneMonth();

// Course
void handleCreateCourse();
void handleDeleteCourse();
void handleEditCourse();
void handleViewCourses();
void handleCreateCourseTask();
void handleAddExistingTask();

void handleSubscribeCourse();
void handleUnsubscribeCourse();


void handleViewConsolidatedDeadlines();


// display formating helper functions
void printCourseList(vector<Course> courseList);
string getInstructorName(int id);
void printTaskList(const list<Task>& taskList);
string getCourseOwnerName(int owner, int type);
void printAggregateDeadlines(list<AggregateDeadline> deadlineList);
string getTypeName(int type);