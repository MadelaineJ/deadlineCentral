#ifndef CONTROLLER_DB_H
#define CONTROLLER_DB_H

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
        ControllerDb();
        ~ControllerDb();
        string connect();
        string disconnect();
        void sendQuery(string query);

    private:
        Environment *environment;
        Connection *connection;
        Statement *stmt;
        string connectString;
        string username;
        string password;

};

#endif // CONTROLLER_DB_H