// Unit tests for userController.cpp

// required libraries
#include <boost/test/unit_test.hpp>

// custom header files
#include "course.hpp"
#include "task.hpp"
#include "courseController.hpp"
#include "taskController.hpp"
// the file being tested
#include "userController.hpp"


#include <iostream>

using namespace std;

BOOST_AUTO_TEST_SUITE(userControllerTest)



// This unit test was written using Chat GPT-4 with the following prompt:
/*
Note: the specifications for the Db classes and functions named below were pasted in their entirety to ChatGPT
but were only listed here for brevity. Additonally, the version GPT-4 gave had to be modified but only slightly

can you write a Boost library C++ function for this deleteUser function?

void UserController::deleteUser(int userId);

here is an example test for another function that you can base it off of:
BOOST_AUTO_TEST_CASE(get_EnrollmentList)

The new testing function should use userdb, taskdb and coursedb to create new tasks, users, and courses. 
It should check that all the associated resources get deleted afterwards. here are the taskdb, coursedb 
and userdb header files:

class CourseDB 
class TaskDB 
class UserDB

Here are the header files for Task, User, and Course classes:
class Course
class Task
class User


*/
BOOST_AUTO_TEST_CASE(delete_user_test) {
    UserController *userController = UserController::getInstance();
    CourseController *courseController = CourseController::getInstance();
    TaskController *taskController = TaskController::getInstance();

    // Create a student
    int studentId = userController->createStudent("John Doe", "student@example.com", "password123");
    userController->setCurrentUser(studentId);
    // Create an instructor
    int instructorId = userController->createInstructor("Jane Smith", "instructor@example.com", "password123");
    // Create a course
    int courseId = courseController->createCourse("Test Course", "This is a test course.", "TEST101", instructorId);
    // Create a task for the student
    int taskId = taskController->createUserTask(studentId, "Test Task", "This is a test task.", "04/01/2023", .5);
    // Delete the student
    userController->deleteUser(studentId);
    // Check that the student's task was deleted
    BOOST_CHECK(taskController->getTaskInfo(taskId).getTaskName() == "");
    // Check that the student was deleted
    BOOST_CHECK(userController->getUserInfo(studentId, "").getName() == "");

    // Delete the instructor
    userController->deleteUser(instructorId);

    // Check that the instructor's course was deleted
    Course course = courseController->getCourseInfo(courseId);
    BOOST_CHECK(courseController->getCourseInfo(courseId).getCourseName() == "");

    // Check that the instructor was deleted
    BOOST_CHECK(userController->getUserInfo(instructorId, "").getName() == "");
}

BOOST_AUTO_TEST_SUITE_END()