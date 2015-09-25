/* Main.cpp

Program will be used to calculate personal mortgages.

Coded by Iheanyi Ekechukwu*/

#include <iostream>
#include <iomanip>
#include "mortgage.h"
using namespace std;

int main() {
  
//Construct a mortgage with an invalid interest rate
Mortgage bad(100000, -0.05, 5000);

// Construct a valid mortgage
Mortgage good(10000.00, 0.05, 500.00);

// Third mortgage to exemplify credit
Mortgage third;

cout << setiosflags(ios::fixed);
third.credit(10000); //Credit the mortgage
cout << "Current balance after crediting second mortgage 10K: " << third.getPrincipal() << endl;
cout << setprecision(2);
cout << "Amortization schedule for good mortgage:" << endl;
cout << setprecision(2);
good.amortize();
 
}