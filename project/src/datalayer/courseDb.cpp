#include "courseDb.hpp"

CourseDB* CourseDB::instance = nullptr; // initialize pointer

// returns a pointer to the single instance of CourseDB, if there is no instance it creates a new one
CourseDB* CourseDB::getInstance()   {
   if(instance == nullptr) {
      instance = new CourseDB();
   }
   return instance;
}

bool CourseDB::createCourse(Course C){
   return 0;
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
