// Test main program to access oracle
#include <iostream>
#include <occi.h>  // Oracle's C++ call level interface library package
#include <termios.h>
#include <unistd.h>

#include "databaseTest.hpp"

using namespace std;
using namespace oracle::occi;

const string userName = "team1";
const string password = "teamwon1";
const string connectString = "192.168.56.101:1539/XEPDB1";

void helloWorldDb()
{
    try {
        // set connection
        Environment *env = Environment::createEnvironment();
        Connection *conn = env->createConnection(userName, password, connectString);

        cout << "Connected to Oracle database using OCCI." << endl << endl;

        // proper preparation should be added when we implement this
        Statement *stmt = conn->createStatement(); 
        string query = "SELECT * FROM Students UNION SELECT * FROM Instructors";
        cout << "QUERY 1: " << query << endl;
        ResultSet *rs = stmt->executeQuery(query); // should not pass query in execute but prepare it first in createStatement()
        while (rs->next()) {
            cout << rs->getInt(1) << " | ";
            cout << rs->getString(2) << " | ";
            cout << rs->getString(3) << " | ";
            cout << rs->getString(4) << "\n\n";
        }

        // clean up
        cout << "Terminating connection...\n";
        conn->terminateStatement(stmt);
        env->terminateConnection(conn);
        Environment::terminateEnvironment(env);
    } catch (SQLException & e) {
        cout << e.what();
    }
}

