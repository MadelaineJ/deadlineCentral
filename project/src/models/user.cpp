#include "user.hpp"

User::User(string name, string password, string email, list<int> taskList)
{
    this->name = name;
    this->password = password;
    this->email = email;
    this->taskList = taskList;
}

string User::getName() {
    return name;
}

void User::setName(string name) {
    this->name = name;
}

string User::getPassword() {
    return password;
}

void User::setPassword(string password) {
    this->password = password;
}

string User::getEmail() {
    return email;
}

void User::setEmail(string email) {
    this->email = email;
}

list<int> User::getTaskList() {
    return taskList;
}

void User::setTaskList(list<int> taskList) {
    this->taskList = taskList;
}

