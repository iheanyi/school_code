/* BoatLoan.h

*/

#ifndef BOATLOAN_H
#define BOATLOAN_H
#include "BankAccount.h"

using namespace std;

class BoatLoan: public BankAccount {
  public:
    BoatLoan(); //Default Constructor
    void print();
  protected:
    int maxLootStorage;
    int numOfCannons;
    int numOfMonths; 
};

#endif