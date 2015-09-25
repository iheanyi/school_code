/* TwoDayPackage.h

*/
#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include <iostream>
#include "Package.h"

using namespace std;

class TwoDayPackage: public Package {
  public:
    TwoDayPackage();
    double flat_fee;
    double CalculateCost();
};

#endif