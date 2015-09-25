/* C4Board.cpp

Coded by Iheanyi Ekechukwu */
#include <iostream>
#include "C4Board.h"
#include "C4Col.h"

using namespace std;

ostream &operator<<(ostream &ostr, const C4Board &B) {
  int no_cols = 7;
  ostr << " 0 1 2 3 4 5 6" << endl;
  for(int i = B.board[0].getMaxDiscs() - 1; i >= 0; i--) {
    ostr << endl;
    ostr << "|";
   for(int j = 0; j < no_cols; j++) {
    ostr << B.board[j].getDisc(i) << "|";
   }
  }
  
  return (ostr);
}

C4Board::C4Board() {
 no_cols = 7;
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
  int p1_choice = 0;
  int p2_choice = 0;
  bool p1_winner = checkWinner(player1,p1_choice);
  bool p2_winner = checkWinner(player2, p2_choice);
  
  while(p1_choice != -1 || p2_choice != -1) {
  cout << *this << endl;
  turns++;
  
  if((turns % 2)) {
    
      while(1) {
	cout << "Where do you want to place a piece, player X? ";
	cin >> p1_choice;
      
	if(p1_choice >= -1 && p1_choice < no_cols) break;
      
      }
      
      if(p1_choice == -1 || p2_choice == -1) break;
      
      board[p1_choice].addDisc(player1);
      
      p1_winner = checkWinner(player1,p1_choice);
      
      if(p1_winner == true) break;

      }
    
  else {
  
    while(1) {
      cout << "Where do you want to place a piece, player 0? ";
      cin >> p2_choice;
      if(p2_choice >= -1 && p2_choice < no_cols) break;
      }
    if(p1_choice == -1 || p2_choice == -1) break;
    
    board[p2_choice].addDisc(player2);
    
    p2_winner = checkWinner(player2, p2_choice);
    if(p2_winner == true) break;
    }
  
}
}
  
bool C4Board::checkWinner(char player, int choice) {
  bool won = false;
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
  }
  
  //Check horizontal case to the left
  for(i = 1; i < 4; i++) {
    if(board[choice-i].getDisc(j) == player) {
      left_ctr++;
    }
  }
  
  //Check vertical case
   for(i = 1; i < 4; i++) {
    if(board[choice].getDisc(j+i) == player) {
      up_ctr++;
    }
  }
  
  //Check down case
   for(i = 1; i < 4; i++) {
    if(board[choice].getDisc(j-i) == player) {
      down_ctr++;
    }
  }
  
  //Check diagonal upper right case
   for(i = 1; i < 4; i++) {
    if(board[choice+i].getDisc(j+i) == player) {
      diag_right_up_ctr++;
    }
  }
  
  //Check diagonal upper left case
  for(i = 1; i < 4; i++) {
      if(board[choice-i].getDisc(j+i) == player) {
	diag_left_up_ctr++;
      }
  }
  
  //Check diagonal lower right case
  for(i = 1; i < 4; i++) {
   if(board[choice+i].getDisc(j-i) == player) {
    diag_right_dn_ctr++; 
   }
  }
  
  //Check diagonal lower left case
  for(i = 1; i <4; i++) {
   if(board[choice-i].getDisc(j-i) == player) {
    diag_left_dn_ctr++; 
   }
  }
 
  
  if(right_ctr == 4 || left_ctr == 4 || up_ctr == 4 || down_ctr == 4 || diag_right_up_ctr == 4 || diag_left_up_ctr == 4 || diag_left_dn_ctr == 4 || diag_right_dn_ctr == 4) {
   won = true; 
  }
  
  if(won == true) {
   cout << "Player " << player << " wins!";
  }
  
  return won;
}
