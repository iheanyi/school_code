#include "SDL/SDL.h"
#include "background.h"
#include <iostream>
using namespace std;


void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* dest) { 
 //Temporary rectangle to hold the offsets
 SDL_Rect offset; //Get the offsets (position)
 offset.x = x;
 offset.y = y;
 //Blit the surface
 SDL_BlitSurface(source, NULL, dest, &offset);
}


Background::Background(const char *image, SDL_Surface *screen){
  dx = 0;

  picture = SDL_LoadBMP(image); //load in the picture to be used as background
  
  if(picture==NULL){ //if image doesn't load
    cout << "Error opening image" << endl;
  }
  
  SDL_BlitSurface(picture,NULL,screen,NULL); //copy picture to the screen
  SDL_Flip(screen); //update the screen
}

void Background::scroll(int velocity, SDL_Surface *screen){
     
    dx -= velocity; //scroll

    //if the background has gone too far
    if(dx <= -picture->w){dx = 0;}

    //show the background
    apply_surface(dx,0,picture,screen);
    apply_surface(dx + picture->w,0,picture,screen);
    
    SDL_Flip(screen);  //update the screen
  
}


  
