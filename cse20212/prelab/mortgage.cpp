/* Mortgage.cpp

Mortgage member-function definitions.

Coded by Iheanyi Ekechukwu */

#include <iostream>
#include <iomanip>
#include "mortgage.h"
using namespace std;

Mortgage::Mortgage(double principalamount, double rate, double mpayment) {
    if (rate < 0) {
     cout << "Invalid interest rate in a constructor! Please check values in your classes and constructor for valid input!\n" << endl; 
    }
    
     principal = principalamount;
     yr_rate = rate;
     payment = mpayment;
}

Mortgage::Mortgage() {
 principal = 100000;
}

void Mortgage::credit(double value) {
  principal = principal - value;
}

double Mortgage::getPrincipal() {
  return principal;
}

void Mortgage::amortize() {
  month = 1;
  balance = principal;
  cout << setiosflags(ios::fixed);
  cout << "Month	Payment		Interest	Balance" << endl;
  
  while(balance > 0) {
  minterest = principal*(yr_rate/12);
  balance = principal + minterest - payment;
  principal = balance;
  
  if(principal < 0) {
    payment = payment + principal;
    balance = 0;
  }
  
 
  cout << month << "	$" << payment << "		$" << minterest << "		$" << balance << endl;
  cout << setprecision(2);
  
  month++;
  }
}