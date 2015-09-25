
/* Graph.c

Function will show an approximation of sin(x) using Taylor Series

Coded by Iheanyi Ekechukwu */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gfx.h"

/* Function prototypes */
void drawAxes( float x1, float y1, float x2, float y2);
void graphSine( float xcoord, float ycoord);
long factorial(long number);
void drawGrid(float x1, float y1, float x2, float y2);
float calculatetaylor(float x, float n); 
void graphtaylor(float n, float xcoord, float ycoord);

/* Main function */
int main (void ) {
/* Define variables */

float xsize = 500;
float ysize = 500;
float x1;
float x2;
float y1;
float y2;
char input;
float xmin;
float xmax;
 int click = 0; // Count clicks
 int degree; // case for polynomial
 float x3 = -10; 

/* Open window to draw */
gfx_open(xsize,ysize, "Graph.c");
while(1) {
   x1 = 0;
   x2 = xsize;
   y1 = 0;
   y2 = ysize;
   drawAxes(x1, y1, x2, y2);
   drawGrid(x1, y1, x2, y2); 
   input = gfx_wait();
  
   if (input == 'q') break; 
    if (input == 1) {
     click += 1; 
     if (click == 1) {
       graphSine(xsize, ysize);
     }
     if (click > 1) {
	 graphtaylor(click, xsize, ysize);
   }   
 }
 }
 return 0;
}

// Functions
void drawAxes( float x1, float y1, float x2, float y2) {
  gfx_line(x2/2, y1, x2/2, y2);
  gfx_line(x1,y2/2, x2,y2/2);
 }

void graphSine(float xcoord, float ycoord) { 
  float x1 = 0;
  float y1 = ycoord/2;
  float x2 = 0;
  float y2;
  int i;

  for(i = 0; i <= 1000; i += 1) {
    y2 = sin(x2);
    double actual_x = (xcoord/20)*(x2);
    double actual_y = (ycoord/2) - (ycoord/20)*y2;
    gfx_line(x1, y1,actual_x, actual_y);
    x1 = actual_x;
    y1 = actual_y;
    x2 = x2 + 1;
  }
}

void graphtaylor(float n, float xcoord, float ycoord) {
  srand(time( NULL));
  gfx_color(rand() % 255, rand() % 255, rand() % 255);
  n = n - 1; 
  float oldx = -10;
  float oldy = calculatetaylor(-10, n);
  float x; 
  for (x = -10; x<=10;) {
    float  y = calculatetaylor(x,n);
    double actual_x = (-xcoord/20)*x+(xcoord/2);
    double actual_y = (ycoord/2) - (ycoord/20)*y;
    gfx_line(oldx, oldy, actual_x, actual_y); 
    oldx = actual_x;
    oldy = actual_y;
    x = x + .01; 
  }
}
float calculatetaylor(float x, float n) {
  x = pow(x,n)*pow(-1,n)/factorial(n);
  return x; 
}
long factorial (long number) {
  if ( number <= 1) {
    return 1;
  }

  else {
    return ( number * factorial(number - 1));
  }
  }

void drawGrid (float x1, float y1, float x2, float y2) {
  int i = 0;  
  for( i <= 10; i++;) {
    gfx_line(x1, y1, x2, y1);
    gfx_line(x1, y1, x1, y2);
    x2 += x2/20;
    y2 += y2/20; 
  }
}
