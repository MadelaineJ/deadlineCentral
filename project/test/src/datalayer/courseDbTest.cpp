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

BOOST_AUTO_TEST_SUITE(courseDB)

BOOST_AUTO_TEST_CASE(create_course) {

	//setup
	Course expected(1000, 1002, "Junk and Snip", "FOO123", "A description");
	CourseDB* inTest = CourseDB::getInstance();
	bool result = inTest->createCourse(expected);
	
	//verify
	BOOST_CHECK(result == true);
	
}

BOOST_AUTO_TEST_CASE(edit_course) {

	//setup
	Course expected(1000, 1002, "Junk and Snip", "FOO123", "A description");
	expected.setCourseName("PICKLE");
	CourseDB* inTest = CourseDB::getInstance();
	bool result = inTest->updateCourse(expected);

	//verify
	BOOST_CHECK(result == true);

}

BOOST_AUTO_TEST_CASE(delete_course) {

	//setup
	Course expected(1000, 1002, "Junk and Snip", "FOO123", "A description");
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
	
BOOST_AUTO_TEST_SUITE_END()
