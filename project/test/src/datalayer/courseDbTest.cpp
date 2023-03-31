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
	list<Student> expected = {
		Student(-1, "Michel Marshall", "", "", {}),
		Student(-1, "Glenda Forbes", "", "", {}),
		Student(-1, "Jeff Marsh", "", "", {}),
		Student(-1, "Ingrid Rose", "", "", {}),
		Student(-1, "Susanne Theriault", "", "", {}),
		Student(-1, "Annette Jacobs", "", "", {}),
		Student(-1, "Jodi James", "", "", {}),
		Student(-1, "Jayne Butler", "", "", {}),
		Student(-1, "Jamie Milne", "", "", {}),
		Student(-1, "Edna Daigle", "", "", {}),
		Student(-1, "Gene Davidson", "", "", {}),
		Student(-1, "Melissa McRae", "", "", {}),
		Student(-1, "Charmaine Turgeon", "", "", {}),
		Student(-1, "Rosaire Young", "", "", {}),
		Student(-1, "Brendan Maltais", "", "", {}),
		Student(-1, "Jordan Mercer", "", "", {}),
		Student(-1, "Vicky Levasseur", "", "", {}),
		Student(-1, "Cheryl Lloyd", "", "", {}),
		Student(-1, "Ginette Sanderson", "", "", {}),
		Student(-1, "Aaron Frenette", "", "", {}),
		Student(-1, "Melissa Tait", "", "", {}),
		Student(-1, "Emma Nielsen", "", "", {}),
		Student(-1, "Mark Paul", "", "", {}),
		Student(-1, "Theresa Cummings", "", "", {}),
		Student(-1, "Fatima Greene", "", "", {}),
		Student(-1, "Pierrette Fung", "", "", {}),
		Student(-1, "Naomi Hodgson", "", "", {})
	};
    
	list<Student> result = inTest->getEnrollmentList(ENROLLMENT_COURSE_ID);

	auto it_expected = expected.begin();
    for(auto it_result = result.begin(); it_result != result.end(); it_result++){
        // verify
        BOOST_CHECK(it_result->getName() == it_expected->getName());
        it_expected++;
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
