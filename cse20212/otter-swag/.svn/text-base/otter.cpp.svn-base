// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// otter.cpp implemenation file

#include "sprite.h"
#include "otter.h"
#include "SDL/SDL.h"
#include <vector>
#include <string>

Otter::Otter(std::string filename, int r, int g, int b):Sprite(4), SPRITE_DOWN(0), SPRITE_UP(1), SPRITE_WALK(2), ROLL(3){ //constructor
    //Initialize sprite dimensions
    height = 32;
    width = 32;

    //Initialize movement variables
    offSetY = -35;
    offSetX = 50;
    velocityX = 0;
    velocityY = 0;
	
    isStarting = true;

    //Initialize animation variables
    frame = 0;
    status = SPRITE_DOWN;

    //Sprite pointer
    sprite = load_image(filename,r,g,b);

    //Initialize States
    set_clips();
    
    isVisible = true;
    isDead = false;
}

void Otter::setDead(bool dead)
{
	if(dead) isDead = true;
	else isDead = false;
}

void Otter::set_clips(){ //sets sprite sheet clip positions
    //Clip the sprites
    states[0][0].x = 215; //swim0
    states[0][0].y = 0;
    states[0][0].w = 33;
    states[0][0].h = height;

    states[0][1].x = 248; //swim1
    states[0][1].y = 0;
    states[0][1].w = 32;
    states[0][1].h = height;
    
    states[1][0].x = 411; //fall0
    states[1][0].y = 0;
    states[1][0].w = 32;
    states[1][0].h = height;
    
    states[1][1].x = 411; //fall1
    states[1][1].y = 0;
    states[1][1].w = 32;
    states[1][1].h = height;
    
    states[2][0].x = 312; //walk0
    states[2][0].y = 0;
    states[2][0].w = 33;
    states[2][0].h = height;
    
    states[2][1].x = 345; //walk1
    states[2][1].y = 0;
    states[2][1].w = 33;
    states[2][1].h = height;

    states[3][0].x = 64; //roll0
    states[3][0].y = 0;
    states[3][0].w = 33;
    states[3][0].h = height;

    states[3][1].x = 97; //roll1
    states[3][1].y = 0;
    states[3][1].w = 26;
    states[3][1].h = height;

    states[3][2].x = 123; //roll2
    states[3][2].y = 0;
    states[3][2].w = 33;
    states[3][2].h = height;

    states[3][3].x = 156; //roll3
    states[3][3].y = 0;
    states[3][3].w = 26;
    states[3][3].h = height;	
}


int Otter::getOffSetX(){ //returns x position coordinate
	return offSetX;
}

int Otter::getOffSetY(){ //returns y position coordinate
	return offSetY;
}

void Otter::setOffSetY(int num){ //sets y position coordinate
	offSetY = num;
}

void Otter::setStarting(bool val){ //sets variable tracking start of game
	isStarting = val;
}

int Otter::collision(){return 0;} //processes collision

void Otter::setIsVisible(bool vis){isVisible = vis;} //sets variable tracking whether otter is visible on screen

bool Otter::check_collision(Sprite *obstacle){ //checks for collision with an obstacle
	    if(isDead) return false; //otter has died. no need to check collisions
            if(obstacle->getHasCollided()){return false;} //if the obstacle has already been collided with, do not process
            //get x and y coodinates of obstacle
	    int x = obstacle->getOffSetX();
            int y = obstacle->getOffSetY();
	    //The sides of the collision rectangles
	    int leftOtter, leftObstacle;
	    int rightOtter, rightObstacle;
	    int topOtter, topObstacle;
	    int bottomOtter, bottomObstacle;

	    //set edges of obstacle's collision rectangle	  
	    leftObstacle = x;
	    rightObstacle = x+24;
	    topObstacle = y;
	    bottomObstacle = y+10;

		//sets edges of otter's collision rectangle based on otter's state
		if ((status == SPRITE_UP) || (frame == 0)){ //swim0
		  leftOtter = offSetX;
	    	  rightOtter = offSetX+32;
		  topOtter = offSetY+7;
	    	  bottomOtter = offSetY+31;
		}
		
		if ((status == SPRITE_UP) || (frame == 1)){ //swim1
		  leftOtter = offSetX;
	    	  rightOtter = offSetX+32;
		  topOtter = offSetY+3;
	    	  bottomOtter = offSetY+31;
		}
		
		if (status == SPRITE_DOWN){ //fall0
		  leftOtter = offSetX;
	    	  rightOtter = offSetX+32;
		  topOtter = offSetY+1;
	    	  bottomOtter = offSetY+31;
		}
		
		if (status == SPRITE_WALK){ //walk
		  leftOtter = offSetX;
	    	  rightOtter = offSetX+31;
		  topOtter = offSetY+13;
	    	  bottomOtter = offSetY+31;
		}


		if (status == ROLL && ((frame==0)||(frame==2)) ){ //roll0 and roll2
		  leftOtter = offSetX;
		  rightOtter = offSetX+33;
		  topOtter = offSetY+6;
		  bottomOtter = offSetY+32;
		}

		if (status == ROLL && ((frame==1)||(frame==3)) ){ //roll1 and roll3
		  leftOtter = offSetX;
		  rightOtter = offSetX+26;
		  topOtter = offSetY;
		  bottomOtter = offSetY+32;
		}

	    //if obstacle and otter rectangles are not overlapping on any side
	    if( bottomOtter <= topObstacle ){ //obstacle is under otter
		return false;
	    }

	    if( topOtter >= bottomObstacle ){ //obstacle is above otter
	        return false;
	    }

	    if( rightOtter <= leftObstacle ){ //obstacle has not reached otter yet
	        return false;
	    }

	    if( leftOtter >= rightObstacle ){ //obstacle has passed the otter
	        return false;
	    }

	    //if obstacle and otter rectangles are overlapping
	    return true;
}

