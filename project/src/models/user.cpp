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

//TODO write print for task list
void User::printUserInfo() {
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
//    cout << "Task List: " << taskList << endl;
}

bool User::compare(User otherUser) {
    if (this->getName() != otherUser.getName()) return false;
    if (this->getEmail() != otherUser.getEmail()) return false;
    if (this->getPassword() != otherUser.getPassword()) return false;
    if (this->getTaskList() != otherUser.getTaskList()) return false;
    return true;
}
