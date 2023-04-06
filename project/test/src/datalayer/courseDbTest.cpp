// Unit tests for courseDb.cpp

// required libraries
#include <boost/test/unit_test.hpp>

// custom header files
#include "courseDbTest.hpp"
#include "course.hpp"
#include "aggregateDeadline.hpp"

// the file being tested
#include "courseDb.hpp"

#include <iostream>

using namespace std;

static int s_COURSE_ID = -1; // gets the auto generated id from insert to be used in edit and delete tests

BOOST_AUTO_TEST_SUITE(courseDB)

BOOST_AUTO_TEST_CASE(create_course) {

	//setup
	Course expected(1000, 1002, "Junk and Snip", "FOO123", "A description");
	CourseDB* inTest = CourseDB::getInstance();
	s_COURSE_ID = inTest->createCourse(expected);

	//verify
	BOOST_CHECK(s_COURSE_ID > 0);
	
}

BOOST_AUTO_TEST_CASE(edit_course) {

	//setup
	Course expected(s_COURSE_ID, 1002, "Junk and Snip", "FOO123", "A description");
	expected.setCourseName("PICKLE");
	CourseDB* inTest = CourseDB::getInstance();
	bool result = inTest->updateCourse(expected);

	//verify
	BOOST_CHECK(result == true);

}

BOOST_AUTO_TEST_CASE(delete_course) {

	//setup
	Course expected(s_COURSE_ID, 1002, "Junk and Snip", "FOO123", "A description");
	CourseDB* inTest = CourseDB::getInstance();
	bool result = inTest->deleteCourse(expected);


	//verify
	BOOST_CHECK(result == true);
}

// get aggregate deadline information specifying date & course
BOOST_AUTO_TEST_CASE(aggregate_Deadlines) {

	CourseDB* inTest = CourseDB::getInstance();
	list<AggregateDeadline> result = inTest->aggregateDeadlines(2000, "01/07/2023");
	BOOST_CHECK(result.front().affectedStudents == 7);
}

BOOST_AUTO_TEST_CASE(get_CourseId_by_CourseCode_InstructorName) {
    CourseDB *inTest = CourseDB::getInstance();
    BOOST_CHECK(inTest->getCourseID(COURSE_CODE, INSTRUCTOR_NAME) == EXPECTED_COURSE_ID);
}

BOOST_AUTO_TEST_CASE(get_EnrollmentList) {
    CourseDB *inTest = CourseDB::getInstance();

	list<int> expectedList = {
		106,
		110,
		112,
		115,
		122,
		126,
		129,
		134,
		136,
		137,
		141,
		142,
		143,
		146,
		148,
		152,
		157,
		158,
		161,
		163,
		166,
		171,
		172,
		177,
		191,
		192,
		197
	};
    
	list<int> resultList = inTest->getEnrollmentList(ENROLLMENT_COURSE_ID);

	// Verify
	BOOST_CHECK(expectedList.size() == resultList.size());

    // setup
	std::vector<int> sortedExpectedList(expectedList.begin(), expectedList.end());
    std::vector<int> sortedResultList(resultList.begin(), resultList.end());
    std::sort(sortedExpectedList.begin(), sortedExpectedList.end());
    std::sort(sortedResultList.begin(), sortedResultList.end());

	// verify
    for (size_t i = 0; i < sortedExpectedList.size(); i++) {
		BOOST_CHECK(sortedExpectedList[i] == sortedResultList[i]);
    }
}

BOOST_AUTO_TEST_CASE(get_Course_Info) {
    CourseDB *inTest = CourseDB::getInstance();
	Course expected(COURSE_INFO_ID, 1003, "Object-Oriented Software Development",
					"CSCI 331",
					"Topics include aspects of object-oriented analysis, design and development; definition and comparison of object-oriented metrics; verification methods for OO-software; maintenance and reuse issues. (3:0:1)");
    Course result = inTest->getCourseInfo(COURSE_INFO_ID);

	BOOST_CHECK(result.getCourseId() == expected.getCourseId());
	BOOST_CHECK(result.getInstructorId() == expected.getInstructorId());
	BOOST_CHECK(result.getCourseName() == expected.getCourseName());
	BOOST_CHECK(result.getCourseCode() == expected.getCourseCode());
}
	
BOOST_AUTO_TEST_SUITE_END()
