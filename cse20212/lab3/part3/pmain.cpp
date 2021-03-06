/* pmain.cpp

Main.cpp file for Package class. */

#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main() {
TwoDayPackage TwoDay;
Package StandardBox;
OvernightPackage Overnight;


cout << "Price for Regular Delivery: $" << StandardBox.CalculateCost() << endl;

cout << "Price for Two Day Delivery: $" << TwoDay.CalculateCost() << endl;

cout << "Price for Overnight Delivery: $" << Overnight.CalculateCost() << endl;


return 0;
}