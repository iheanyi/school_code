/* BankAccount.h 

Iheanyi Ekechukwu */
#include <iostream>
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

using namespace std;

class BankAccount {
  public:
    BankAccount();
    void print();
    void setLoot();
  protected:
    int balance;	// Current Balance
    int loot;
    string FName; // First name
    string LName; // Last name
    int AccountNum;	//Account Number
};

class Checking: public BankAccount {
  public:
   Checking();
   void print();
  protected:
};


#endif