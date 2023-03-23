#ifndef STUDENT_H
#define STUDENT_H

#include "user.hpp"

class Student : public User
{
    private:
        int studentId;
    public:
        Student(int studentId, string name, string password, string email, list<int> taskList);
                
        int getStudentId();
        void setStudentId(int studentId);
};


#endif
