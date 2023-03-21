#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "view.hpp"
using namespace std;
const string userName = std::getenv("USER");
const string ASSET_PATH = "/home/student/" + userName  + "/csci375/Project/project/assets/";

//base class
class BaseState{

    public:

        BaseState() {}
        virtual ~BaseState() {}

        //any class that is derived has to provide definition for the following functions
        virtual void enter() = 0;
        virtual void update() = 0;
        virtual void exit() = 0;

        void shutdown();
        void limit_fps(Uint32 start_tick);

        static SDL_Window * win ; //window
        static SDL_Renderer * ren; //renderer

        SDL_Texture * bgTexture; //background texture for each class

        //static BaseState * currState ; //pointer to current state

        //pointers to all the other state
        static BaseState * mainMenu ; 
        static BaseState * viewTask ;
        static BaseState * viewCourse ;
        static BaseState * createTask ;
        static BaseState * createCourse ;

	static BaseState * currState;

};


//////////Main Menu//////////////

class MainMenu : public BaseState{
	
    public:
    MainMenu(/*args*/);
    virtual ~MainMenu();

    void enter() ;
    void update() ;
    void exit() ;


};

//////////View Task//////////////

class ViewTask : public BaseState{

    public:
    ViewTask(/*args*/);
    virtual ~ViewTask();

    void enter() ;
    void update() ;
    void exit() ;


};

///////////View Course////////////

class ViewCourse : public BaseState{
    
    public:
    ViewCourse(/*args*/);
    virtual ~ViewCourse();

    void enter() ;
    void update() ;
    void exit() ;    

};

///////////Create Task////////////

class CreateTask : public BaseState{

    public:
    CreateTask(/*args*/);
    virtual ~CreateTask();

    void enter() ;
    void update() ;
    void exit() ;    

};

///////////Create Course////////////

class CreateCourse : public BaseState{

    public:
    CreateCourse(/*args*/);
    virtual ~CreateCourse();

    void enter() ;
    void update() ;
    void exit() ;    

};


#endif // CONTROLLER_DB_H