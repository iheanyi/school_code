// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// Otter.h header file

#include "SDL/SDL.h"
#include "sprite.h"
#include <vector>
#include <string>

#ifndef OTTER_H
#define OTTER_H

class Otter : public Sprite{
 public:
  Otter(std::string,int,int,int); //constructor
  virtual void move(); //moves otter up and down on screen
  virtual void show(SDL_Surface *); //shows correct sprite for each frame based upon otter state
  virtual void set_clips(); //sets sprite sheet position clips
  virtual int getOffSetX(); //returns x position coordinate
  virtual int getOffSetY(); //returns y position coordinate 
  virtual int collision(); //handles collision
  void handle_events(SDL_Event &); //checks for input event such as spacebar press
  bool check_collision(Sprite *); //checks for collision between otter and an obstacle
  void setIsVisible(bool); //set whether otter is visible on screen
  void setInvincible(int); //sets whether otter is invincible (ROLL state)
  int getStatus(); //returns state of otter
  void setOffSetY(int); //sets y position coordinate of otter
  void setStarting(bool); //sets variable tracking whether game is just starting
  void setDead(bool); //sets variable tracking whether otter is dead

protected:
  bool isVisible; //otter shown on screen
  bool isStarting; //very start of game
  bool isDead; //whether otter has died
  //states
  const int SPRITE_DOWN;
  const int SPRITE_UP;
  const int SPRITE_WALK;
  const int ROLL;
};

#endif
  
