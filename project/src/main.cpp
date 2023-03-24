// Custom Header files
// #include "controllerDb.hpp"
// #include "view.hpp"
// #include "student.hpp"
#include "courseController.hpp"
#include "commandHandler.hpp"
// Required Libraries
#include <iostream>
#include <string>
#include <list>


using namespace std;

int main() {

    CommandHandler commandHandler;
    cout << "enter command\n>>>";
    string userInput;
    getline(cin, userInput);
    commandHandler.parseInput(userInput);
}
