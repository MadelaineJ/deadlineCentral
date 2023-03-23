// Custom Header files
#include "controllerDb.hpp"
#include "view.hpp"
#include "student.hpp"
#include "subscriptionController.hpp"
// Required Libraries
#include <iostream>
#include <string>
#include <list>


using namespace std;

int main() {
    // ControllerDb db;
    // db.connect();
    // string query = "SELECT * FROM Students UNION SELECT * FROM Instructors";
    // db.sendQuery(query);
    // db.disconnect();
    //view_layer();
    //Course foo("Assembly", "CSCI222", "Blah Balh Lall", {0, 1});

    list<int> list = {0, 1, 2};
    string name = "mad";
    string pass = "hie";
    string email = "hi";
    Student me(123, name, pass, email, list);
    me.setName("madelaine");
    
    SubscriptionController test;
    test.addSubscription();
}
