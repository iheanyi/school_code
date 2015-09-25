/* Carnival.c

   Program is going to simulate a carnival ride.

   Coded by Iheanyi Ekechukwu */

#include <stdio.h>
#include "gfx.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

// Function prototypes
void drawSlider(float x, float y);
void drawArm(float x, float y);
void drawSpin(float x, float y, float theta);

// Main function
int main(void) {

  // Declare and define variables
  int xsize = 700;
  int ysize = 700;
  int sliderx = 250;// Slider values
  int slidery = 250;
  int armx;
  int army = slidery;
  int vx = 1; // Velocities
  int varmy = 10; // Velocities
  char input; 
  double deltat = .01;
  int spinx; 
  int spiny = slidery+25;
  float angle; 

  // Open window for drawing
  gfx_open(xsize,ysize, "Carnival");

  // Execute drawings and animations 
 while(1) {
    gfx_clear();
    
    //Slider drawing
    drawSlider(sliderx, slidery);

    if (sliderx+100 >= xsize) {
      vx = -vx;
    }
    
    if (sliderx <= 0) {
      vx = -vx;
    }

    //Arm drawing
    armx = sliderx + 50;
    drawArm(armx, army); 

    if (army >= ysize) {
      varmy = -varmy;
    }
    if (army < slidery) {
      varmy = -varmy;
    }

    //Spin drawing
    spinx = sliderx;
    drawSpin(spinx, spiny, angle);
    char c  = gfx_event_waiting();
    if (c == 1) {
      input = gfx_wait();
    if (input == 'q') break;
    }
    else {
    gfx_flush();
    usleep(deltat*1000000);
    sliderx += vx;
    army += varmy;
    spiny += varmy;
    angle += .01;
    }
  }

}

// Custom functions

void drawSlider(float x, float y) {
  gfx_line(x, y, x+100, y);
  gfx_line(x+100,y,x+100,y-50);
  gfx_line(x+100,y-50,x,y-50);
  gfx_line(x,y-50,x,y);

} 

void drawArm(float x, float y) {
  gfx_line(x, 250, x, y+25);
}

void drawSpin(float x, float y, float theta) {
  int r = 50;
  float PI = 3.14159; // PI constant
  float xcen = x;
  float ycen = y;

    gfx_line(xcen+r*cos(theta), ycen+r*sin(theta), xcen+r*cos(theta+PI/2),ycen+r*sin(theta+PI/2));
    gfx_line(xcen+r*cos(theta+PI/2),ycen+r*sin(theta+PI/2),x+r*cos(theta+PI),y+r*sin(theta+PI));
    gfx_line(xcen+r*cos(theta+PI),ycen+r*sin(theta+PI),xcen+r*cos(theta+3*PI/2),ycen+r*sin(theta+3*PI/2));
    gfx_line(xcen+r*cos(theta+3*PI/2),ycen+r*sin(theta+3*PI/2),xcen+r*cos(theta),ycen+r*sin(theta));

}
