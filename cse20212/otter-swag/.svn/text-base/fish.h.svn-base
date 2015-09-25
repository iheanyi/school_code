// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// fish.h header file

#include "SDL/SDL.h"
#include "sprite.h"
#include <vector>
#include <string>

#ifndef FISH_H
#define FISH_H

class Fish : public Sprite{
 
public:
  Fish(std::string,int,int,int,int); //constructor
  virtual void move(); //changes the location of sprite on the screen absed on the velocity
  virtual void show(SDL_Surface *); //shows the correct sprite for the object based on frame
  virtual void set_clips(); //sets the sprite sheet clip values
  virtual int getOffSetX(); //gets the x location of object
  virtual int getOffSetY(); //gets the y location of object
  virtual int collision(); //what to do if there is a collision

protected:
  //States
  const int SWIM; 
  const int EATEN;

};

#endif
