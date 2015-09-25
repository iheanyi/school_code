/* Rotate.c

   This program is made to demonstrate circular motion with multiple shapes while also allowing the end user to change the parameters.

Coded by: Iheanyi Ekechukwu */

#include <stdio.h>
#include "gfx.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(void) {

  // Declare & Define Variables
  int xsize; // Window dimensions
  int ysize;
  char input; // For determining user input
  float curxpos; // Position (Location) of the shape
  float curypos;
  float newx;   // For drawing the circle
  float newy;
  float oldx;
  float oldy; 
  double deltat; // Change in time
  float vx; // Velocities in their respective directions
  float vy;
  int radius; // Radius of the figure
  float PI = 3.14159; // Constant PI
  float theta; // Angles
  char c; // Check for input
  float theta2; // Second theta for rotation

  radius = 30;
  xsize = 400;
  ysize = 400;
  curxpos = radius;
  curypos = ysize-radius;
  oldx = curxpos-radius;
  oldy = curypos;
  vx = 0;
  vy = 0;
  srand(time(NULL));
  deltat = 0.01;
  theta2 = 0;

  // Open a new window for drawing
  gfx_open(xsize, ysize, "Rotate");
  while(input != 'q') {
    gfx_clear();
    
    gfx_color(0,255,255);

    gfx_line(curxpos,curypos,curxpos+radius*cos(theta2),curypos+radius*sin(theta2));
    gfx_line(curxpos,curypos,curxpos-radius*cos(theta2),curypos-radius*sin(theta2));
    gfx_line(curxpos,curypos,curxpos+radius*cos(theta2),curypos-radius*sin(theta2));
    gfx_line(curxpos,curypos,curxpos-radius*cos(theta2),curypos+radius*sin(theta2));
  
    
      
    for (theta = 0; theta <= 2*PI; theta+=.01) {
      gfx_color(255,0,0);
       newx = cos(theta)*radius+curxpos;
       newy = sin(theta)*radius+curypos;
       gfx_line(oldx,oldy,newx,newy);
       oldx = newx;
       oldy = newy;
       c = gfx_event_waiting();

       if (c == 1) {
	 input = gfx_wait();
	 if (input == 1) {
	   vx += 1;
	   theta2 += PI/16;
	 }
	 if (input == 3) {
	   vx -= 1;
	   theta -= PI/16;
	 }
	 if (input =='1') {
	   gfx_color(0,255,0);
	 }
	 if (input == '2') {
	   gfx_color(0,0,255);
	 }
	 if (input == '3') {
	   gfx_color(255,0,0);
	 }
	 if (input == '4') {
	   gfx_color(255,255,255);
	 }
	 if (input == 'q') break; 
       }
    }

    if (newx >= xsize || newx <= radius) {
      vx = -vx;
    
    }
    curxpos += vx;
   
 if (vx > 0) {
    theta2 += PI/16;
    }
 if (vx < 0) {
   theta2 -= PI/16;
 }

 if (vx == 0) {
   theta2 = curxpos/curypos;
 }
    gfx_flush();
    usleep(deltat*1000000);
  }
  return 0;
}

