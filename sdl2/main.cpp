#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include <iostream>

int fps = 30;

void limit_fps(Uint32 start_tick){
    if((1000/fps) > SDL_GetTicks() - start_tick) {
        SDL_Delay(1000/fps - (SDL_GetTicks() - start_tick));
    }
}


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
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("fonts/Roboto-Regular.ttf", 25);
    std::cout << SDL_GetError();

    SDL_Color color = {100, 100, 100};
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


