#include "student.hpp"

Student::Student(int studentId, string name, string password, string email, list<int> taskList)
    : User(name, password, email, taskList)
{
    this->studentId = studentId;
}
