/* Puzzle.cpp

*/

#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "Puzzle.h"

using namespace std;

Puzzle::Puzzle(char* c) {

 ostream_iterator<int> output(cout, " ");
 ifstream myfile(c);

 //Starts a new row, pushing nine 0's to each row of the Puzzle Vector. 
 for (int j = 0; j < 9; j++) {
   PuzzleVector.resize (9);
 }
 
 
// Read in data from text file to fill the Puzzle Vector.
 if(myfile.is_open()) {

   while(myfile.good()) {
     //Row, column
     for(int i = 0; i < 9; i++) {
       PuzzleVector[i].resize(9);
       for(int j = 0; j < 9; j++) {
         myfile >> PuzzleVector[i][j];
       }
     }
   }

   myfile.close();
 }
 
//Default every single value in the PossNum vector to 0 for every board piece. 
PossNum.resize(10);
 for(int j = 0; j < 9; j++) {
   PossNum[j].resize(10);
   for(int i = 0; i < 9; i ++) {
     PossNum[j][i].resize(10);
	if(PuzzleVector[j][i] == 0) {
     	 for(int k = 0; k < 10; k++) {
	    PossNum[j][i][k] = 1;	
	}
     }
	else {
	  for(int k = 0; k < 10; k++) {
	  PossNum[j][i][k] = 0;
	  }
	}
   }
 }
}


void Puzzle::solve() {



 //Check each spot to see if there is a matching number in either row
 //or column, if so, set the number at that position to 0.

 for(int j = 0; j < 9; j++) {
   for(int i = 0; i < 9; i++) {
     int num = PuzzleVector[j][i];
     for(int x = 0; x < 9; x++) {
         PossNum[j][x][num] = 0;
         PossNum[x][i][num] = 0;
     }

   }
 }
 
 //Check the boxes and set all possible value sfor that matching number in the box equal to 0.
 for(int j = 0; j < 3; j++) {
   for(int i = 0; i < 3; i++) {
     for(int r = j*3; r < j*3+3; r++) {
      for(int s = i*3; s < i*3+3; s++) {
	int num = PuzzleVector[r][s];
	for(int x = j*3; x < j*3+3; x++) {
	  for(int y = i*3; y < i*3+3; y++) {
	    PossNum[x][y][num] = 0;
	  }
      }
     }
   }
   
 }
 }
 
 //Checking singleton values in the subgrid, if there is only one value possible, insert that value.

 for(int j = 0; j < 3; j++) {
   for(int i = 0; i < 3; i++) {
     for(int k = 1; k < 10; k++) {
       int count = 0;
       int x = -1;
       int y = -1;
     for(int r = j*3; r < j*3+3; r++) {
      for(int s = i*3; s < i*3+3; s++) {
	if(PuzzleVector[r][s] == 0) {
	 if(PossNum[r][s][k]) {
	  count++;
	  x = r;
	  y = s;
	 }
	}
      }
     }
     if(count == 1) {
      PuzzleVector[x][y] = k; 
     }
   }
   
 }
 }
  
// Loops through entire board, seeing where there is only one possible value. If one possible value, place it on the
// board.
  for(int j = 0; j < 9; j++) {
   for(int i = 0; i < 9; i++) {
     if(PuzzleVector[j][i] == 0) {
     int count = 0;
     int value = 0;
     for(int k = 1; k < 10; k++) {
       if(PossNum[j][i][k] == 1) {
	 count++;
	 value = k;
       }
     }
     
     if(count == 1) {
      PuzzleVector[j][i] = value; 
     }
     }
   }
  }
  
}
void Puzzle::printFinal() {
    ostream_iterator<int> output(cout, " ");
  
 for(int i = 0; i < 9; i++) {
  copy(PuzzleVector[i].begin(), PuzzleVector[i].end(), output);
  cout << endl;
  }
}

bool Puzzle::checkDone() {
  
  for(int i = 0; i < 9; i++) {
   for(int j = 0; j< 9; j++) {
    if(PuzzleVector[j][i] == 0) {
      return false;
    }
   }
    
  }
   return true;
}
