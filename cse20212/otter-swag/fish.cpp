// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// fish.cpp implemenation file

#include "sprite.h"
#include "fish.h"
#include "SDL/SDL.h"
#include <vector>
#include <string>
#include <iostream>

Fish::Fish(std::string filename, int r, int g, int b,int randY):Sprite(2), SWIM(0), EATEN(1){
    hasCollided = false;

    //Initialize movement variables
    offSetY = randY;
    offSetX = SCREEN_WIDTH;
    velocityX = 10;
    velocityY = 0;

    //Initialize animation variables
    frame = 0;
    status = SWIM;

    //Sprite pointer
    sprite = load_image(filename,r,g,b);

    //Initialize States
    set_clips();
}

int Fish::getOffSetX(){ //returns x position coordinate
	return offSetX;
}

int Fish::getOffSetY(){ //returns y position coordinate
	return offSetY;
}

void Fish::set_clips(){
    //Clip the sprites
    states[0][0].x = 281; //swim0
    states[0][0].y = 15;
    states[0][0].w = 31;
    states[0][0].h = 17;

    states[0][1].x = 241; //swim1
    states[0][1].y = 13;
    states[0][1].w = 30;
    states[0][1].h = 18;

    states[0][2].x = 323; //swim2
    states[0][2].y = 10;
    states[0][2].w = 30;
    states[0][2].h = 23;

    states[0][3].x = 405; //swim3
    states[0][3].y = 5;
    states[0][3].w = 30;
    states[0][3].h = 26;

    states[0][4].x = 364; //swim4
    states[0][4].y = 5;
    states[0][4].w = 30;
    states[0][4].h = 27;    

    states[1][0].x = 0; //eaten0
    states[1][0].y = 0;
    states[1][0].w = 1;
    states[1][0].h = 1;
}

int Fish::collision(){
	status = EATEN; //fish is eaten
	hasCollided = true; //collision has occured
	return 3; //collision was with a fish
}


void Fish::move(){
    // increase the offSet based on the value of the velocity (up or down)
    offSetX -= velocityX;
}

void Fish::show(SDL_Surface *screen){
	if (status == SWIM){ //cycles through 5 different swimming sprites to give animation
 		if (frame < 4){
			frame++;
		}else{
        	frame = 0;
		}
		apply_surface(sprite, screen, &states[0][frame]);
	}
	if (status == EATEN){ //makes fish disappear when eaten
		frame = 0;

		apply_surface(sprite, screen, &states[1][frame]);
	}
}
