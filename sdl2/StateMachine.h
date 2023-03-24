// State.h
#pragma once

#include <iostream>

using namespace std;

class State {
public:
    State(){}
    virtual ~State() {}

    virtual void Enter() = 0;
    virtual void Update() = 0;
    virtual void Exit() = 0;

    //pointers to all the other state
    static State * mainMenu ;
    static State * instructorMainMenu; 
    static State * manageAccount ;
    static State * viewMyCourses ;
    static State * viewTask ;
    static State * sortTask ;
    static State * viewAllAvailableCourses;
    static State * manageCourseSubscription;
    static State * manageTask;
    static State * viewConsolidatedDeadlines;
    static State * manageCourse;

    //to track current states for instructor and students
	static State * currStateStu;
    static State * currStateIns;
};

//////////Main Menu//////////////

class MainMenu : public State{
	
    public:
    MainMenu(/*args*/){}
    virtual ~MainMenu(){}

    void Enter() ;
    void Update() ;
    void Exit() ;


};

//////////Instructor Main Menu//////////////

class InstructorMainMenu : public State{
	
    public:
    InstructorMainMenu(/*args*/){}
    virtual ~InstructorMainMenu(){}

    void Enter() ;
    void Update() ;
    void Exit() ;


};

//////////View Task//////////////

class ViewTask : public State{

    public:
    ViewTask(/*args*/){}
    virtual ~ViewTask(){}

    void Enter() ;
    void Update() ;
    void Exit() ;


};

///////////View My Course////////////

class ViewMyCourses : public State{
    
    public:
    ViewMyCourses(/*args*/){}
    virtual ~ViewMyCourses(){}

    void Enter() ;
    void Update() ;
    void Exit() ;    

};

///////////Manage Account////////////

class ManageAccount : public State{

    public:
    ManageAccount(/*args*/){}
    virtual ~ManageAccount(){}

    void Enter() ;
    void Update() ;
    void Exit() ;    

};

///////////Sort Task////////////

class SortTask : public State{

    public:
    SortTask(/*args*/){}
    virtual ~SortTask(){}

    void Enter() ;
    void Update() ;
    void Exit() ;    

};

///////////View All Available Courses////////////

class ViewAllAvailableCourses : public State{

    public:
    ViewAllAvailableCourses(/*args*/){}
    virtual ~ViewAllAvailableCourses(){}

    void Enter() ;
    void Update() ;
    void Exit() ;    

};

///////////Manage Course Subscription////////////

class ManageCourseSubscription : public State{

    public:
    ManageCourseSubscription(/*args*/){}
    virtual ~ManageCourseSubscription(){}

    void Enter() ;
    void Update() ;
    void Exit() ;    

};

///////////Manage Task////////////

class ManageTask : public State{

    public:
    ManageTask(/*args*/){}
    virtual ~ManageTask(){}

    void Enter() ;
    void Update() ;
    void Exit() ;    

};

///////////View Consolidated Deadlines////////////

class ViewConsolidatedDeadlines : public State{

    public:
    ViewConsolidatedDeadlines(/*args*/){}
    virtual ~ViewConsolidatedDeadlines(){}

    void Enter() ;
    void Update() ;
    void Exit() ;    

};

///////////Manage Course////////////

class ManageCourse : public State{

    public:
    ManageCourse(/*args*/){}
    virtual ~ManageCourse(){}

    void Enter() ;
    void Update() ;
    void Exit() ;    

};