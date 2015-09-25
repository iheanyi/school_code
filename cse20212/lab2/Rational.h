/* Rational.h

Coded by Iheanyi Ekechukwu */

#include <iostream>
#ifndef RATIONAL_H
#define RATIONAL_H

using namespace std;
class Rational {
  public:
    Rational();
    Rational(int, int);
    void print();
    //void overload<<();
    
  private:
    int numerator;
    int denominator;
    int GCD();
};

#endif