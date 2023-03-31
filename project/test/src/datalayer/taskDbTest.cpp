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
    TaskDB* inTest = TaskDB::getInstance();
    Task expected(1071, "Personal Task", 10, 172, "Personal task for Mark Paul", "NULL" , false, 0);
    Task result = inTest->getTaskInfo("1071");

    // verify
    BOOST_CHECK(inTest->getTaskInfo("1071").compare(expected));
}


// Brandon
BOOST_AUTO_TEST_CASE(Filter_Tasks_FINAL_EXAMS_INSTRUCTOR_1001) {
    
    // setup
    TaskDB* inTest = TaskDB::getInstance();

    // create list of tasks expected
    list<Task> expected = { 
        Task(6, "CSCI 251 Final Exam", 5, 2000, " Final Exam task for CSCI 251 due on April 13", "13-APR-23", false, 0.5),
        Task(12, "CSCI 265 Final Exam", 5, 2001, " Final Exam task for CSCI 265 due on April 16", "16-APR-23", false, 0.5),
        Task(18, "CSCI 260 Final Exam", 5, 2002, " Final Exam task for CSCI 260 due on April 20", "20-APR-23", false, 0.5),
        Task(24, "CSCI 310 Final Exam", 5, 2003, " Final Exam task for CSCI 310 due on April 17", "17-APR-23", false, 0.5)
    };

    // results from function
    list<Task> result = inTest->getFilteredTasks(5, 0, 0, 0, 0, 1001);

    // compare results to expected
    auto it_expected = expected.begin();
    for(auto it_result = result.begin(); it_result != result.end(); it_result++){
        // verify
        BOOST_CHECK(it_result->getTaskId() == it_expected->getTaskId());
        BOOST_CHECK(it_result->getTaskName() == it_expected->getTaskName());
        BOOST_CHECK(it_result->getTaskType() == it_expected->getTaskType());
        BOOST_CHECK(it_result->getTaskOwner() == it_expected->getTaskOwner());
        BOOST_CHECK(it_result->getTaskDescription() == it_expected->getTaskDescription());
        BOOST_CHECK(it_result->getDueDate() == it_expected->getDueDate());
        BOOST_CHECK(it_result->getCompletionStatus() == it_expected->getCompletionStatus());
        BOOST_CHECK(it_result->getWeight() == it_expected->getWeight());

        it_expected++;
    }
}

BOOST_AUTO_TEST_SUITE_END()
