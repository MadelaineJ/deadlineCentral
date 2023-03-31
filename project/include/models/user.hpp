#ifndef USER_HPP
#define USER_HPP

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
        User(int userId, string name, string password, string email, list<int> taskList);
        
        string getName();
        void setName(string name);

        string getPassword();
        void setPassword(string password);

        string getEmail();
        void setEmail(string email);

        list<int> getTaskList();
        void setTaskList(list<int> taskList);

        int getUserId();
        void setUserId(int userId);

        void printUserInfo();

        bool compare(User otherUser);

    private:
        list<int> taskList;
    
    protected:
        int userId;
        string name;
        string password;
        string email;


};

#endif 
