#ifndef USER_H
#define USER_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <list>

// Custom header files
#include "task.hpp"

using namespace std;


class User
{
    public:
        User(string name, string password, string email, list<Task> taskList);
        ~User();
        
        string getName();
        void setName(string name);

        string getPassword();
        void setPassword(string password);

        string getEmail();
        void setEmail(string email);

        list<Task> getTaskList();
        void setTaskList(list<Task> taskList);

    private:
        list<int> taskList;
    
    protected:
        string name;
        string password;
        string email;


};

#endif 