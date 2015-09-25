/* C4Board.h


Coded by Iheanyi Ekechukwu */

#include <iostream>
#include "C4Col.h"
#ifndef C4BOARD_H
#define C4BOARD_H

using namespace std;

class C4Board {
  friend ostream &operator<<(ostream &, const C4Board &);
  public:
    C4Board(); //default constructor
    C4Board(const C4Board&); //copy constructor
    ~C4Board(); //deconstructor
    int moveValid(int);
    //void display();
    void play();
  private:
    bool checkWinner(char, int);
    int no_cols; // Number of columns
    //C4Col board[7];
    C4Col *board;
    
};

#endif