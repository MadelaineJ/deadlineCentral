// Required boost definitions
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE DeadlineCentral

// the file to be tested
#include "controllerDb.hpp"

// custom header files
#include "controllerDbTest.hpp"

// required libraries
#include <boost/test/included/unit_test.hpp>



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
