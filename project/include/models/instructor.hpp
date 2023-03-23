#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "user.hpp"

class Instructor : public User
{
    private:
        int instructorId;
    public:
        Instructor(int instructorId, string name, string password, string email, list<int> taskList);
};

#endif
