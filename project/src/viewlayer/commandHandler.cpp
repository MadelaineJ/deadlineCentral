#include <iostream>

// custom header files
#include "commandHandler.hpp"
#include "../models/task.hpp"
#include <ctime>

using namespace std;

// constructor
// CommandHandler::CommandHandler()
// {
// }

// // destructor
// CommandHandler::~CommandHandler() { }


void CommandHandler::parseInput(string input) {
    if (input == "vt") {
        handleTaskCommand();
    }
}
void CommandHandler::handleTaskCommand() {
    cout << "hi" << endl;
    Task task("best task", 10, 123, "best task", time(NULL), true, 50);
    cout <<  task.getTaskName() << endl;

}