// Unit tests for controllerDb.cpp

// required libraries
#include <boost/test/unit_test.hpp>

// custom header files
#include "controllerDbTest.hpp"

// the file being tested
#include "controllerDb.hpp"

#include <iostream>

using namespace std;

BOOST_AUTO_TEST_SUITE(controllerDB)

BOOST_AUTO_TEST_CASE(database_connection) {
    
    // setup
    ControllerDb inTest;

    // verify
    BOOST_CHECK(inTest.connect() == DATABASE_CONNECTION_EXPECTED);
    BOOST_CHECK(inTest.disconnect() == DATABASE_CONNECTION_EXPECTED);
}

BOOST_AUTO_TEST_SUITE_END()