#include "instructor.hpp"

Instructor::Instructor(int InstructorId, string name, string password, string email, list<int> taskList)
    : User(name, password, email, taskList)
{
    this->instructorId = InstructorId;
}
