#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

// Required Libraries
#include <iostream>
#include <string>
using namespace std;


class CommandHandler 
{
    public:
        CommandHandler(){}
        ~CommandHandler(){}
        
        void parseInput(string input);
        void handleTaskCommand();
};

#endif
