// handles connection and query sending to database

#include <iostream>
#include "occi.h"  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>

// custom header files
#include "controllerDb.hpp"

using namespace std;
using namespace oracle::occi;

// constructor
ControllerDb::ControllerDb()
{
    this->username = USERNAME;
    this->password = PASSWORD;
    this->connectString = CONNECTION_STRING;
    this->stmt = NULL;

}

// destructor
ControllerDb::~ControllerDb() { }

/*
* establishes connection to the oracle database using connection parameters defined in controllerDb.hpp
* todo: this should probably return the result set (rs) so the other db layers can make use of it
* author: Brandon & Madelaine
*/ 
string ControllerDb::connect() {
    try {
        this->environment = Environment::createEnvironment();
        this->connection = environment->createConnection(this->username, this->password, this->connectString);
        cout << "Connected to Oracle database using OCCI." << endl << endl;
    } catch (SQLException & e) {
        return e.what() + this->username;
    }
    return "success";
}

/*
* executes a query if connect was called previously
* todo: this should probably return the result set (rs) so the other db layers can make use of it
* author: Brandon & Madelaine
*/ 
void ControllerDb::sendQuery(string query) {
    if (this->connection != NULL) {
        this->stmt = this->connection->createStatement(); 
        cout << "QUERY: " << query << endl;
        ResultSet *rs = stmt->executeQuery(query); // should not pass query in execute but prepare it first in createStatement()
        while (rs->next()) {
            cout << rs->getInt(1) << " | ";
            cout << rs->getString(2) << " | ";
            cout << rs->getString(3) << " | ";
            cout << rs->getString(4) << "\n\n";
        }
    }
}

/*
* terminates the connection to oracle db only if connect() was called first
* author: Brandon & Madelaine
*/
string ControllerDb::disconnect() {
    cout << "Terminating connection...\n";
    try {
        if (this->stmt != NULL) {
            this->connection->terminateStatement(this->stmt);
        }
        if (this->environment != NULL) {
            this->environment->terminateConnection(this->connection); 
            Environment::terminateEnvironment(this->environment);
        }
    } catch (SQLException & e) {
        return e.what() + this->username;
    }
    return "success";
}
