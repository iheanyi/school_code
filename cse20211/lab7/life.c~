/* Life.c

Objective of this program is to display Conway's Game of Life.

Coded by Iheanyi Ekechukwu */

#include <stdio.h>
#include <unistd.h>
#define BOARD_SIZE 40

char current[BOARD_SIZE][BOARD_SIZE];
char future[BOARD_SIZE][BOARD_SIZE];

// Function prototypes
void print_board();
void blank_board();
void add_cell(); 
void remove_cell();
char get_input();
void play_life();
int count_alive(int x, int y);
void switch_data();

// Main function
int main(void) {
  // Declare variables
  char input;
  
  // Begin with a blank board
  blank_board();
  
  // Loop for user inputs
  while(1) {
  input = get_input();
  
   switch(input) {
     case 'a':
     add_cell();
     print_board();
     break;
     case 'r':
     remove_cell();
     print_board();
     break;
     case 'n':
     play_life();
     switch_data();
     print_board();
     break;
     case 'q':
     return 0;
     break;
     case 'p':
     while(1) {
      play_life();
      switch_data();
      printf("\033[2J\033[H");
      print_board();
      usleep(100000);
     }
   }
   
  }
  
  return 0;
}

// Print out the current state of the world
void print_board() {
  int row;
  int col;
  
  
  for(row = 0; row < BOARD_SIZE; row++) {
    for(col = 0; col < BOARD_SIZE; col++) {
     printf("%c", current[row][col]);
  }
  printf("\n");
}
}

// Originally blank board
void blank_board() {
  int row;
  int col;
  
  for(row = 0; row < BOARD_SIZE; row++) {
    for(col = 0; col < BOARD_SIZE; col++) {
      current[row][col] = ' '; //All spaces dead
      future[row][col] = ' ';
    }
  }
}
// Where a cell will be added
void add_cell() {
int x;
int y;

while(1) {
  
printf("Enter the 'x y' coordinates for new life (0 - 39): ");
scanf("%d %d", &x, &y);
getchar(); // Getting rid of the new line
printf("\n");

if(x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE) {
 break;
}

else printf("Invalid move!\n");
}

current[y][x] = 'X';

}

void remove_cell() {
int x;
int y;

printf("Enter the 'x y' coordinates to remove life (0 - 39): ");
scanf("%d %d", &x, &y);printf("\n");
getchar(); // Getting rid of the new line

while(1) {
if(x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE) {
 break;
}

else printf("Invalid move!\n");

}
current[y][x] = ' ';

}

char get_input() {
char output;

printf("Please enter what you want to input:");
scanf("%c", &output);
getchar();

return output;
}

// Apply the rules of life
void play_life() {
int row;
int col;
int neighbors;

// Judge the rules of life
for(row = 0; row < BOARD_SIZE; row++) {
  for(col = 0; col < BOARD_SIZE; col++) {
    neighbors = count_alive(row, col);
    
    if(current[row][col] == 'X' && (neighbors == 2 || neighbors == 3)) {
     future[row][col] = 'X';
    }
    
    else if(current[row][col] == ' ' && neighbors == 3) {
     future[row][col] = 'X'; 
    }
    
    else {
      future[row][col] = ' ';
    }
}
}

}

// Count the number of alive neighbors
int count_alive(int x, int y) {
int no_alive = 0;

if(current[x+1][y] == 'X' && x+1 < BOARD_SIZE)  no_alive += 1;
if(current[x-1][y] == 'X' && x-1 > 0) no_alive += 1;
if(current[x+1][y+1] == 'X' && x+1 < BOARD_SIZE && y+1 < BOARD_SIZE) no_alive += 1;
if(current[x-1][y-1] == 'X' && x-1 > 0 && y-1 > 0) no_alive += 1;
if(current[x+1][y-1] == 'X' && x+1 < BOARD_SIZE && y-1 > 0) no_alive += 1;
if(current[x-1][y+1] == 'X' && x-1 > 0 && y+1 < BOARD_SIZE) no_alive += 1;
if(current[x][y+1] == 'X' && y+1 < BOARD_SIZE) no_alive += 1;
if(current[x][y-1] == 'X' && y-1 > 0) no_alive+= 1;

return no_alive;
}

// Replace the current world with the future world
void switch_data() {
  int row;
  int col;
  
 // Set current board's values to the next generation
for(row = 0; row < BOARD_SIZE; row++) {
  for(col = 0; col < BOARD_SIZE; col++) {
    current[row][col] = future[row][col];
  }
} 
}
