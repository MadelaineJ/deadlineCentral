// Unit tests for controllerDb.cpp

// required libraries
#include <boost/test/unit_test.hpp>

// custom header files
#include "taskDbTest.hpp"
#include "task.hpp"

// the file being tested
#include "taskDb.hpp"

#include <iostream>

using namespace std;

BOOST_AUTO_TEST_SUITE(taskDatabase)

BOOST_AUTO_TEST_CASE(view_task) {
    
    // setup
    TaskDB inTest;
    Task expected(1000, "Personal Task", 10, 101, "Personal task for Carman Gravel", "", false, 0);
    Task result = inTest.getTaskInfo("1000");
    result.printTaskInfo();
    expected.printTaskInfo();

    // verify
    BOOST_CHECK(inTest.getTaskInfo("1000").compare(expected));
}

BOOST_AUTO_TEST_SUITE_END()