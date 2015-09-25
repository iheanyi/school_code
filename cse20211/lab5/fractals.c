/* Fractals.c

   This program is designed to draw a fractal shape based on the input

Coded by Iheanyi Ekechukwu */

#include <stdlib.h>
#include "gfx.h"
#include <stdio.h>
#include <math.h>

const float pi = 3.14159; 

// Function prototypes
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3);
void draw_square(int x1, int y1, int x2, int y2);
void draw_circle(int xcen, int ycen, float r);
void draw_flake(int xcen, int ycen,  int r);
void fractal_triangle(int x1, int y1, int x2, int y2, int x3, int y3);
void fractal_shrinksquare(int x1, int y1, int w);
void fractal_spiralsquare(int x1, int y1, int w, float theta, float r); 
void fractal_lace(int x1, int y1, int r);
void fractal_flake(int x1, int y1, float r);
void fractal_tree(int x1, int y1, float r, float theta);
void fractal_fern(int x1, int y1, float r, float theta);
void fractal_spiral(int x1, int y1, float r, float theta); 
 
// Main loop
int main (void) {
  // Declare and define variables
  int xsize = 800; 
  int ysize = 800;
  char input;

  // Serpinski Triangle Coordinates
  int xser1 = 0;
  int yser1 = 0;
  int xser2 = xsize;
  int yser2 = 0;
  int xser3 = xsize/2;
  int yser3 = ysize;

  // Shrinking Square Variables
  int xcen = xsize/2;
  int ycen = ysize/2;
  int widthshrink = 200; 

  // Spiral Square Variables
  int widthspiralsquare = 50;  // Width of squares for the spiral
  float theta = 0;
  float rspiral = xsize/2; // Radius of spiral

  // Circular Lace Variables
  float rlace = xsize/3; // Radius of the circle

  // Snowflake Variables
  int rflake = xsize/3; // Size of snowflake 

  // Tree variables
  int xtree = xsize/2;
  int ytree = ysize - 20;
  float rtree = xsize/3;

  // Fern variables
  int xfern = xsize/2;
  int yfern = ysize - 20;
  float rfern = 5*xsize/8;

  // Spiral spiral variables
  float rdoublespiral = xsize;

  // Open a window for drawing
  gfx_open(xsize, ysize, "Fractals");

  // While loop for drawing
  while(1) {
    input = gfx_wait();

    // Input of q, quit program
    if (input == 'q') break;

    // Number 1 pressed, draw Serpinski's triangle
    if (input == '1') {
      gfx_clear();
      fractal_triangle(xser1, yser1, xser2, yser2, xser3, yser3);
    }

    // Number 2 pressed, draw shrinking squares
    if (input == '2') {
      gfx_clear();
      fractal_shrinksquare(xcen, ycen, widthshrink);
    }

    // Number 3 pressed, draw spiral squares
    if (input == '3') { 
      gfx_clear();
      fractal_spiralsquare(xcen, ycen, widthspiralsquare, theta, rspiral); 
  }

    // Number 4 pressed, draw circular lace
    if (input == '4') {
      gfx_clear();
      fractal_lace(xcen, ycen, rlace);
    }

    // Number 5 pressed, draw snowflake
    if (input == '5') {
      gfx_clear();
      fractal_flake(xcen, ycen, rflake);
    }

    // Number 6 pressed, draw tree
    if (input == '6') {
      gfx_clear();
      fractal_tree(xtree, ytree, rtree, 3*pi/2);
  }

    // Number 7 pressed, draw fern
    if (input == '7') {
      gfx_clear();
      fractal_fern(xfern, yfern, rfern, 3*pi/2); 
  }

    // Number 8 pressed, draw spiral
    if (input == '8') {
      gfx_clear();
      fractal_spiral(xcen, ycen, rdoublespiral, 0);

    }
  }

  return 0; 
}

// Functions for drawing
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  gfx_line(x1, y1, x2, y2);
  gfx_line(x2, y2, x3, y3);
  gfx_line(x3, y3, x1, y1);

}

void draw_square(int x1, int y1, int x2, int y2) {
  gfx_line(x1, y1, x2, y1);
  gfx_line(x2,y1,x2,y2);
  gfx_line(x2,y2,x1,y2);
  gfx_line(x1,y2,x1,y1);
}

void draw_circle(int xcen, int ycen, float r) {
  float oldx = xcen + r;
  float oldy = ycen;
  float theta;

  for(theta = 0; theta <= 2*pi; theta += .01) {
    float newx = cos(theta)*r + xcen;
    float newy = sin(theta)*r + ycen; 
    gfx_line(oldx, oldy, newx, newy);
    oldx = newx;
    oldy = newy;
  }

}

void draw_flake(int xcen, int ycen, int r) {
  float theta;
  float newx, newy;
  for(theta = 0; theta <= 3*pi; theta += 2*pi/5) {
    newx = xcen+r*sin(theta);
    newy = ycen+r*cos(theta);
    gfx_line(xcen,ycen,newx,newy);
  }

}

