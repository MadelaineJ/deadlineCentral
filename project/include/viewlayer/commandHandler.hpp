#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

// Required Libraries
#include <iostream>
#include <string>

// custom header files

using namespace std;


class CommandHandler 
{
    public:
        CommandHandler(){}
        ~CommandHandler(){}
        
        int getUserInput();

        // printed menus
        void mainMenu();
        void accountMenu();
        void taskMenu();
        void courseMenu();

        // menu input handlers
        void manageMain();
        void manageAccount();
        void manageTask();
        void manageCourse();

    private:
};

#endif
