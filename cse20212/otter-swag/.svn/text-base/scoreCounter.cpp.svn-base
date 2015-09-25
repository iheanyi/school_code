// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// scoreCounter.cpp implemenation file

#include "sprite.h"
#include "scoreCounter.h"
#include "SDL/SDL.h"
#include <vector>
#include <string>
#include <math.h>


scoreCounter::scoreCounter(std::string filename, int r, int g, int b):Sprite(1), COUNT(0){ //constructor
 
    isStarted = false;
    score = 0;
    hasCollided = false;
    title = true;

    //Initialize animation variables
    frame = 0;
    status = COUNT;

    //Sprite pointer
    sprite = load_image(filename,r,g,b);
    
    set_clips();
}

void scoreCounter::set_clips(){ //sets sprite sheet position clips
    //Clip the sprites
    states[0][0].x = 287; //0
    states[0][0].y = 0;
    states[0][0].w = 21;
    states[0][0].h = 28;

    states[0][1].x = 0; //1
    states[0][1].y = 0;
    states[0][1].w = 20;
    states[0][1].h = 28;

    states[0][2].x = 30; //2
    states[0][2].y = 0;
    states[0][2].w = 24;
    states[0][2].h = 28;

    states[0][3].x = 62; //3
    states[0][3].y = 0;
    states[0][3].w = 23;
    states[0][3].h = 28;

    states[0][4].x = 93; //4
    states[0][4].y = 0;
    states[0][4].w = 26;
    states[0][4].h = 28;

    states[0][5].x = 126; //5
    states[0][5].y = 0;
    states[0][5].w = 25;
    states[0][5].h = 28;

    states[0][6].x = 157; //6
    states[0][6].y = 0;
    states[0][6].w = 26;
    states[0][6].h = 28;

    states[0][7].x = 189; //7
    states[0][7].y = 0;
    states[0][7].w = 26;
    states[0][7].h = 28;

    states[0][8].x = 221; //8
    states[0][8].y = 0;
    states[0][8].w = 26;
    states[0][8].h = 28;

    states[0][9].x = 253; //9
    states[0][9].y = 0;
    states[0][9].w = 26;
    states[0][9].h = 28;
}

int scoreCounter::getOffSetX(){ //returns x position coordinate
	return offSetX;
}

int scoreCounter::getOffSetY(){ //returns y position coordinate
	return offSetY;
}

int scoreCounter::collision(){return 0;} //virtual function from inheritnace

void scoreCounter::apply_surface(int x, int y,SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL){ //applies new surface
    //Holds offsets
    SDL_Rect shift;

    //Get offsets
    shift.x = x;
    shift.y = y;

    //Blit
    SDL_BlitSurface(source, clip, destination, &shift);
}




bool scoreCounter::check_collision(int x,int y){} //virtual function from inheritance

void scoreCounter::move(){} //virtual function from inheritance

void scoreCounter::setScore(int num){ //sets score to a specific value
  score = num;
}


bool scoreCounter::getTitle(){ //returns variable tracking whether at the title screen
	return title;
}

void scoreCounter::setTitle(bool val){  //sets variable tracking whether at the title screen
	title = val;
}


void scoreCounter::show(SDL_Surface *screen){ //displays the counter

  int xPos = SCREEN_WIDTH - (28*6);
  isStarted = false;
int digits=0;
  for(int i=6;i>0;i--){
    frame = score / (pow(10,i-1));
    frame = frame % 10;
    if (isStarted || frame!=0){
		if (title){
      		apply_surface(xPos,0,sprite, screen, &states[0][frame]);
		}else{
			digits++;
			//xPos -= 165;
			xPos -= ((480-((digits+1)*28))/2)-10;
			apply_surface(xPos,135,sprite, screen, &states[0][frame]);	
			xPos += ((480-((digits+1)*28))/2)-10;
			//xPos += 165;
		}
      isStarted = true;
    }
    xPos += 28;
  }
}
