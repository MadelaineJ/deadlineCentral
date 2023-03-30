#ifndef COURSE_H
#define COURSE_H

// Required Libraries
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <list>



using namespace std;


class Course 
{
    public:
        Course(int courseId, int instructorId, string courseName, string courseCode, string calendarDescription);
        ~Course();
        
        int getCourseId();
        void setCourseId(int courseId);

        int getInstructorId();
        void setInstructorId(int instructorId);
        
        string getCourseName();
        void setCourseName(string courseName);
        
        string getCourseCode();
        void setCourseCode(string courseCode);

        string getCalendarDescription();
        void setCalendarDescription(string calendarDescription);

        list<int> getEnrollmentList();
        void setEnrollmentList(list<int> enrollmentList);

        friend std::ostream& operator<< (std::ostream& out, const Course& c); // allows us to use std::cout << <COURSE-OBJECT>

    private:
        int courseId;
        int instructorId;
        string courseName;
        string courseCode;
        string calendarDescription;
        list<int> enrollmentList;



};

#endif 
