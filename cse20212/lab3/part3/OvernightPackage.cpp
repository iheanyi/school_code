/* OvernightPackage.cpp

*/

#include <iostream>
#include "Package.h"
#include "OvernightPackage.h"

using namespace std;

OvernightPackage::OvernightPackage() : Package() {
  extraCostPerOunce = 0.06;
}


double OvernightPackage::CalculateCost() {
 total_cost = (unit_cost*weight) + (extraCostPerOunce*weight);
 
 return total_cost;
}