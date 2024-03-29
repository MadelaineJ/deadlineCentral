#include <iostream>
#include <list>
#include <vector>
#include "task.hpp"
#include "course.hpp"
#include "aggregateDeadline.hpp"


// Account handlers
void handleViewAccount();
void handleUpdateAccount();
void handleDeleteAccount();
void handleCreateAccount(int userType);
void handleLogin();
void handleLogout();

// Task Handlers
void handleCreateTask();
void handleDeleteTask();
void handleEditTask();

// task viewing
void handleViewAllTasks();
void handleViewTask();

// task sorting
void handleSortTasks();
void handleSortByWeight();
void handleSortByName();
void handleSortByType();
void handleSortByDate();
void handleSortByOwner();

// Task filtering
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


// Helper functions
int chooseCourse(vector<Course> courseList);
int chooseTask(vector<Task> taskList);
bool dateValidator(string date);


// display formating helper functions
string trimString(string str, int maxLength);
void printCourseList(vector<Course> courseList);
string getInstructorName(int id);
void printTaskList(const list<Task>& taskList);
string getCourseOwnerName(int owner, int type);
void printAggregateDeadlines(list<AggregateDeadline> deadlineList);
string getTypeName(int type);