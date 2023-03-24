#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

// Required Libraries
#include <iostream>
#include <string>

// custom header values
#include "taskDb.hpp"

using namespace std;


class CommandHandler 
{
    public:
        CommandHandler(){}
        ~CommandHandler(){}
        
        void parseInput(string input);
        void handleViewTask(string taskId);
    private:
        TaskDB taskDb;
};

#endif
