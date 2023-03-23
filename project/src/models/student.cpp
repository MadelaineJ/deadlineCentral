#include "student.hpp"

Student::Student(int studentId, string name, string password, string email, list<int> taskList)
    : User(name, password, email, taskList)
{
    this->studentId = studentId;
}


int Student::getStudentId() {
    return this->studentId;
}

void Student::setStudentId(int studentId) {
    this->studentId = studentId;
}
