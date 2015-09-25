// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// missile.cpp implemenation file

#include "sprite.h"
#include "missile.h"
#include "SDL/SDL.h"
#include <vector>
#include <string>
#include <iostream>

Missile::Missile(std::string filename, int r, int g, int b,int randY):Sprite(2), SHOOT(0), EXPLODE(1){ //constructor

    hasCollided = false;

    //Initialize movement variables
    offSetY = randY;
    offSetX = SCREEN_WIDTH;
    velocityX = 20;
    velocityY = 0;

    //Initialize animation variables
    frame = 0;
    status = SHOOT;

    //Sprite pointer
    sprite = load_image(filename,r,g,b);

    //Initialize States
    set_clips();
}

int Missile::getOffSetX(){ 
	return offSetX;
}

int Missile::getOffSetY(){
	return offSetY;
}

void Missile::set_clips(){
    //Clip the sprites
    states[0][0].x = 13; //shoot0
    states[0][0].y = 16;
    states[0][0].w = 33;
    states[0][0].h = 8;

    states[0][1].x = 58; //shoot1
    states[0][1].y = 16;
    states[0][1].w = 32;
    states[0][1].h = 8;

    states[1][0].x = 49; //explode0
    states[1][0].y = 67;
    states[1][0].w = 35;
    states[1][0].h = 28;

    states[1][1].x = 148; //explode1
    states[1][1].y = 57;
    states[1][1].w = 52;
    states[1][1].h = 42;

    states[1][2].x = 236; //explode2
    states[1][2].y = 24;
    states[1][2].w = 92;
    states[1][2].h = 78;

    states[1][3].x = 334; //explode3
    states[1][3].y = 24;
    states[1][3].w = 105;
    states[1][3].h = 78;
	
    states[1][4].x = 458; //explode4
    states[1][4].y = 32;
    states[1][4].w = 80;
    states[1][4].h = 70;

    states[1][5].x = 568; //explode5
    states[1][5].y = 41;
    states[1][5].w = 76;
    states[1][5].h = 61;

    states[1][6].x = 28; //explode6
    states[1][6].y = 124;
    states[1][6].w = 73;
    states[1][6].h = 62;

    states[1][7].x = 137; //explode7
    states[1][7].y = 124;
    states[1][7].w = 74;
    states[1][7].h = 62;

    states[1][8].x = 242; //explode8
    states[1][8].y = 117;
    states[1][8].w = 78;
    states[1][8].h = 69;

    states[1][9].x = 349; //explode9
    states[1][9].y = 117;
    states[1][9].w = 81;
    states[1][9].h = 70;
	
    states[1][10].x = 459; //explode10
    states[1][10].y = 117;
    states[1][10].w = 79;
    states[1][10].h = 69;

    states[1][11].x = 567; //explode11
    states[1][11].y = 117;
    states[1][11].w = 77;
    states[1][11].h = 69;

    states[1][12].x = 13; //explode12
    states[1][12].y = 16;
    states[1][12].w = 0;
    states[1][12].h = 0;
}

int Missile::collision(){ //processes collision with otter
	status = EXPLODE;
	hasCollided = true;
	return 1; //missile collision
}


void Missile::move(){ //moves missile across screen
    // increase the offSet based on the value of the velocity (up or down)
    offSetX -= velocityX;
}

void Missile::show(SDL_Surface *screen){ //processes animation of missiles showing correct sprite for each frame
	if (status == SHOOT){ //swaps between the 2 sprites for the shooting animation of a missile
 		if (frame < 1){
			frame++;
		}else{
        	frame = 0;
		}
		apply_surface(sprite, screen, &states[0][frame]);
	}
	if (status == EXPLODE){ //swaps between the 12 sprites for the exploding animation of a missile
		if (frame < 12){
			frame++;
		}else{
        	frame = 12;
		}
		apply_surface(sprite, screen, &states[1][frame]);
	}
}
