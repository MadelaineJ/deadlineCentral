#include "user.hpp"

User::User(string name, string password, string email, list<int> taskList)
{
    this->name = name;
    this->password = password;
    this->email = email;
    this->taskList = taskList;
}
