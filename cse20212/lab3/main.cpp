/* Main.cpp

*/

#include <iostream>
#include "BankAccount.h"
#include "Savings.h"
#include "BoatLoan.h"

using namespace std;

int main() {
  Savings BlackBeard_S;
  BankAccount &BlackBeard_Base = BlackBeard_S;
  BoatLoan BlackBeard_Loan;
  
  BlackBeard_S.setLoot();
  
  BlackBeard_Base.print();
  
  BlackBeard_S.print();
  
  BlackBeard_Loan.print();
 
  return 0;
}