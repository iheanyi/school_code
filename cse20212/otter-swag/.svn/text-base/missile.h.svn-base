// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// missile.h header file

#include "SDL/SDL.h"
#include "sprite.h"
#include <vector>
#include <string>

#ifndef MISSILE_H
#define MISSILE_H

class Missile : public Sprite{
 public:
  Missile(std::string,int,int,int,int); //constructor
  virtual void move(); //moves missiles across screen
  virtual void show(SDL_Surface *); //shows correct animation for missiles
  virtual void set_clips(); //sets sprite sheet clip positions
  virtual int getOffSetX(); //returns x position coordinate
  virtual int getOffSetY(); //returns y position coordinate
  virtual int collision(); //processes collision with otter

protected:
  //states
  const int SHOOT;
  const int EXPLODE;
};

#endif
