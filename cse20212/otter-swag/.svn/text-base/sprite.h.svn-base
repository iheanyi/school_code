// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// sprite.h header file

/*
	sprite class forms the abstract base class on top of which all other sprite objects will be built
*/

#include "SDL/SDL.h"
#include <vector>
#include <string>

#ifndef SPRITE_H
#define SPRITE_H
using namespace std;

class Sprite{
    public:
        Sprite(int); //constructor
        void apply_surface(SDL_Surface *,SDL_Surface *,SDL_Rect *); //applies new surface
        virtual void move()=0; // handles the movement of the sprite
        virtual void show(SDL_Surface *)=0; // updates the frames of the sprite sheet shown based on conditional logic
	virtual void set_clips()=0; //clips sprite sheet
	virtual int collision()=0; //handles collision with another object
	SDL_Surface * load_image(std::string,int,int,int); //takes in image of sprite
	virtual int getOffSetX()=0; //returns x position coordinate
	virtual int getOffSetY()=0; //returns y position coordinate
	int frame; // determines which frame of the sprite sheet should be displayed
	bool getHasCollided(); //returns whether object has collided with another
	SDL_Surface * sprite; //sprite surface

    protected:
        int offSetX; // position of the sprite relevant to the origin of the x
	int offSetY; //and y axes
        int velocityX; // horizontal speed the sprite is moving at
        int velocityY; //vertical speed the sprite is moving at
        int status; // determines the status of movement the sprite is in (eg. walk, swim, fall)
	int height; //height of image
	int width; //width of image
	bool hasCollided; //whether object has collided with another
	vector< vector<SDL_Rect> > states; //contains states for sprite sheet clips and animation

	//Screen Dimensions
	const int SCREEN_WIDTH; 
	const int SCREEN_HEIGHT; 
	const int SCREEN_BPP; 

	//FPS
	const int FRAMES_PER_SECOND;

	//Statuses
	const int SPRITE_DOWN;
	const int SPRITE_UP;
	const int SPRITE_WALK;


};

#endif
