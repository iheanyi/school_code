/* Rational.h

Coded by Iheanyi Ekechukwu */

#include <iostream>
#ifndef RATIONAL_H
#define RATIONAL_H

using namespace std;
class Rational {
   friend ostream &operator<<(ostream &, const Rational &);
  
  public:
   //Member functions
   Rational();
   Rational(int, int);
   void print() const;
   
   //Arithmetic Operator Overloading  
   friend Rational operator+( Rational &r1, Rational &r2);
   friend Rational operator-( Rational &r1, Rational &r2);
   friend Rational operator*( Rational &r1, Rational &r2);
   friend Rational operator/( Rational &r1, Rational &r2);
   
   //Incrementers/Decrementers Operators Overloading
   Rational& operator++(); //prefix
   Rational operator++(int); //postfix

   //Custom Overload for Part 3
   Rational operator%(int);
   Rational operator^(int);

  private:
    int numerator;
    int denominator;
    int GCD(int, int);
};

#endif