void Otter::handle_events(SDL_Event &event){ //checks for input events such as spacebar press
    // if a key is currently pressed
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym){ //check if key pressed was spacebar
			case SDLK_SPACE: velocityY = -1*(width / 2); //set otter to move up is spacebar pressed
            break; // break once the velocity has been pressed
        }
    }
    // if the spacebar is currently unpressed
    if(event.type == SDL_KEYUP){
        //Set the velocity
        switch(event.key.keysym.sym){
            case SDLK_SPACE: velocityY = (width / 2);
            break; // break once the velocity is set
        }
    }
}

void Otter::move(){ //moves otter up and down on screen based on velocity
  if(isStarting) //if very start of the game
  {
	offSetY += (width/2); //move otter into water
	if(isStarting && offSetY>20){isStarting = false;} //if the otter is in the water
  }else{
    // increase the offSet based on the value of the velocity (up or down)
    offSetY += velocityY;

    // stop the sprite from going out of bounds
    	if(((offSetY < 20) || ( offSetY + height > SCREEN_HEIGHT)) && !isStarting){
        	offSetY -= velocityY; // balance addition of velocity so the offset will no longer change is going out of bounds
    	}
  }
}

void Otter::show(SDL_Surface *screen){ //shows correct sprite of otter for each frame based upon state
  if(isVisible){
    
    if( status != ROLL ){ //if otter is not in powerup mode
  	  // if the sprite is moving down
  	  if(velocityY > 0){
  	      // if the sprite hits the floor move to the walking state
  	      if(offSetY>(280)){
		  status = SPRITE_WALK; // set animation status to walk
	        }
		else{ // other wise continue animation for moving down
		  status = SPRITE_DOWN; // set animation status to down
	        }
	        //Move to the next frame in the animation
	        frame++;
	    }	
	    //If Sprite is moving up
	    else if(velocityY < 0 ){
		status = SPRITE_UP;
	        frame++; //Move to the next frame in the animation
	    }
	    else{
	      frame = 0;  //Restart the animation
	    }
	
	    //Loop the animation (2 frames in every animation status
	    if( frame > 1 ){
	        frame = 0;
	    }
	
	    // display the otter on the screen using the apply_surface function
	    if( status == SPRITE_UP ){ //swim
	        apply_surface(sprite, screen, &states[0][frame] ); 
	    }
	    else if( status == SPRITE_DOWN ){ //fall
	        apply_surface(sprite, screen, &states[1][frame] ); 
	    }
	    else if( status == SPRITE_WALK ){ //walk
	        apply_surface(sprite, screen, &states[2][frame] );
	    }
   
   }else{ //otter is in powerup mode
	if(frame<3){ //displays rolling animation for otter
		frame++;
	}else{
		frame=0;
	}

	apply_surface(sprite, screen, &states[3][frame] );
    }
  } 
}

void Otter::setInvincible(int on) //changes state for otter based on whether it has collected invincibility powerup
{
  if(on){ //otter invincible
    status = ROLL;
  }else{ //otter normal
    status = SPRITE_DOWN;
  }
}

int Otter::getStatus() //returns state that otter is currently in
{
	return status;
}
		
