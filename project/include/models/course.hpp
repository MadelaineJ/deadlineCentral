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
        Course(string courseName, string courseCode, string calendarDescription, list<int> enrollmentList);
        ~Course();
        
        string getCourseName();
        void setCourseName(string courseName);
        
        string getCourseCode();
        void setCourseCode(string courseCode);

        string getCalendarDescription();
        void setCalendarDescription(string calendarDescription);

        list<int> getEnrollmentList();
        void setEnrollmentList(list<int> enrollmentList);

    private:
        string courseName;
        string courseCode;
        string calendarDescription;
        list<int> enrollmentList;



};

#endif 
