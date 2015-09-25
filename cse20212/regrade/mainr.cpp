/* mainr.cpp

Coded by Iheanyi Ekechukwu */

#include <iostream>
#include "Rational.h"

using namespace std;

int main () {
  
cout << "*********PART 3 DEMO***********" << endl;

/*Demo*/
Rational fraction(9,3);
Rational second(5, 2);
Rational add;
Rational subtract;
Rational multiply;
Rational divide;

cout << "Arithmetic Examples" << endl;
cout << "First Fraction Demo" << endl;
fraction.print();
cout << fraction << endl;

cout << "Second Fraction Demo" << endl;
second.print();
cout << second << endl;

//Add operator
cout << "Addition Demo" << endl;
add = fraction + second;
add.print();
cout << add << endl;

//Subtract
cout << "Subtraction Demo" << endl;
subtract = fraction - second;
subtract.print();
cout << subtract << endl;

//Multiplication
cout << "Multiplication Demo" << endl;
multiply = fraction * second;
multiply.print();
cout << multiply << endl;

//Division
cout << "Division Demo" << endl;
divide = fraction / second;
divide.print();
cout << divide << endl;

//Incrementing
cout << "Increment First Fraction" << endl;
cout << "Post-fix increment: " << endl;
fraction++;
fraction.print();
cout << fraction << endl;
cout << "Pre-fix increment: " << endl;
++fraction;
fraction.print();
cout << fraction << endl;

int numerator1;
int numerator2;
int denominator1;
int denominator2;

/* Interactive Input */
cout << "Please enter the first numerator: ";
cin >> numerator1;

cout << endl << "Please enter the first denominator: ";
cin >> denominator1;

cout << endl << "Please enter the second numerator: ";
cin >> numerator2;

cout << endl << "Please enter the second denominator: ";
cin >> denominator2;

Rational one(numerator1, denominator1);
Rational two(numerator2, denominator2);

//Modulo Operator, inverses the first fraction
cout << "Inverse of First Fraction" << endl;
Rational inverse = one%1;
inverse.print();
cout << inverse << endl;

//Exponential operator, calculates the respective power
cout << "Power of the Second Fraction" << endl;
Rational power = two^3;
power.print();
cout << power << endl;

return 0;
}
