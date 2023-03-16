#include "statemachine.h"

///////////////////////////////////////
/////////////Global Space//////////////
///////////////////////////////////////

///////////very important////////////

void BaseState:: limit_fps(Uint32 start_tick){
    if((1000/fps) > SDL_GetTicks() - start_tick) {
        SDL_Delay(1000/fps - (SDL_GetTicks() - start_tick));
    }
}

//hard coded width and height, window not resizable
SDL_Window * BaseState:: win = SDL_CreateWindow("State Machine" , SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 640, 480, 0); 
SDL_Renderer * BaseState:: ren = SDL_CreateRenderer (win,-1,0); //renderer
TTF_Font *font = TTF_OpenFont("fonts/Roboto-Regular.ttf", 25);

BaseState * BaseState:: mainMenu = new MainMenu;
BaseState * BaseState:: viewTask = new ViewTask;
BaseState * BaseState:: viewCourse = new ViewCourse;
BaseState * BaseState:: createTask = new CreateTask;
BaseState * BaseState:: createCourse = new CreateCourse;

BaseState * BaseState:: currState = mainMenu;

void BaseState::shutdown(){

    TTF_Quit();
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    exit();

}

//////////Main Menu//////////////

MainMenu::MainMenu(){

    bgTexture = IMG_LoadTexture(ren, "menu.png"); //menu background

    if(!bgTexture){
        cout << "menu could not be loaded" << SDL_GetError()<<endl;
    }

}    
MainMenu::~MainMenu(){

    SDL_DestroyTexture(bgTexture); //it only loads it once but just to be safe and avoid any memory leaks
}
void MainMenu::enter(){}

void MainMenu::update(){

    Uint32 starting_tick;

    //main menu loop
    while(currState == BaseState::mainMenu){

        starting_tick = SDL_GetTicks();

        SDL_Event e;
        //input loop
        while(SDL_PollEvent(&e)){
            switch(e.type){

                case SDL_QUIT:
                    shutdown();
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        shutdown();
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_1){
                        currState = viewTask;
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_2){
                        currState = viewCourse;
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_3){
                        currState = createTask;
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_4){
                        currState = createCourse;
                        break;
                    }
                    

            }
        }

        SDL_RenderClear(ren);
        SDL_Rect rect = {0,0,640,480};
        SDL_RenderCopy(ren, bgTexture, NULL, &rect);
        SDL_RenderPresent(ren);
        limit_fps(starting_tick);

    }


}

void MainMenu::exit(){}


//////////View Task//////////////

ViewTask::ViewTask(){

    bgTexture = IMG_LoadTexture(ren, "icon.png"); //menu background

    if(!bgTexture){
        cout << "icon could not be loaded" << SDL_GetError()<<endl;
    }
}    
ViewTask::~ViewTask(){

    SDL_DestroyTexture(bgTexture); //it only loads it once but just to be safe and avoid any memory leaks
}
void ViewTask::enter(){}
void ViewTask::update(){

    Uint32 starting_tick;

    while(currState == BaseState::viewTask){

        starting_tick = SDL_GetTicks();
        SDL_Event e;using namespace std;

        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    shutdown();
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        shutdown();
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_1){
                        currState = mainMenu;
                        break;
                    }

            }
        }

        SDL_RenderClear(ren);
        SDL_Rect rect = {0,0,640,480};
        SDL_RenderCopy(ren, bgTexture, NULL, &rect);
        SDL_RenderPresent(ren);
        limit_fps(starting_tick);

    }

}
void ViewTask::exit(){}

///////////View Course////////////

ViewCourse::ViewCourse(){

    bgTexture = IMG_LoadTexture(ren, "icon.png"); //menu background

    if(!bgTexture){
        cout << "icon could not be loaded" << SDL_GetError()<<endl;
    }
}    
ViewCourse::~ViewCourse(){

    SDL_DestroyTexture(bgTexture); //it only loads it once but just to be safe and avoid any memory leaks    
}
void ViewCourse::enter(){}

