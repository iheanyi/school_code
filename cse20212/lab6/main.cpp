/* Main.cpp

Prints out the Sudoku solver */

#include <iostream>
#include <fstream>
#include <vector>
#include "Puzzle.h"

using namespace std;

int main(int argc, char* argv[]) {
  Puzzle Game(argv[1]);
  
  while(!Game.checkDone()) {
  Game.solve();
  }

  cout << endl;
  cout << endl;
  Game.printFinal();

return 0;
}