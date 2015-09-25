// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// gameFuncs.h contains functions used throughout the program

#include "SDL/SDL.h"
#include <string>
#include <iostream>

#ifndef GAME_FUNCS
#define GAME_FUNCS

//variables
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 320;
const int SCREEN_BPP = 32;

const int FRAMES_PER_SECOND = 10;

SDL_Event event;

SDL_Surface *screen = NULL;

bool init(){
    //Initialize all SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    //If there was an error in setting up the screen
    if(screen == NULL){
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption("Otter Swag", NULL);

    //If everything initialized fine
    return true;
}

bool check_collision( SDL_Rect A, SDL_Rect B ){
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB ){
        return false;
    }

    if( topA >= bottomB ){
        return false;
    }

    if( rightA <= leftB ){
        return false;
    }

    if( leftA >= rightB ){
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

/*void clean_up(){
    //Free the surface
    SDL_FreeSurface(sprite);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(obstacle);

    //Quit SDL
    SDL_Quit();
    }*/


#endif
