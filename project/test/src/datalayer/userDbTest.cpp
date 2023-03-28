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
    User expected("William Lowe", "passwordWil", "WilliamLowe@example.com", L);
    User result = inTest->getUserInfo("111");
    result.printUserInfo();
    expected.printUserInfo();

    // verify
    BOOST_CHECK(inTest->getUserInfo("111").compare(expected));
}

BOOST_AUTO_TEST_CASE(view_user_instructor) {
    
    // setup
    UserDB* inTest = UserDB::getInstance();
    list<int> L;
    User expected("Ezra Lane", "passwordEzr", "EzraLane@example.com", L);
    User result = inTest->getUserInfo("1003");
    result.printUserInfo();
    expected.printUserInfo();

    // verify
    BOOST_CHECK(inTest->getUserInfo("1003").compare(expected));
}

BOOST_AUTO_TEST_SUITE_END()
