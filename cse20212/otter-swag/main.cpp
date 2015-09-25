// Taylor Seale, Ryan Shea, Iheanyi Ekechukwu, Andrew Caron
// Fundamentals of Computing II: Final Project
// main.cpp driver file

#include "sprite.h"
#include "timer.h"
#include "background.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "gameFuncs.h"
#include "otter.h"
#include "missile.h"
#include "coin.h"
#include "fish.h"
#include "scoreCounter.h"
#include "menuScreen.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char* args[]){
    //Quit flag
    bool quit = false;

    //Initialize
    if(init() == false){
        return 1;
    }

    //set score variables
    int score = 0;
    scoreCounter scoreCount("numbers.bmp",255,255,255);

    //set obstacle variables
    srand(time(NULL));
    vector<Sprite*> obstacles;
    int action;
    int collider;
    int obstacleScore = 0;
    double obstacleTimer = 0;
    double obstacleSpawnRate=0;
    double obstacleAmplitude=50.0;
    double obstacleIntercept=50.0;
    double invincibleCheck = 0.0;
    bool expertMode = false;


    //The frame rate regulator
    Timer fps;

    //The otter
    Otter otter("otter.bmp",255,255,255);

    //The background
    Background background("background.bmp",screen);

    MenuScreen menu("menuScreens.bmp",255,0,255);
	
    bool start = false; 
    bool isExploding = false;
    int explodeCount = 0;

    // THE MUSIC
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_Music* music;
    music = Mix_LoadMUS("swag.wav");
        if(Mix_PlayingMusic() == 0) {   
    		Mix_PlayMusic(music, -1);

	}
   // THE SOUND EFFECTS
   Mix_Chunk* coin;
   Mix_Chunk* boom;
   Mix_Chunk* powerup;
   coin = Mix_LoadWAV("coin.wav");
   boom = Mix_LoadWAV("boom.wav");
   powerup = Mix_LoadWAV("powerup.wav");
			
    //While the user hasn't quit
    while(quit == false){
        //Start the frame timer
		while(start==false){ //game has not started yet
			scoreCount.setTitle(false);
			isExploding = false;
			explodeCount = 0;
	 		Timer mps;
			mps.start();
	   		//Handle events for the stick figure
			while(SDL_PollEvent(&event)){ //check for spacebar press to start game
	           	start = menu.handle_event(event); 
			}
			//sets variables and settings to initial holding values
			background.scroll(10,screen);
			menu.show(screen);
			scoreCount.show(screen);
			SDL_Flip(screen);
			SDL_Flip(menu.sprite);
			SDL_Flip(scoreCount.sprite);
			if(mps.get_ticks() < 1000 / FRAMES_PER_SECOND){
				SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - mps.get_ticks() );
		    	}
			//initialize otter variables			
			if (score > 0){
				score = 0;
				otter.setIsVisible(true);
			}
			otter.setStarting(true);
			otter.setOffSetY(-35);
	    }
	//GAME STARTED
	scoreCount.setTitle(true);
	menu.setHasPlayed(true);
	fps.start();
		
        //While there's events to handle
        while(SDL_PollEvent(&event)){
            //Handle events for the stick figure
            otter.handle_events(event);

            //If the user has Xed out the window
            if(event.type == SDL_QUIT){
                //Quit the program
                quit = true;
            }
        }
	
	//set obstacle spawn rates based on sinusoidal difficulty tracker
	if(expertMode){obstacleSpawnRate = 25*sin(obstacleTimer) + 375;}
	else{
	  obstacleSpawnRate = obstacleAmplitude*(sin(obstacleTimer)) + obstacleIntercept;
	  if(obstacleSpawnRate > 400){expertMode = true;}
	  if(score > obstacleScore + 1000){
	    obstacleAmplitude=50;
	    obstacleIntercept+=10;
	    obstacleScore = score;
	  }	
	  obstacleAmplitude -= .1;
	}
	obstacleTimer += .1;
	
    //spawn obstacles
	//missiles
	int spawnObstacle = rand()%1000 + 1;   //randomly create missles
	if (spawnObstacle < obstacleSpawnRate){
	  int randY = (rand()%11)*24 + 50;//random height
	  Missile *temp = new Missile("missiles.bmp",127,127,127,randY); //create missile
	  obstacles.push_back(temp); //add missile to obstacle pointer vector
	}
	//coins
	int spawnCoin = rand()%1000 + 1;
	if (spawnCoin < 50){
	  int randX = rand()%400 + 100;     //random x
	  Coin *money = new Coin("coins.bmp",48,120,128,randX);
	  obstacles.push_back(money);
	}
	//fish
	int spawnFish = rand()%1000 + 1;
	if(spawnFish < 3){
	  int fRandY = (rand()%10)*25 + 50; //random height
	  Fish *food = new Fish("LoveFish.bmp",85,109,143,fRandY);
	  obstacles.push_back(food);
	}

    //Move the stick figure and collision detection
	bool collide;
	otter.move(); //moves otter
	for(int i=0;i<obstacles.size();i++){ //indexes through active obstacles
	 	collide = false;
		collide = otter.check_collision(obstacles.at(i)); //checks for collision between otter and current obstacle
		if(collide){ //if collided
			action=0;
			action=obstacles.at(i)->collision(); //determines which time of obstacle has been collided with
			if (action==2){ //coin
			  score += 100;
			  Mix_PlayChannel(-1, coin, 0); //coin sound
			}	
			if (action==1){ //missile
			 Mix_PlayChannel(-1, boom, 0); //explosion sound
			  if(otter.getStatus()!=3){ //if otter not invincible(from powerup)
			      otter.setDead(true); //otter has died
			      otter.setIsVisible(false); //otter is invisible
			      collider = i; //obstacle index number that killed otter
			      isExploding = true; //trigger explosions
			      break;
			  }else{ //if otter is invincible
			    score += 200;
			  }

			}
			if (action==3){ //fish
			  Mix_PlayChannel(-1, powerup, 0);
				otter.setInvincible(1);
				invincibleCheck=0;
			}
		}
		obstacles.at(i)->move(); //moves obstacle to new position based on velocity
	}

	if(otter.getStatus()==3) //if otter invincible
	{
		//cout << endl << fps.get_ticks();
		if(invincibleCheck==0) invincibleCheck=score+2000; //if otter just turned invincible, set limit for how long
		else
		{
			if(score>=invincibleCheck)
			{
				otter.setInvincible(0); //turns otter back to normal after set limit has been reached
			}
		}
	}
	
	//increment score
	score += 7;
	scoreCount.setScore(score);

	
    //Show the otter on the screen and scroll the background
	background.scroll(10,screen);
        otter.show(screen);
	scoreCount.show(screen);
	for(int i=0;i<obstacles.size();i++){obstacles.at(i)->show(screen);}
	
    //Update the screen
        SDL_Flip(screen);
	SDL_Flip(otter.sprite);	
	for(int i=0;i<obstacles.size();i++){SDL_Flip(obstacles.at(i)->sprite);}
	SDL_Flip(scoreCount.sprite);
	
	//Cap the frame rate
        if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND){
	  SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
	}
	
	//free obstacles as they exit
	for(int i=0;i<obstacles.size();i++){
	  if(obstacles.at(i)->getOffSetX() < -50){ //if obstacle off screen
	    delete obstacles.at(i);
	    obstacles.erase(obstacles.begin()+i);
		i--;
	  }
	}

	if(isExploding){explodeCount++;} //if otter has died
	
	//resets variables at end of game for if player wants to replay
	if(explodeCount == 13){ //end of game
		start = false;
		for(int j=0; j<obstacles.size(); j++){ //deletes all obstacles
			delete obstacles.at(j);
	    	obstacles.erase(obstacles.begin()+j);
			j--;
		}
	 	obstacleScore = 0;
         	obstacleTimer = 0;
         	obstacleSpawnRate=0;
         	obstacleAmplitude=50.0;
         	obstacleIntercept=50.0;
	 	invincibleCheck = 0.0;
         	expertMode = false;
	 	otter.setDead(false);
	}

    }

    
    //Clean up
    SDL_Quit();
    
    return 0;
}
