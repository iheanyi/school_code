/* Pi Estimate Program

The point of the program is to keep estimate pi.

Coded by Iheanyi Ekechukwu */

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
 int no_terms; //Number of terms in the series
 int n; //Iterator
 int exp; //Exponent
 float pi = 0;
 
 
 // Enter the number of terms
 while(1) {
 cout << "Please enter the number of terms in the series (greater than or equal to 2): ";
 cin >> no_terms;
 
 if(no_terms >= 2) break;

 }
 
 for(n = 1; n < no_terms*2; n+=2) {
   pi = pi+(4*pow(-1,exp))/n;
   cout << "Estimate after " << n << " terms: " << pi << endl;
   exp++;
 }
 
 return 0;
}