// Functions for fractals
void fractal_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  // Base case
  if (abs(x2-x1) < 2) return;

  // Do something
  draw_triangle(x1,y1,x2,y2,x3,y3);

  // recursive function
  fractal_triangle(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2);
  fractal_triangle((x1+x2)/2, (y1+y2)/2, (x2+x3)/2, (y2+y3)/2, x2, y2);
  fractal_triangle((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3);
}

void fractal_shrinksquare(int x1, int y1, int w) {
  // Base case
  if (w < .01) return; 
  // Do something
  draw_square(x1-w, y1-w, x1+w, y1+w);

  // Recursive Function
     fractal_shrinksquare(x1-w, y1-w, w/3);
     fractal_shrinksquare(x1+w, y1-w, w/3);
     fractal_shrinksquare(x1+w, y1+w, w/3);
     fractal_shrinksquare(x1-w, y1+w, w/3);
}

void fractal_spiralsquare(int x1, int y1, int w, float theta, float r) {
  // Base case
  int x = r*cos(theta) + x1;
  int y = r*sin(theta) + y1; 
  
  if (theta > 10*pi) return; 

  // Do something
  draw_square(x-w,y-w,x+w,y+w);

  // Recursive function
  fractal_spiralsquare(x1, y1, 14*w/15, theta+pi/5, r*9/10);
}

void fractal_lace(int x1, int y1, int r) {
  // Base case
  if (r < 1) return;

  // Draw circle
  draw_circle(x1, y1, r);

  // Recursive function
  fractal_lace(x1+r, y1, r/3);
  fractal_lace(x1-r, y1, r/3);
  fractal_lace(x1+r*cos(pi/3), y1+r*sin(pi/3), r/3);
  fractal_lace(x1+r*cos(pi/3), y1-r*sin(pi/3), r/3);
  fractal_lace(x1-r*cos(pi/3), y1-r*sin(pi/3), r/3);
  fractal_lace(x1-r*cos(pi/3), y1+r*sin(pi/3), r/3);
}

void fractal_flake(int x1, int y1, float r) {
  // base case
  if (r < 1) return; 

  // Draw flake
  draw_flake(x1, y1, r);

  // Recursive Functions
  fractal_flake(x1-r*sin(2*pi/5), y1+r*cos(2*pi/5), r/3);
  fractal_flake(x1+r*sin(2*pi/5), y1+r*cos(2*pi/5), r/3);
  fractal_flake(x1, y1+r, r/3);
  fractal_flake(x1+r*sin(4*pi/5), y1+r*cos(4*pi/5), r/3);
  fractal_flake(x1-r*sin(4*pi/5), y1+r*cos(4*pi/5), r/3);

}

void fractal_tree(int x1, int y1, float r, float theta) {
   // Base case
   if (r < 1.0) return;

   // Draw tree
   gfx_line(x1, y1, x1+r*cos(theta), y1+r*sin(theta));

   // Recursive function
   fractal_tree(x1+r*cos(theta), y1+r*sin(theta), 2*r/3, theta + pi/6);
   fractal_tree(x1+r*cos(theta), y1+r*sin(theta), 2*r/3, theta - pi/6);
 }

 void fractal_fern(int x1, int y1, float r, float theta) {
   // Base case
   if (r < 3.0) return; 

   // Draw fern
   gfx_line(x1, y1, x1+r*cos(theta), y1+r*sin(theta));

   // Recursive function
   fractal_fern(x1+r*cos(theta), y1+r*sin(theta), r/3, theta + pi/6);
   fractal_fern(x1+r*cos(theta), y1+r*sin(theta), r/3, theta - pi/6);
   fractal_fern(x1+(r*cos(theta)/4), y1+(r*sin(theta)/4), r/3, theta + pi/6);
   fractal_fern(x1+(r*cos(theta)/4), y1+(r*sin(theta)/4), r/3, theta - pi/6);
   fractal_fern(x1+(r*cos(theta)/2), y1+(r*sin(theta)/2), r/3, theta + pi/6);
   fractal_fern(x1+(r*cos(theta)/2), y1+(r*sin(theta)/2), r/3, theta - pi/6);
   fractal_fern(x1+3*(r*cos(theta)/4), y1+3*(r*sin(theta)/4), r/3, theta + pi/6);
   fractal_fern(x1+3*(r*cos(theta)/4), y1+3*(r*sin(theta)/4), r/3, theta - pi/6);
 }

 void fractal_spiral(int x1, int y1, float r, float theta) {
   // Base case
   int x = r*cos(theta) + x1;
   int y = r*sin(theta) + y1; 
  
   if (r <= 1) {

   // Do something
   draw_circle(x, y, 0.5); 

   return; 

   }

   // Recursive function
   fractal_spiral(x1, y1, r*.9, theta+pi/5);
   fractal_spiral(x, y, r*0.3, theta+pi/5);
 }
