/* C4Board.cpp

Coded by Iheanyi Ekechukwu */
#include <iostream>
#include "C4Board.h"
#include "C4Col.h"

using namespace std;

ostream &operator<<(ostream &ostr, const C4Board &B) {
  int cols = 7;
  ostr << " 0 1 2 3 4 5 6" << endl;
  for(int i = B.board[0].getMaxDiscs() - 1; i >= 0; i--) {
    ostr << endl;
    ostr << "|";
   for(int j = 0; j < cols; j++) {
    ostr << B.board[j].getDisc(i) << "|";
   }
  }
  
  return (ostr);
}

//Default constructor
C4Board::C4Board() {
 no_cols = 7;
 
 board = new C4Col[7];
}

//Copy constructor
C4Board::C4Board(const C4Board& b) {
  no_cols = b.no_cols;
  board = new C4Col[7];

 cout << "Copy constructor initialized" << endl;
}

//Destructor
C4Board::~C4Board() {
delete [] board;

}

/*
void C4Board::display() {
  cout << " 0 1 2 3 4 5 6" << endl;
  for(int i = board[0].getMaxDiscs() - 1; i >= 0; i--) {
    cout << endl;
    cout << "|";
   for(int j = 0; j < no_cols; j++) {
    cout << board[j].getDisc(i) << "|";
   }
  }
  
  cout << endl;
}*/
void C4Board::play() {
  int turns = 0;
  char player1 = 'X';
  char player2 = 'O';
  int p1_choice = -2;
  int choice;
  int p2_choice = -2;
  bool winner = false;
  
  while(choice != -1 || winner != true) {
 
  cout << *this << endl;
  turns++;
  
  if(turns % 2) {
    choice = -2;
    while(moveValid(choice) == false) {
	cout << "Where do you want to place a piece, player X? ";
	cin >> choice;
      	
	if(moveValid(choice) == true) break;
     }
      if(choice == -1) break;
      p1_choice = choice;
      board[p1_choice]+=player1;
      winner = checkWinner(player1, p1_choice);    

  }
  
  else {
    choice = -2;
    while(moveValid(choice) == false) {
      cout << "Where do you want to place a piece, player 0? ";
      cin >> choice;

	if(moveValid(choice == true)) break;
      }
    
    if(choice == -1) break;
    p2_choice = choice;
    board[p2_choice]+=player2;
    winner =checkWinner(player2, p2_choice); 
 } 

  if(winner == true || choice == -1) break;
}
}
  
bool C4Board::checkWinner(char player, int choice) {
  bool won;
  int i = 0;
  int j = board[choice].getCurrentDisc() - 1;
  int right_ctr = 1; //Right counter
  int left_ctr = 1;  //Left Counter
  int up_ctr = 1; //Up Counter
  int down_ctr = 1; //Down Counter
  int diag_right_up_ctr = 1; //Diagonal Right Up Counter
  int diag_left_up_ctr = 1; //Diagonal Left Up Counter
  int diag_left_dn_ctr = 1; //Diagonal Left Down Counter
  int diag_right_dn_ctr = 1; //Diagonal Right Down Counter

  //Check horizontal case to the right
  for(i = 1; i < 4; i++) {
    if(board[choice+i].getDisc(j) == player) {
     right_ctr++;
   }  
   else {
    break; 
   }
  }
  
  //Check horizontal case to the left
  for(i = 1; i < 4; i++) {
    if(board[choice-i].getDisc(j) == player) {
      left_ctr++;
    }
    else break;
  }
  
  //Check vertical case
   for(i = 1; i < 4; i++) {
    if(board[choice].getDisc(j+i) == player) {
      up_ctr++;
    }
    
    else break;
  }
  
  //Check down case
   for(i = 1; i < 4; i++) {
    if(board[choice].getDisc(j-i) == player) {
      down_ctr++;
    }
    else break;
  }
  
  //Check diagonal upper right case
   for(i = 1; i < 4; i++) {
    if(board[choice+i].getDisc(j+i) == player) {
      diag_right_up_ctr++;
    }
    else break;   /* p2_winner = checkWinner(player2, p2_choice);
    
    if(p2_winner) break; */
  }

  
  //Check diagonal upper left case
  for(i = 1; i < 4; i++) {
      if(board[choice-i].getDisc(j+i) == player) {
	diag_left_up_ctr++;	
      }
      else break;
  }

  
  //Check diagonal lower right case
  for(i = 1; i < 4; i++) {
   if(board[choice+i].getDisc(j-i) == player) {
    diag_right_dn_ctr++;
   }
   else break;
  }

//Check diagonal lower left case
  for(i = 1; i < 4; i++) {
   if(board[choice-i].getDisc(j-i) == player) {
    diag_left_dn_ctr++;
   }
   else break;
  }
  
  if(right_ctr == 4 || left_ctr == 4 || up_ctr == 4 || down_ctr == 4 || diag_right_up_ctr == 4 || diag_left_up_ctr == 4 || diag_left_dn_ctr == 4 || diag_right_dn_ctr == 4) {
   cout << *this << endl;
   cout << "Player " << player << " wins!";
   return true;
  }
  
}

int C4Board::moveValid(int col) {
  
  if((col >= -1) && (col < no_cols) && (board[col].isFull() == 0)) {
  return 1;  
  }
  
  else {
   return 0; 
  }
}
