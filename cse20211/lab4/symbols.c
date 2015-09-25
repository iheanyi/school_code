/* Symbols.c

  Program draws a certain shape based on the user's input. 

   Coded by Iheanyi Ekechukwu */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#include "gfx.h"

/* Function prototypes */

void drawcircle( float xcir, float ycir, float rcir);
void drawhexagon( float xhex, float yhex, float ycir);
void drawspiral( float xspi, float yspi, float rspi, int a);
void draw_one( int x, int y, int height);
void draw_two( int x, int y, int height);
void draw_neg( int x, int y, int height);
void draw_zero( int x, int y, int height); 
void draw_three( int x, int y, int height);
void draw_four( int x, int y, int height);
void draw_five( int x, int y, int height);
void draw_six( int x, int y, int height);
void draw_seven( int x, int y, int height);
void draw_eight( int x, int y, int height);
void draw_nine( int x, int y, int height);
void draw_numeral(int x, int y, int n, int height);
void draw_number(int x, int y, int height);

/* Execute main loop */ 
int main( void ) {
  int xsize = 700;
  int ysize = 700;
  char input;
  float curx;
  float cury;
  float theta;
  int radius;
  float newx;
  float newy;
  float oldx;
  float oldy;
  int height;
  int a; // Constant to control the size of the spiral
  int i;
  int randNum;

  radius = 100;
  height = 100;
  a = 1;
 
  // Open a new window for drawing
  gfx_open(xsize,ysize,"Symbols");
  
  while(1) {
    input = gfx_wait();
    curx = gfx_xpos();
    cury = gfx_ypos();
    // If 'q' is pressed, break the loop and quit
    if (input == 'q') break;

    // If 'h' is pressed, draw hexagon
    if (input == 'h') {
    drawhexagon(curx, cury, radius);
    } 
    
    // If 'c' is pressed, draw circle
    if (input == 'c') {
    drawcircle(curx, cury, radius);
    }
    
    // If 's' is pressed, draw spiral
    if (input == 's') {
    drawspiral(curx, cury, radius, a);
    }
    
    // If 'n' is pressed, draw a randomly-chosen integer
    if (input == 'n') {
      draw_number(curx, cury, height);
    }

    // If '=' is pressed, increase size of future symbols by 10 px
    if (input == '=') {
    radius += 10;
    a += 1;
    height += 10 ;
    }
    
    // If '-' is pressed, decrease the size of future symbols by 10 px
    if (input == '-') {
    radius -= 10;
    a -= 1;
    height -= 10;
    }
}
  return 0;
}

// Execute functions after main loop
void drawcircle( float xcir, float ycir, float rcir) {
      float theta;
      float newx;
      float newy;
      float oldx;
      float oldy;
      float PI = 3.14159;
      
      oldx = xcir + rcir;
      oldy = ycir;
      
        for (theta = 0; theta <= 2*PI; theta+=.01) {
        float  newx = cos(theta)*rcir+xcir;
        float  newy = sin(theta)*rcir+ycir;
        gfx_line(oldx, oldy, newx, newy);
        oldx = newx;
        oldy = newy;
}
}

void drawhexagon( float xhex, float yhex, float rhex) {
  float theta;
  float newx;
  float newy;
  float oldx;
  float oldy;
  float PI = 3.14159;
  
  oldx = xhex + rhex;
  oldy = yhex;
  
  for (theta = 0; theta <= 4*PI; theta+=PI/3) {
    newx = cos(theta)*rhex+xhex;
    newy = sin(theta)*rhex+yhex;
    gfx_line(oldx,oldy,newx,newy);
    oldx = newx;
    oldy = newy;
  }
}

void drawspiral( float xspi, float yspi, float rspi, int a) {
  float theta;
  float newx;
  float newy;
  float oldx;
  float oldy;
  float PI = 3.14159;
  
  oldx = xspi;
  oldy = yspi;
  
  for (theta = 0; theta <= 4*PI; theta+=.01) {
    newx = theta*cos(theta)*a+xspi;
    newy = theta*sin(theta)*a+yspi;
    gfx_line(oldx,oldy,newx,newy);
    oldx = newx;
    oldy = newy;
  }
}


void draw_one( int x, int y, int height) {
gfx_line(x, y, x,y+height);
}

void draw_neg( int x, int y, int height) {
gfx_line(x,y,x+height/2,y);
}

void draw_two( int x, int y, int height) {
draw_neg(x,y, height);
draw_one(x+height/2,y, height/2);
draw_neg(x,y+height/2, height);
draw_one(x, y+height/2, height/2);
draw_neg(x, y+height, height);
}

void draw_zero( int x, int y, int height) {
 draw_neg(x,y, height);
 draw_one(x,y, height);
 draw_one(x+height/2, y, height);
 draw_neg(x,y+height, height);
}

void draw_three(int x, int y, int height) {
  draw_neg(x, y, height);
  draw_one(x+height/2, y, height);
  draw_neg(x,y+height/2, height);
  draw_neg(x,y+height, height);
}

void draw_four(int x, int y, int height) {
  draw_one(x,y,height/2);
  draw_one(x+height/2,y,height);
  draw_neg(x,y+height/2,height);
}

void draw_five(int x, int y, int height) {
  draw_neg(x,y,height);
  draw_one(x,y,height/2);
  draw_neg(x,y+height/2,height);
  draw_one(x+height/2,y+height/2, height/2);
  draw_neg(x,y+height,height);
}

void draw_six( int x, int y, int height) {
  draw_one(x,y,height);
  draw_neg(x,y+height/2,height);
  draw_neg(x,y+height,height);
  draw_one(x+height/2,y+height/2,height/2);
}

void draw_seven( int x, int y, int height) {
  draw_neg(x,y,height);
  draw_one(x+height/2,y,height);
}

void draw_eight( int x, int y, int height) {
  draw_zero(x,y,height);
  draw_neg(x,y+height/2,height);
}

void draw_nine(int x, int y, int height) {
  draw_one(x+height/2,y,height);
  draw_neg(x,y,height);
  draw_neg(x,y+height/2,height);
  draw_one(x,y,height/2);
}

void draw_numeral(int x, int y, int n, int height) {
  if (n == 10) {
    draw_zero(x, y, height);
  }
  if (n == 1) {
    draw_one(x, y, height);
  }
  if (n == 2) {
    draw_two(x, y, height);
  }
  if (n == 3) {
    draw_three(x, y, height);
  }
  if (n == 4) {
    draw_four(x,y,height);
  }
  if (n == 5) {
    draw_five(x,y,height);
  }
  if (n == 6) {
    draw_six(x,y,height);
  }
  if (n == 7) {
    draw_seven(x,y,height);
  }
  if (n == 8) {
    draw_eight(x,y,height);
  }
  if (n == 9) {
    draw_nine(x,y, height);
  }
}

void draw_number(int x, int y, int height) {
  int randNumLoop;
  int i;
  srand( time(NULL) );
  randNumLoop = 1 + (rand() % 10);
  for(i = 0; i <= randNumLoop; i++) {
    int randNum2;
    randNum2 = 1 + (rand() % 10);
    draw_numeral(x, y, randNum2, height);
    x = x + 75;
  } 
}
