#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

using namespace std;

void view_layer();

////////inititialisations///////////

static int k = SDL_Init(SDL_INIT_EVERYTHING); //initialised everything SDL

//TTF_Init(); //initialised ttf

/////////constants////////////

const int fps = 30;
//SDL_Color color = {100, 100, 100};

#endif // CONTROLLER_DB_H