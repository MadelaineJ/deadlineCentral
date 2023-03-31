// Unit tests for subscriptionDb.cpp

// required libraries
#include <boost/test/unit_test.hpp>

// custom header files
#include "subscriptionDbTest.hpp"
#include "course.hpp"

// the file being tested
#include "subscriptionDb.hpp"

#include <iostream>

using namespace std;

BOOST_AUTO_TEST_SUITE(subscriptionDatabase)

// add a new subscription between student and course
BOOST_AUTO_TEST_CASE(ADD_SUBSCRIPTION) {
    // setup
    SubscriptionDB* inTest = SubscriptionDB::getInstance();
}

// get a list of all course objects that the student is not subscribed too
BOOST_AUTO_TEST_CASE(getAvailableCourseList) {
    
    // setup
    SubscriptionDB* inTest = SubscriptionDB::getInstance();
    
    // create expected list of courses
    list<Course> expected = {
        Course(2000, 1001, "Systems and Networks", "CSCI251", "An introduction to operating systems and computer networks. Topics include network architectures, communications protocols, client / server architecture and file systems. The lab component includes hardware and software installations, upgrades and backups. (3:0:2)"),
        Course(2003, 1001, "Introduction to Human-Computer Interaction", "CSCI 310", "An introduction to understanding human behaviour as it applies to interface design, implementation, and evaluation. Topics include: design issues and goals, the limits of the human cognitive system, user-centered design, prototyping, establishing requirements, evaluation techniques, and design implications of emerging technologies. (3:0:1)"),
        Course(2004, 1002, "Web Programming", "CSCI 311", "Exploration of languages, tools and techniques to write software for use within the World Wide Web (WWW). The course includes the WWW client/server model and related protocols, web server properties, web markup languages, client/server scripting tools, server side programming, and database access tools. (3:0:2)"),
        Course(2005, 1002, "Foundations of Computer Science", "CSCI 320", "A survey of formal models and results that form the theoretical foundation of computer science. Typical topics include finite automata, Turing machines, simple undecidable problems, context-free languages, grammars and elementary computational complexity. (3:1:0)"),
        Course(2006, 1002, "Programming Languages", "CSCI 330", "The fundamental concepts of imperative and applicative programming languages. Topics include the description of data types, variable assignment and sharing, sequencing, iteration and recursion, parameter passing mechanisms, and type checking. (3:0:1)"),
        Course(2008, 1003, "Digital Logic and Computer Organization", "CSCI 355", "The fundamentals of logic design, computer organization, and the structure of major hardware components of computers. Topics include the application of Boolean algebra to switching circuits; the use of MSI, LSI and field programmable devices in digital design; combinatorial and sequential circuits, flip flops, counters, memory organization, CAD tools. (3:0:2)"),
        Course(2009, 1004, "Intro to Operating Systems", "CSCI 360", "An introduction to the major concepts of operating systems and study of the interrelationships between the operating system and the architecture of computer systems. Topics include operating system structures, concurrent programming techniques, cpu scheduling, deadlocks, memory management, file systems and protection. (3:0:1)"),
        Course(2010, 1005, "Database Systems", "CSCI 370", "An introduction to the use and operating principles of database management systems. Topics include data entities and relationships, data modelling using Entity-Relationship Diagrams, hierarchical, network and relational models of databases, query language, physical representation of data in secondary storage, relational algebra and calculus as applied to the design of databases, security and integrity in the context of concurrent use, and basic ethical issues associated with database design and use. (3:0:1)"),
        Course(2011, 1006, "Logic and Foundations", "MATH 123", "An introduction to higher level mathematical thinking and techniques vital for success in mathematics and computer science. Topics include fundamental counting principles, combinations and permutations, symbolic logic, set theory, elementary number theory, one-to-one and onto functions. Essential mathematical proof techniques are emphasized: direct proof, proof by contradiction and mathematical induction. (4:0:0)"),
    };

    list<Course> result = inTest->getAvailableCourseList(101);

    // compare results to expected
    auto it_expected = expected.begin();
    for(auto it_result = result.begin(); it_result != result.end(); it_result++){
        // verify
        BOOST_CHECK(it_result->getCourseId() == it_expected->getCourseId());
        BOOST_CHECK(it_result->getCourseCode() == it_expected->getCourseCode());
        BOOST_CHECK(it_result->getCourseName() == it_expected->getCourseName());
        BOOST_CHECK(it_result->getInstructorId() == it_expected->getInstructorId());
        BOOST_CHECK(it_result->getCalendarDescription() == it_expected->getCalendarDescription());
        it_expected++;
    }
}

BOOST_AUTO_TEST_CASE(getCourseSubscriptions) {
    
    // setup
    SubscriptionDB* inTest = SubscriptionDB::getInstance();
    
    // create expected list of courses
    list<Course> expected = {
        Course(2001, 1001, "Software Engineering", "CSCI265", "An exploration of the methods and tools for developing high quality software. The course includes topics in program design, program style, algorithm selection, interface design, debugging and testing, system utilities, version control, regular expressions and an introduction to scripting languages. (4:0:1)"),
        Course(2002, 1001, "Data Structures", "CSCI 260", "An examination of various methods of representing and manipulating data, including internal representation of data, stacks, queues, linked lists, trees and graphs. Analysis of algorithms will also be discussed extensively. (4:0:1)"), 
        Course(2007, 1003, "Object-Oriented Software Development", "CSCI 331", "Topics include aspects of object-oriented analysis, design and development; definition and comparison of object-oriented metrics; verification methods for OO-software; maintenance and reuse issues. (3:0:1)")
    };

    list<Course> result = inTest->getCourseSubscriptions(101);

    // compare results to expected
    auto it_expected = expected.begin();
    for(auto it_result = result.begin(); it_result != result.end(); it_result++){
        // verify
        BOOST_CHECK(it_result->getCourseId() == it_expected->getCourseId());
        BOOST_CHECK(it_result->getCourseCode() == it_expected->getCourseCode());
        BOOST_CHECK(it_result->getCourseName() == it_expected->getCourseName());
        BOOST_CHECK(it_result->getInstructorId() == it_expected->getInstructorId());
        BOOST_CHECK(it_result->getCalendarDescription() == it_expected->getCalendarDescription());
        it_expected++;
    }
}

BOOST_AUTO_TEST_SUITE_END()