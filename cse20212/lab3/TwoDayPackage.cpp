/*TwoDayPackage.cpp

*/
#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"

using namespace std;

TwoDayPackage::TwoDayPackage() : Package() {
  //Flat fees
  flat_fee = 1.99;
  
  printLabel();
}

double TwoDayPackage::CalculateCost() {
 total_cost = (unit_cost*weight) + flat_fee;
 
 return total_cost;
}

