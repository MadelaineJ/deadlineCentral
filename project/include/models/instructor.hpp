#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

// custom header files
#include "user.hpp"

class Instructor : public User
{
    private:
        int instructorId;
    public:
        Instructor(int instructorId, string name, string password, string email, list<int> taskList);

        int getInstructorId();
        void setInstructorId(int InstructorId);
};

#endif
