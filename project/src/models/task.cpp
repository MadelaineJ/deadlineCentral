// Required Libraries
#include <iostream>
#include <termios.h>
#include <unistd.h>

// Custom header files
#include "task.hpp" 

using namespace std;

// constructor
Task::Task(int taskId, string name, int type, int owner, string description, time_t dueDate, bool isCompleted, float weight)
{
    this->name = name;
    this->type = type;
    this->owner = owner;
    this->description = description;
    this->dueDate = dueDate;
    this->isCompleted = isCompleted;
    this->weight = weight;
}

// destructor
Task::~Task() { }

// getTaskName
string Task::getTaskName() {
    return this->name;
}

// setTaskName
void Task::setTaskName(string name) {
    this->name = name;
}

// getTaskType
int Task::getTaskType() {
    return this->type;
}

// setTaskType
void Task::setTaskType(int type) {
    this->type = type;
}

// getTaskOwner
int Task::getTaskOwner() {
    return this->owner;
}

// setTaskOwner
void Task::setTaskOwner(int owner) {
    this->owner = owner;
}

// getTaskDescription
string Task::getTaskDescription() {
    return this->description;
}

// setTaskDescription
void Task::setTaskDescription(string description) {
    this->description = description;
}

// getDueDate
time_t Task::getDueDate() {
    return this->dueDate;
}

// setDueDate
void Task::setDueDate(time_t dueDate) {
    this->dueDate = dueDate;
}

// getCompletionStatus
bool Task::getCompletionStatus() {
    return this->isCompleted;
}

// setCompletionStatus
void Task::setCompletionStatus(bool isCompleted) {
    this->isCompleted = isCompleted;
}

// getWeight
float Task::getWeight() {
    return this->weight;
}

// setWeight
void Task::setWeight(float weight) {
    this->weight = weight;
}

// getTaskId
int Task::getTaskId() {
    return taskId;
}

// setTaskId
void Task::setTaskId(int taskId) {
    this->taskId = taskId;
}

