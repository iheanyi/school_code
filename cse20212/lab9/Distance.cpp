/* Distance.cpp 

Coded by Iheanyi Ekechukwu
*/

#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Distance.h"

using namespace std;

Distance::Distance(char* c) {
  ostream_iterator<int> output(cout, " ");
  ifstream myfile(c);
  string str;
  int dist;
  vector<int> tempVector; // Temporary vector for storing stream input

  
 if(myfile.is_open()) {
   
 getline(myfile, str); // Get first line of file (cities)
 stringstream ss(str); // Convert to a string stream
 
  while(ss.good()) {
    ss >> str;
    Cities.push_back(str);	//Push all of the locations into the cities vector 
 }
  
   while(myfile.good()) {
     //Disregard first element of the file, locations, and just insert distances into the
     //tempVector from the file.
     for(int i = 0; i < Cities.size(); i++) {
       myfile >> str;
       for(int j = 0; j < Cities.size(); j++) { 
	  myfile >> dist;
	  tempVector.push_back(dist);
       }
       
       //Push back the tempVector into the DistanceVector and clear the tempVector.
       DistanceVector.push_back(tempVector);
       tempVector.clear();
     }
   }

   myfile.close();
 }
}

void Distance::printLocations() {  
  
  // Print each city with valid number input beside it.
  for(int i = 0; i < Cities.size(); i++) {
   cout << "(" << i << ") ";
   cout << Cities[i] << endl; 
  }
}

void Distance::planTrip() {
  int input;
  
  //Display choices
  cout << "Here are the following cities you can visit: " << endl;
  printLocations();
  
  
  
  //Loops obtaining input until the user enters -1
  while(input >= 0) {
    cout << "Which location would you like to visit? (-1 to exit)";
    cin >> input;
    
    Choices.push_back(input);
  }
  
  //After loop ends, calculates the distance!
  cout << "Distance traveleled for the road trip is: "<< roadTrip() << " miles!" << endl;

}

void Distance::FootballTravel() {
  
 //Prints out the Irish football schedule based on the txt file
 cout << "Here is the Irish football schedule:" << endl;
 printLocations(); 
 
 //Home location is assumed to be very last place on the schedule. 
int home = Cities.size()-1;

 //Team starts off at home, then travel, ensures user returns to home arena after every game.
for(int i = 0; i < Cities.size(); i++) {
  Choices.push_back(home);
  Choices.push_back(i);
 }
 
cout << "The Fighting Irish Travel an estimated: " << roadTrip() << " miles!" << endl;
 
}

int Distance::roadTrip() {
 int sum = 0;
 
 //Loops through the entire choices array, calculating the total distance based on the numbers
 //stored in the Choices vector.
 for(int i = 0; i < Choices.size()-1; i++) {
  sum += (int)DistanceVector[Choices[i]][Choices[i+1]]; 
 }
  
  return sum;
}