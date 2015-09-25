/* main.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Distance.h"
int main(int argc, char* argv[]) {
  Distance Trip("cities.txt");
  Distance Irish("ND-2012_nospace.txt");
  
  Trip.planTrip();
    
  cout << endl;
  
  Irish.FootballTravel();

return 0;
}