/* Savings.h

Coded by Iheanyi Ekechukwu
*/

#ifndef SAVINGS_H
#define SAVINGS_H
#include <iostream>
#include "BankAccount.h"
#include <string>

using namespace std;

class Savings: public BankAccount {
  public:
    Savings();
    void print();
  protected:
    int balance;
    int interest_rate;
    
};

#endif