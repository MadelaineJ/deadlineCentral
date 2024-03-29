// Custom Header files
#include "student.hpp"

Student::Student(int studentId, string name, string password, string email, list<int> taskList)
    : User(studentId, name, password, email, taskList)
{
    this->studentId = studentId;
}


int Student::getStudentId() {
    return this->studentId;
}

void Student::setStudentId(int studentId) {
    this->studentId = studentId;
}

std::ostream& operator<< (std::ostream& out, const Student& stu)
{
    out << "Student(" << stu.studentId <<')';

    return out;
}
