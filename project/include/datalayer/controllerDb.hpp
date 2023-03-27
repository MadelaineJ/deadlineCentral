#ifndef CONTROLLER_DB_H
#define CONTROLLER_DB_H

// Connection information
#define USERNAME "team1"
#define PASSWORD "teamwon1"
#define CONNECTION_STRING "192.168.18.58:1539/XEPDB1"

// Required Libraries
#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>

using namespace std;
using namespace oracle::occi;

class ControllerDb 
{
    public:
        static ControllerDb* getInstance(); // gets the single instance of this class
        ~ControllerDb();
        string connect();
        string disconnect();
        void sendQuery(string query);

        Connection* getConnection();
        Statement* getStatement();

    private:
        ControllerDb(); // pvt to prevent direct instanciation
        static ControllerDb* instance; // Pointer to the single instance of ControllerDb

        Environment *environment;
        Connection *connection;
        Statement *stmt;
        string connectString;
        string username;
        string password;
};

#endif // CONTROLLER_DB_H