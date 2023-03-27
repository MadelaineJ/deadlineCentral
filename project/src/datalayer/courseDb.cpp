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
   /* Work in progress
   this->controllerDb.connect();
   
   string query = "INSERT INTO Courses (couseID, courseCode, courseName, calendarDescription, instructorID) VALUES ("
     + C.getCourseName() + ", "
     + C.getCourseCode() + ", '"
     + C.getCourseName() + "', '"
     + task.getTaskDescription() + "', TO_DATE('"
     + task.getDueDate() + "', 'YYYY-MM-DD HH24:MI:SS'), "
     + to_string(task.getWeight()) + ", "
     + to_string(task.getCompletionStatus()) + ", NULL, "
     + to_string(task.getTaskOwner()) + ", NULL)";

   int rowCount = this->controllerDb.getStatement()->executeUpdate(query);
   this->controllerDb.disconnect();
   return rowCount;
   */
}

bool CourseDB::updateCourse(Course C){
   return 0;
}

bool CourseDB::deleteCourse(Course C){
   return 0;
}

list<Student> CourseDB::getEnrollmentList(int courseID){
   list<Student> L;
   return L;
}

Course CourseDB::getCourseInfo(int courseID){
   list<int> L;
   Course C(0,0,0,L);
   return C;
}

//TODO return type tbd
void CourseDB::aggregateDeadlines(int courseID){

}
