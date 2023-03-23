#ifndef STUDENT_H
#define STUDENT_H

#include "user.hpp"

class Student : public User
{
    public:
        Student(string name, string password, string email, list<int> taskList);
};

#endif
