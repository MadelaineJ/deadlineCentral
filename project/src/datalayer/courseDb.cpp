//Included custom header files
#include "courseDb.hpp"
#include "course.hpp"
#include "instructor.hpp"
#include "controllerDb.hpp"


CourseDB* CourseDB::instance = nullptr; // initialize pointer

// returns a pointer to the single instance of CourseDB, if there is no instance it creates a new one
CourseDB* CourseDB::getInstance()   {
   if(instance == nullptr) {
      instance = new CourseDB();
   }
   return instance;
}

CourseDB::CourseDB() {}
CourseDB::~CourseDB() {}

bool CourseDB::createCourse(Course C){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   string query = "INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES ("
      + to_string(C.getCourseId()) + ", '"
      + C.getCourseCode() + "', '"
      + C.getCourseName() + "', '"
      + C.getCalendarDescription() + "', "
      + to_string(C.getInstructorId()) + ")";

   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
}

bool CourseDB::updateCourse(Course C){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   string query = "UPDATE Courses SET courseCode = '" 
	   + C.getCourseCode() + "', courseName = '" 
	   + C.getCourseName() + "', calendarDescription = '" 
	   + C.getCalendarDescription() + "', instructorID = " 
	   + to_string(C.getInstructorId()) + "WHERE courseID = " 
	   + to_string(C.getCourseId()) + "";

   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
}

bool CourseDB::deleteCourse(Course C){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();  

   string query = "DELETE FROM Courses WHERE courseID = " + to_string(C.getCourseId()) + "";

   int rowCount = controllerDB->getStatement()->executeUpdate(query);
   controllerDB->disconnect();
   return rowCount;
}

list<Student> CourseDB::getEnrollmentList(int courseID){
   list<Student> L;
   return L;
}

Course CourseDB::getCourseInfo(int courseID){
   Course C(0,0,"0", "0", "0");
   return C;
}

//TODO return type tbd
list<AggregateDeadline> CourseDB::aggregateDeadlines(int courseID, string date){
   ControllerDb* controllerDB = ControllerDb::getInstance();
   controllerDB->connect();

   stringstream queryBuilder;
   queryBuilder << "SELECT t.type, t.dueDate, c.courseName, COUNT(DISTINCT sc.studentID) "
                << "FROM Tasks t "
                << "JOIN StudentCourses sc ON t.courseID = sc.courseID "
                << "JOIN Courses c ON t.courseID = c.courseID "
                << "WHERE t.dueDate IN ( "
                << "SELECT t2.dueDate "
                << "FROM Tasks t2 "
                << "JOIN StudentCourses sc2 ON t2.courseID = sc2.courseID "
                << "WHERE t2.courseID = :thisCourse "
                << "AND sc2.studentID = sc.studentID "
                << ") "
                << "AND t.courseID != :thisCourse "
                << "AND sc.studentID IN ( "
                << "SELECT sc3.studentID "
                << "FROM StudentCourses sc3 "
                << "WHERE sc3.courseID = :thisCourse "
                << ") ";

   // only bind if we have a valid date var
   if(date != "") {
      cout << "DATE " << date << endl;
      queryBuilder << "AND t.dueDate = TO_DATE(:4, 'MM/DD/YYYY') ";
   }
   
   queryBuilder << "GROUP BY t.type, t.dueDate, c.courseName ";
   
   string query = queryBuilder.str();
   cout << "QUERY - " << query << endl;

   // prepare statement
   Statement *stmt = controllerDB->getConnection()->createStatement(query);
   stmt->setInt(1, courseID);
   stmt->setInt(2, courseID);
   stmt->setInt(3, courseID);

   // only bind if we have a date var
   if(date != ""){
      stmt->setString(4, date);
   }

   list<AggregateDeadline> aggregateDeadlineResults = {};

   // get results
    ResultSet *rs = stmt->executeQuery();

    if(rs->next()) {
      int type = rs->getInt(1); // task type
      string date = rs->getString(2); // due date
      string course = rs->getString(3); // course name
      int num = rs->getInt(4); // affected students

      AggregateDeadline ag; // create a new struct for each result row
      ag.type = type;
      ag.courseName = course;
      ag.dueDate = date;
      ag.affectedStudents = num;

      aggregateDeadlineResults.push_back(ag);
    }
      return aggregateDeadlineResults;
}
