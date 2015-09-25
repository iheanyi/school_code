// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// menuScreen.h header file

#include "SDL/SDL.h"
#include "sprite.h"
#include <vector>
#include <string>

#ifndef MENU_H
#define MENU_H

class MenuScreen : public Sprite{
 public:
 	MenuScreen(std::string,int,int,int);  //constructor
  	virtual void move(); //virtual function from inheritance
  	virtual void show(SDL_Surface *); //shows either start up screen or endgame screen
  	virtual void set_clips(); //sets sprite sheet clip positions
  	virtual int getOffSetX(); //returns x position of center
  	virtual int getOffSetY(); //returns y position of center
	virtual int collision(); //virtual function from inheritance
	bool handle_event(SDL_Event &); //detects events such as spacebar press
	void setHasPlayed(bool); //sets hasPlayed variable
	bool getHasPlayed(); //returns hasPlayed variable
 private:
 	bool hasPlayed; //whether game has been started at least once
	//States
	const int TITLE;
	const int REPLAY;
};

#endif
