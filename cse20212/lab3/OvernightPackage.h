/* OvernightPackage.h

*/
#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include <iostream>
#include "Package.h"

class OvernightPackage: public Package {
  public:
    OvernightPackage();
    double extraCostPerOunce;
    double CalculateCost();
};

#endif