/* Package.h 

Coded by Iheanyi Ekechukwu
*/

#include <iostream>
#ifndef PACKAGE_H
#define PACKAGE_H

using namespace std;
class Package {
  public:
    Package();
    virtual double CalculateCost();
    void printLabel();
    double unit_cost;
    double total_cost;
    int weight;
  private:
    string send_name; //Sender's name
    string rec_name; // Recipient's name
    string send_address; // Sender's address
    string rec_address; // Recipient's address
    string send_city; //Sender's city
    string rec_city; //Recipient's city
    string send_state; // Sender's state
    string rec_state; // Recipient's state
    string send_zip; //Sender's zip code
    string rec_zip; //Recipient's zip code
};


#endif