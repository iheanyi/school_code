/* C4Board.h


Coded by Iheanyi Ekechukwu */

#include <iostream>
#include "C4Col.h"
#ifndef C4BOARD_H
#define C4BOARD_H

using namespace std;

class C4Board {
  public:
    C4Board();
    void display();
    void play();
  private:
    bool checkWinner(char, int);
    int no_cols; // Number of columns
    C4Col board[7];
    
};

#endif