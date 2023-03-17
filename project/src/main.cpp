// Custom Header files
#include "controllerDb.hpp"
//Required Libraries
#include <iostream>

using namespace std;

int main() {
    ControllerDb db;
    db.connect();
    string query = "SELECT * FROM Students UNION SELECT * FROM Instructors";
    db.sendQuery(query);
    db.disconnect();
}
