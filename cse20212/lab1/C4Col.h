/*C4Col.h

Coded by Iheanyi Ekechukwu
*/

#include <iostream>
#ifndef C4COL_H
#define C4COL_H

using namespace std;

class C4Col {
  public:
    C4Col();		//Default constructor
    int isFull();	//Is the board full?
    char getDisc(int);	//Get current number of discs
    int getMaxDiscs();	//Get maximum number of discs
    void addDisc(char);	//Add a disc
    int getCurrentDisc(); //Get current discs in column
    
  private:
    int current_discs;	//Current number of numbers
    int max_discs;	//Maximum number of discs
    char players[10]; 	//Array of players
};

#endif