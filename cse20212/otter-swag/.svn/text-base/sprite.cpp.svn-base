// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// sprite.cpp implemenation file

#include "sprite.h"
#include "SDL/SDL.h"
#include <string>

Sprite::Sprite(int count):states(count,vector<SDL_Rect>(15)), SCREEN_WIDTH(480),SCREEN_HEIGHT(320), SCREEN_BPP(32), FRAMES_PER_SECOND(10), SPRITE_DOWN(0), SPRITE_UP(1), SPRITE_WALK(2){} //constructor

bool Sprite::getHasCollided(){return hasCollided;} //returns variable tracking whether object has collided

void Sprite::apply_surface(SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL){ //applies new surface
    //Holds offsets
    SDL_Rect shift;

    //Get offsets
    shift.x = offSetX;
    shift.y = offSetY;

    //Blit
    SDL_BlitSurface(source, clip, destination, &shift);
}

SDL_Surface * Sprite::load_image(std::string filename, int r, int g, int b){ //takes in image of sprite
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = SDL_LoadBMP(filename.c_str());

    //If the image loaded
   if(loadedImage != NULL){
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat(loadedImage);

        //Free the old surface
        SDL_FreeSurface(loadedImage);

        //If the surface was optimized
	if(optimizedImage != NULL){
            //Color key surface
	  int colorkey = SDL_MapRGB(optimizedImage->format, r, g, b);
	  SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
	}
   }

    //Return the optimized surface
    return optimizedImage;
}
