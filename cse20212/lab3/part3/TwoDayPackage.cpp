/*TwoDayPackage.cpp

*/
#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"

using namespace std;

TwoDayPackage::TwoDayPackage() {
  //Flat fees
  flat_fee = 1.99;
  
  regBox.printLabel();
  
}

double TwoDayPackage::CalculateCost() {
  double total_cost = regBox.getTotalCost();
  double unit_cost = regBox.getUnitCost();
  double weight = regBox.getWeight();
 total_cost = (unit_cost*weight) + flat_fee;
 
 return total_cost;
}

