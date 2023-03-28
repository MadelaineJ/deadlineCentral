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
void CourseDB::aggregateDeadlines(int courseID){

}
