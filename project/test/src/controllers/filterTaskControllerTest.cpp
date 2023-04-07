// Unit tests for filterTaskController.cpp

// required libraries
#include <boost/test/unit_test.hpp>

// custom header files
#include "course.hpp"
#include "task.hpp"
// the file being tested
#include "filterTaskController.hpp"
#include "userController.hpp"

#include <iostream>

using namespace std;


BOOST_AUTO_TEST_SUITE(filterTaskController)

Task createFakeTask(int taskType, int ownerId) {
    Task task(-1, "Test Task", taskType, ownerId, "Description", "10/25/2023", false, 0.0);
    return task;
}

void deleteTestTasks(TaskDB* taskDb, std::list<Task>& testTasks) {
    for (Task& task : testTasks) {
        taskDb->deleteTask(task);
    }
}

BOOST_AUTO_TEST_CASE(FilterTasksByTypeTest)
{
    FilterTaskController *filterTaskController = FilterTaskController::getInstance();
    UserController *userController = UserController::getInstance();
    TaskDB* taskDb = TaskDB::getInstance();
    std::list<Task> testTasks;

    int typeFiltered = 1; // Task type to filter by
    
    userController->createStudent("Test User", "testUser@mail.com", "passwordTest");
    User user = userController->getUserInfo(-1, "testUser@mail.com");
    int userId = user.getUserId();
    // Note: UserDb doesn't return the auto generated user id

    // Create some fake tasks to filter
    Task task1 = createFakeTask(typeFiltered, userId);
    Task task2 = createFakeTask(typeFiltered, userId);
    Task task3 = createFakeTask(typeFiltered, userId);
    Task task4 = createFakeTask(typeFiltered, userId);
    // Tasks that should not be returned in the filtered list
    Task task5 = createFakeTask(2, userId);
    Task task6 = createFakeTask(2, userId);
    Task task7 = createFakeTask(3, userId);
    Task task8 = createFakeTask(4, userId);
    Task task9 = createFakeTask(4, userId);

    // Add the fake tasks to the database and the list to delete them later
    testTasks.push_back(task1);
    testTasks.push_back(task2);
    testTasks.push_back(task3);
    testTasks.push_back(task4);
    testTasks.push_back(task5);
    testTasks.push_back(task6);
    testTasks.push_back(task7);
    testTasks.push_back(task8);
    testTasks.push_back(task9);
    for (Task& task : testTasks) {
        int taskId = taskDb->createTask(task);
        task.setTaskId(taskId);
    }

    userController->setCurrentUser(userId);

    filterTaskController->filterTasksByType(typeFiltered);

    std::list<Task> filteredTasks = filterTaskController->getTaskList();
    int numFilteredTasks = filteredTasks.size();
    BOOST_CHECK_EQUAL(numFilteredTasks, 4);
    //check that the type for each task is correct
    for (Task task : filteredTasks) {
        BOOST_CHECK_EQUAL(task.getTaskType(), typeFiltered);
    }
    // Clear Filters
    filterTaskController->findAllUserTasks();
    filteredTasks = filterTaskController->getTaskList();
    numFilteredTasks = filteredTasks.size();
    BOOST_CHECK_EQUAL(numFilteredTasks, 9);

    // Clean up Database
    deleteTestTasks(taskDb, testTasks);
    userController->deleteUser(userId);
}

BOOST_AUTO_TEST_SUITE_END()
