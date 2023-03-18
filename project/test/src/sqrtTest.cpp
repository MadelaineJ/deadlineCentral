

// required libraries
#include <boost/test/unit_test.hpp>
#include <iostream>

// Custom header files
#include "sqrt.hpp"

using namespace std;

BOOST_AUTO_TEST_SUITE(math)

BOOST_AUTO_TEST_CASE(square_root) {
    BOOST_CHECK_MESSAGE(squareRoot(25) == 5, "TEST: square root of 25");
    BOOST_CHECK_MESSAGE(squareRoot(36) == 6, "TEST: square root of 36");
}

BOOST_AUTO_TEST_SUITE_END()