void ViewCourse::update(){

    Uint32 starting_tick;

    while(currState == BaseState::viewCourse){

        starting_tick = SDL_GetTicks();
        SDL_Event e;

        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    shutdown();
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        shutdown();
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_1){
                        currState = mainMenu;
                        break;
                    }

            }
        }

        SDL_RenderClear(ren);
        SDL_Rect rect = {0,0,640,480};
        SDL_RenderCopy(ren, bgTexture, NULL, &rect);
        SDL_RenderPresent(ren);
        limit_fps(starting_tick);

    }
}
void ViewCourse::exit(){}

///////////Create Task////////////

CreateTask::CreateTask(){

    bgTexture = IMG_LoadTexture(ren, "icon.png"); //menu background

    if(!bgTexture){
        cout << "icon could not be loaded" << SDL_GetError()<<endl;
    }
}    
CreateTask::~CreateTask(){

    SDL_DestroyTexture(bgTexture); //it only loads it once but just to be safe and avoid any memory leaks
}
void CreateTask::enter(){}
void CreateTask::update(){

    Uint32 starting_tick;

    while(currState == BaseState::createTask){

        starting_tick = SDL_GetTicks();
        SDL_Event e;

        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    shutdown();
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        shutdown();
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_1){
                        currState = mainMenu;
                        break;
                    }

            }
        }

        SDL_RenderClear(ren);
        SDL_Rect rect = {0,0,640,480};
        SDL_RenderCopy(ren, bgTexture, NULL, &rect);
        SDL_RenderPresent(ren);
        limit_fps(starting_tick);

    }
}
void CreateTask::exit(){}

///////////Create Course////////////

CreateCourse::CreateCourse(){

    bgTexture = IMG_LoadTexture(ren, "icon.png"); //menu background

    if(!bgTexture){
        cout << "icon could not be loaded" << SDL_GetError()<<endl;
    }
}    
CreateCourse::~CreateCourse(){

    SDL_DestroyTexture(bgTexture); //it only loads it once but just to be safe and avoid any memory leaks
}
void CreateCourse::enter(){}
void CreateCourse::update(){

    Uint32 starting_tick;

    while(currState == BaseState::createCourse){

        starting_tick = SDL_GetTicks();
        SDL_Event e;

        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    shutdown();
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        shutdown();
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_1){
                        currState = mainMenu;
                        break;
                    }

            }
        }

        SDL_RenderClear(ren);
        SDL_Rect rect = {0,0,640,480};
        SDL_RenderCopy(ren, bgTexture, NULL, &rect);
        SDL_RenderPresent(ren);
        limit_fps(starting_tick);

    }
}
void CreateCourse::exit(){}


/*
int main() {


    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { // initialize SDL2
        std::cout << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }


    // create a window
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Window - Test",                  // window title
        SDL_WINDOWPOS_CENTERED,         // initial x position
        SDL_WINDOWPOS_CENTERED,         // initial y position
        640,                            // width, in pixels
        480,                            // height, in pixels
        SDL_WINDOW_SHOWN
    );

    if(window == NULL) {
        std::cout << "ERROR: window is NULL" << std::endl;
    }

    SDL_Event windowEvent;

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface *surface = IMG_Load("icon.png");

    // SDL_Texture *icon = IMG_LoadTexture(renderer, "icon.png");

    SDL_Rect rect = {0, 0, 400, 400};


    // Font Stuff
    
    std::cout << SDL_GetError();

    
    surface = TTF_RenderText_Solid(font, "Hello", color);
    SDL_Texture *icon = SDL_CreateTextureFromSurface(renderer, surface);

    while(true) {
        Uint32 starting_tick = SDL_GetTicks();
        SDL_RenderCopy(renderer, icon, NULL, &rect);
        SDL_RenderPresent(renderer);

        if(SDL_PollEvent (&windowEvent)) {
            if(SDL_QUIT == windowEvent.type){
                break;
            }
        }
        limit_fps(starting_tick);
    }


    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
*/

