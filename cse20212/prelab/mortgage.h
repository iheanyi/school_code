/* Mortgage.h

Mortgage class definition

Coded by Iheanyi Ekechukwu */

#include <iostream>

using namespace std;

class Mortgage {
  public:
    Mortgage(double, double, double);
    Mortgage();
    void credit(double);
    double getPrincipal();
    void amortize();
    
  private:
    double principal;
    double yr_rate; //Yearly rate of interest
    double payment;
    double balance; // Remaining balance
    double value;
    double minterest; // Monthly interest
    int month;
};