// Required Libraries
#include <iostream>
#include <termios.h>
#include <unistd.h>

// Custom header files
#include "task.hpp" 

using namespace std;

// constructor
Task::Task(int taskId, string name, int type, int owner, string description, string dueDate, bool isCompleted, float weight)
{
    this->taskId = taskId;
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
string Task::getDueDate() {
    return this->dueDate;
}

// setDueDate
void Task::setDueDate(string dueDate) {
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
    return this->taskId;
}

// setTaskId
void Task::setTaskId(int taskId) {
    this->taskId = taskId;
}

void Task::printTaskInfo() {
    cout << "Task ID: " << taskId << endl;
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "Owner: " << owner << endl;
    cout << "Description: " << description << endl;
    cout << "Due Date: " << dueDate << endl;
    cout << "Completion Status: " << isCompleted << endl;
    cout << "Weight: " << weight << endl;
}

bool Task::compare(Task otherTask) {
    if (this->getTaskId() != otherTask.getTaskId()) {
        return false;
    }
    if (this->getTaskName() != otherTask.getTaskName()) {
        return false;
    }
    if (this->getTaskType() != otherTask.getTaskType()) {
        return false;
    }
    if (this->getTaskOwner() != otherTask.getTaskOwner()) {
        return false;
    }
    if (this->getTaskDescription() != otherTask.getTaskDescription()) {
        return false;
    }
    if (this->getDueDate() != otherTask.getDueDate()) {
        return false;
    }
    if (this->getCompletionStatus() != otherTask.getCompletionStatus()) {
        return false;
    }
    if (this->getWeight() != otherTask.getWeight()) {
        return false;
    }
    return true;
}

std::ostream& operator<< (std::ostream& out, const Task& t)
{
    out << "Task: " << t.taskId << " " << t.name << " " << t.type << " " << t.owner << " " << t.description \
        << " " << t.dueDate << " " << t.isCompleted << " " << t.weight;
    return out;
}


string Task::getTypeName() {
    switch (this->type) {
        case 0:
            return "participation";
        case 1:
            return "assignment";
        case 2:
            return "project";
        case 3:
            return "quiz";
        case 4:
            return "test";
        case 5:
            return "exam";
        default:
            return "personal";

    }
}
