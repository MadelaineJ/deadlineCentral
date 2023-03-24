#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
// custom header files
#include "commandHandler.hpp"
#include "task.hpp"
#include "taskDb.hpp"


using namespace std;

// constructor
// CommandHandler::CommandHandler()
// {
// }

// // destructor
// CommandHandler::~CommandHandler() { }


void CommandHandler::parseInput(string input) {

//     else if (command.find(FTP_CLIENT_USER_COMMAND_USER) == 0){
//       handleCommandUser(command.substr(strlen(FTP_CLIENT_USER_COMMAND_USER) + 1), clientFtpSession, serverResponse);
//    } 
    if (input.find("vt") == 0) {
        string taskId = input.substr(strlen("vt") + 1);
        this->handleViewTask(taskId);
    }
}
void CommandHandler::handleViewTask(string taskId) {
   // Task task(taskId, "best task", 10, 123, "best task", "", true, 50);
    Task task = taskDb.getTaskInfo(taskId);
    task.printTaskInfo();


}