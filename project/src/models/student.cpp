#include "student.hpp"

Student::Student(string name, string password, string email, list<int> taskList)
    : User(name, password, email, taskList)
{
}
