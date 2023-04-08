// Custom Header files
#include "instructor.hpp"

Instructor::Instructor(int instructorId, string name, string password, string email, list<int> taskList)
    : User(instructorId, name, password, email, taskList)
{
    this->instructorId = instructorId;
}


int Instructor::getInstructorId() {
    return this->instructorId;
}

void Instructor::setInstructorId(int instructorId) {
    this->instructorId = instructorId;
}
