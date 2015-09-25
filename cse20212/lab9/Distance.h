/* Distance.h

Class definition for distance between two cities*/

#include <vector>
#include <iostream>
#ifndef DISTANCE_H
#define DISTANCE_H

using namespace std;
class Distance {
  
  public:
    Distance(char*);
    void printLocations();
    void planTrip();
    void FootballTravel();
    int roadTrip();
  
  private:
    vector< vector<int> > DistanceVector;
    vector<int> Choices;
    vector<string> Cities;
};

#endif