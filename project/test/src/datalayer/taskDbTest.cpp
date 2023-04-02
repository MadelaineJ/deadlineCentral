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

static int s_TASK_ID = -1; // stores the auto generated id from insert to be used in edit and delete tests
Task TEST_TASK(-1,
                "TEST TASK",
                10,
                101,
                "TEST DESCRIPTION TASK",
                "04/01/2023",
                false,
                0.99);

BOOST_AUTO_TEST_SUITE(taskDatabase)

BOOST_AUTO_TEST_CASE(INSERT_TASK_PERSONAL) {
    
    // setup
    TaskDB* inTest = TaskDB::getInstance();

    s_TASK_ID = inTest->createTask(TEST_TASK);
    BOOST_CHECK_MESSAGE(s_TASK_ID > 1, "TASK_ID_GENERATED " << s_TASK_ID);
}

BOOST_AUTO_TEST_CASE(EDIT_TASK_PERSONAL) {
    
    // setup
    TaskDB* inTest = TaskDB::getInstance();
    Task expected(s_TASK_ID,
                    "UPDATED - TEST TASK",
                    10,
                    101,
                    "UPDATED - TEST DESCRIPTION TASK",
                    "04/01/2023",
                    false,
                    0.99);

    TEST_TASK.setTaskId(s_TASK_ID);
    TEST_TASK.setTaskDescription("UPDATED - TEST DESCRIPTION TASK");
    TEST_TASK.setTaskName("UPDATED - TEST TASK");

    bool updateReturn = inTest->updateTask(TEST_TASK);

    Task result = inTest->getTaskInfo(s_TASK_ID);

    BOOST_CHECK_MESSAGE(updateReturn, "UPDATE RETURNED " << updateReturn);
    BOOST_CHECK(result.getTaskId() == expected.getTaskId());
    BOOST_CHECK(result.getTaskName() == expected.getTaskName());
    BOOST_CHECK(result.getTaskType() == expected.getTaskType());
    BOOST_CHECK(result.getTaskOwner() == expected.getTaskOwner());
    BOOST_CHECK(result.getTaskDescription() == expected.getTaskDescription());
    BOOST_CHECK_MESSAGE(result.getDueDate() == expected.getDueDate(), "EXPECTED: " <<
                         expected.getDueDate() << ", but got " << result.getDueDate());
    BOOST_CHECK(result.getCompletionStatus() == expected.getCompletionStatus());
    BOOST_CHECK(result.getWeight() == expected.getWeight());
}

BOOST_AUTO_TEST_CASE(DELETE_TASK_PERSONAL) {
    // setup
    TaskDB* inTest = TaskDB::getInstance();

    cout << TEST_TASK << endl;
    bool result = inTest->deleteTask(TEST_TASK);
    BOOST_CHECK(result);
}

BOOST_AUTO_TEST_CASE(view_task) {
    
    // setup
    TaskDB* inTest = TaskDB::getInstance();
    Task expected(14, "CSCI 260 Assignment", 1, 2002, 
                "Assignment task for CSCI 260 due on April 01", 
                "04/01/2023" , false, 0.1);
    Task result = inTest->getTaskInfo(14);

    // verify
    BOOST_CHECK(result.getTaskId() == expected.getTaskId());
    BOOST_CHECK(result.getTaskName() == expected.getTaskName());
    BOOST_CHECK(result.getTaskType() == expected.getTaskType());
    BOOST_CHECK(result.getTaskOwner() == expected.getTaskOwner());
    BOOST_CHECK(result.getTaskDescription() == expected.getTaskDescription());
    BOOST_CHECK_MESSAGE(result.getDueDate() == expected.getDueDate(), "EXPECTED: " <<
                         expected.getDueDate() << ", but got " << result.getDueDate());
    BOOST_CHECK(result.getCompletionStatus() == expected.getCompletionStatus());
    BOOST_CHECK(result.getWeight() == expected.getWeight());
}


// Brandon
BOOST_AUTO_TEST_CASE(Filter_Tasks_FINAL_EXAMS_INSTRUCTOR_1001) {
    
    // setup
    TaskDB* inTest = TaskDB::getInstance();

    // create list of tasks expected
    list<Task> expected = { 
        Task(6, "CSCI 251 Final Exam", 5, 2000, " Final Exam task for CSCI 251 due on April 13", "04/13/2023", false, 0.5),
        Task(12, "CSCI 265 Final Exam", 5, 2001, " Final Exam task for CSCI 265 due on April 16", "04/16/2023", false, 0.5),
        Task(18, "CSCI 260 Final Exam", 5, 2002, " Final Exam task for CSCI 260 due on April 20", "04/20/2023", false, 0.5),
        Task(24, "CSCI 310 Final Exam", 5, 2003, " Final Exam task for CSCI 310 due on April 17", "04/17/2023", false, 0.5)
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
        BOOST_CHECK_MESSAGE(it_result->getDueDate() == it_expected->getDueDate(), "EXPECTED: " <<
                         it_expected->getDueDate() << ", but got " << it_result->getDueDate());
        BOOST_CHECK(it_result->getCompletionStatus() == it_expected->getCompletionStatus());
        BOOST_CHECK(it_result->getWeight() == it_expected->getWeight());

        it_expected++;
    }
}

BOOST_AUTO_TEST_SUITE_END()
