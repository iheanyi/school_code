/* Othello.c

Board game Othello (Reversi) coded in ASCII and C, for two users to play.

Coded by Iheanyi Ekechukwu */ 

#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

// Function prototypes
void print_board(int board[][BOARD_SIZE]);
void default_board(int board[][BOARD_SIZE]);
void player_turn(int board[][BOARD_SIZE], int player);
void make_move(int x, int y, int board[][BOARD_SIZE], int player);
int valid_move(int x, int y, int board[][BOARD_SIZE]);
void flip_piece(int x, int y, int board[][BOARD_SIZE], int player, int dx, int dy);
void who_won(int board[][BOARD_SIZE]); 

int main ( void ) {

//Declare variables
int board[BOARD_SIZE][BOARD_SIZE];
int turnnumber = 0;	 // Decide what turn number it is
int no_moves = 4;	// Number of pieces on the board

// Welcome message
printf("*******************************************************\n");
printf("* Welcome to Othello! The main objective of this game *\n");
printf("* is to outscore your oppponent and whoever has more  *\n");
printf("* pieces remaining wins the game! Please enter moves  *\n");
printf("* in the format of 'x y', without quotes. Have fun!   *\n");
printf("*                                                     *\n"); 
printf("*                                                     *\n");
printf("*             Coded by Iheanyi Ekechukwu              *\n");
printf("*******************************************************\n\n");

// Starting positions
default_board(board);

// Gameplay Loop
while(no_moves < BOARD_SIZE*BOARD_SIZE){

	print_board(board); // Continuously prints board
	if(turnnumber % 2 == 0) {
	
		player_turn(board, 1);
		no_moves++;
}
	else if(turnnumber % 2 == 1) {

		player_turn(board, -1);
		no_moves++;

}

turnnumber++;

}

print_board(board);
who_won(board);

return 0;
}

// Custom functions

// Print board
void print_board(int board[][BOARD_SIZE]) {
int rows;
int cols; 

for(cols = 0; cols < BOARD_SIZE; cols++) {
	printf("	%d", cols);
}
printf("\n");

for(rows = 0; rows < BOARD_SIZE; rows++) {
	printf("  %d", rows);
for(cols = 0; cols < BOARD_SIZE; cols++) {
	if(board[cols][rows] > 0) {
		printf("	X");
	}
	if(board[cols][rows] < 0) {
		printf("	O");
	}
	if(board[cols][rows] == 0) {
		printf("	.");
	}
	}
printf("\n");
}
}

// Starting pieces on the board
void default_board(int board[][BOARD_SIZE]) {
	int rows;
	int cols;
	
	for(rows = 0; rows < BOARD_SIZE; rows++) {
		for(cols = 0; cols< BOARD_SIZE; cols++) {
		board[rows][cols] = 0;	
	}
	}

board[BOARD_SIZE/2][BOARD_SIZE/2] = 1;
board[BOARD_SIZE/2-1][BOARD_SIZE/2-1] = 1;
board[BOARD_SIZE/2][BOARD_SIZE/2-1] = -1;
board[BOARD_SIZE/2-1][BOARD_SIZE/2] = -1;

}

// Player's turn
void player_turn(int board[][BOARD_SIZE], int player) {
	char turn;
	int x;
	int y;
	
	if (player == 1) {
	turn = 'X';
	}
	
	if (player == -1) {
	turn = 'O';
	
	}
	
	while(1) {
	
	printf("Player %c, enter a move: ", turn);
	scanf("%d %d", &x, &y);
	
	if (valid_move(x, y, board) == 1) break;
	
	else printf("Sorry, invalid move!\n");
	
	}
	
	make_move(x, y, board, player);
}

// Check the validity of a move, if valid return 1, otherwise return 0
int valid_move(int x, int y, int board[][BOARD_SIZE]) {
  int result = 0; // Default result
  
  if(board[x+1][y] != 0 && board[x][y] == 0 && x != BOARD_SIZE-1) {
    result = 1;
  }
  
  else if(board[x-1][y] != 0 && board[x][y] == 0 && x != 0) {
   result = 1;
  }
  
  else if(board[x][y+1] != 0 && board[x][y] == 0 && y != BOARD_SIZE-1) {
   result = 1;
  }
  
  else if(board[x][y-1] != 0 && board[x][y] == 0 && y != 0) {
   result = 1; 
    
  }
  
  else if(board[x+1][y+1] != 0 && board[x][y] == 0 && x != BOARD_SIZE-1 && y != BOARD_SIZE-1) {
   result = 1; 
  }
  
  else if(board[x-1][y-1] != 0 && board[x][y] == 0 && x != 0 && y != 0) {
   result = 1;  
  }
  
  else if(board[x+1][y-1] != 0 && board[x][y] == 0 && x != BOARD_SIZE-1 && y != 0 ) {
   result = 1; 
  }
  
  else if(board[x-1][y+1] != 0 && board[x][y] == 0 && x != 0 && y != BOARD_SIZE-1) {
   result = 1;  
  }
  
  if(x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE || board[x][y] != 0) {
    result = 0;
  }
  
 return result;
}


// Make the move according to the player's input
void make_move(int x, int y, int board[][BOARD_SIZE], int player) {

board[x][y] = player;

// Flip pieces in proper directions
flip_piece(x, y, board, player, 1, 0);
flip_piece(x, y, board, player, 0, 1);
flip_piece(x, y, board, player, -1, 0);
flip_piece(x, y, board, player, 0, -1);
flip_piece(x, y, board, player, 1, 1);
flip_piece(x, y, board, player, -1, -1);
flip_piece(x, y, board, player, 1, -1);
flip_piece(x, y, board, player, -1, 1);

}

// Check for flippable pieces and flip them
void flip_piece(int x, int y, int board[][BOARD_SIZE], int player, int dx, int dy) {
int row = x;
int col = y;
int opponent = -1*player;

// Depending on the input for dx and dy, check in every direction
while(1) {
	row += dx;
	col += dy;
	
	// Don't check off the board 
	if(row >= BOARD_SIZE || row < 0 || col >= BOARD_SIZE || col < 0) break;
	
	// If opponent piece is encountered, continue next loop
	if(board[row][col] == opponent) continue;
	
	// If blank space is encountered, stop
	if(board[row][col] == 0) {
	
	break;
	}
	// If player piece is encountered, flip pieces and stop
	if(board[row][col] == player) {
		while(board[row -= dx][col -= dy] == opponent) {
			board[row][col] = player;
		}
	
	break;
	}
}
}

// Calculate the final score of the game and determine the winner
void who_won(int board[][BOARD_SIZE]) {
  int x_score = 0;
  int o_score = 0;
  int rows;
  int cols;
  
for(rows = 0; rows < BOARD_SIZE; rows++) {
  for(cols = 0; cols < BOARD_SIZE; cols++) {
	if(board[cols][rows] > 0) {
		x_score++;
	}
	if(board[cols][rows] < 0) {
		o_score++;
	}
	}
}

if(x_score > o_score) {
 printf("Player X wins!"); 
}

else if(o_score > x_score) {
printf("Player O wins!");
}

else if(x_score == o_score) {
 printf("It's a tie!");  
}

}