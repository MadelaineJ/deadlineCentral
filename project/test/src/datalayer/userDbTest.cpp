// Unit tests for userDb.cpp

// required libraries
#include <boost/test/unit_test.hpp>

// custom header files
#include "userDbTest.hpp"
#include "user.hpp"

// the file being tested
#include "userDb.hpp"

#include <iostream>

using namespace std;

BOOST_AUTO_TEST_SUITE(userDatabase)

BOOST_AUTO_TEST_CASE(view_user_student) {
    
    // setup
    UserDB* inTest = UserDB::getInstance();
    list<int> L;
    L.push_back(83);
    User expected(111, "William Lowe", "passwordWil", "WilliamLowe@example.com", L);
    User result = inTest->getUserInfoById(111);
    //result.printUserInfo();
    //expected.printUserInfo();

    // verify
    BOOST_CHECK(result.compare(expected));
}

BOOST_AUTO_TEST_CASE(view_user_instructor) {
    
    // setup
    UserDB* inTest = UserDB::getInstance();
    list<int> L;
<<<<<<< Updated upstream
    User expected(1003, "Ezra Lane", "passwordEzr", "EzraLane@example.com", L);
    User result = inTest->getUserInfoById(1003);
    // result.printUserInfo();
    // expected.printUserInfo();
=======
    User expected("Ezra Lane", "passwordEzr", "EzraLane@example.com", L);
    User result = inTest->getUserInfo(1003);
    result.printUserInfo();
    expected.printUserInfo();
>>>>>>> Stashed changes

    // verify
    BOOST_CHECK(result.compare(expected));
}

BOOST_AUTO_TEST_SUITE_END()
