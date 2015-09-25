 /* BankAccount.cpp

Coded by Iheanyi Ekechukwu */
#include <iostream>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount() {
  FName = "Edward";	// Default first name is Edward
  LName = "Teach";	// Default last name is Teach
  balance = 100000;	// Default Balance is $100,000
}

void BankAccount::setLoot() {
  loot = 100; 
}

void BankAccount::print() { 
  cout << "Good Evening Mr. " << LName << "." << endl;
  
  cout << FName << ", your current balance is: $" << balance << endl;
  
  cout << "You currently have " << loot << " sq. ft of loot to store!" << endl;
}


