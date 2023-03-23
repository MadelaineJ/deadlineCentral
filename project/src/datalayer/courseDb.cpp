#include "courseDb.hpp"

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
