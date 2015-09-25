/* CardDeck.h

Header file for CardDeck.h

Coded by Iheanyi Ekechukwu */

#include <iostream>
#include <algorithm>
#include <ctime>
#include <deque>
#include <iterator>
#include <cstdlib>
#ifndef CARDDECK_H
#define CARDDECK_H

using namespace std;

class CardDeck {
  public:
    CardDeck(int);
    CardDeck();
    int getSize();
    void shuffle();
    void printDeck() const;
    int inOrder();
    int Deal();
    void Hit();
    void Stand();
    void convertDeck();
    void play();
  private:
    int size;
    deque<int> myDeck;
    string whoWon(int, int);
    
};

#endif