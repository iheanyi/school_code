/* monkey.cpp

Program for the monkey sort by Iheanyi Ekechukwu */

#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "CardDeck.h"


using namespace std;
int main() {
  CardDeck sevenDeck(8);
  CardDeck eightDeck(9);
  CardDeck nineDeck(10);
  int noShuffles7 = 0;
  int noShuffles8 = 0;
  int noShuffles9 = 0;
  srand(time (NULL));

  
  // Shuffle and determine the number of shuffles to order 7 cards
  sevenDeck.shuffle();
  
  while(sevenDeck.inOrder() != 1) { 
    sevenDeck.shuffle();
    noShuffles7++;
}
  
  cout << "Number of Shuffles to order 7 cards: " << noShuffles7;
  cout << endl;
  
 
  // Shuffle and determine the number of shuffles to order 8 cards
  eightDeck.shuffle();
  
  while(eightDeck.inOrder() == 0) {
    eightDeck.shuffle();
    noShuffles8++; 
  }
  
  cout << "Number of Shuffles to order 8 cards: " << noShuffles8;
  cout << endl;
  
  // Shuffle and determine the number of shuffles to order 9 cards
  nineDeck.shuffle();
  
  while(nineDeck.inOrder() == 0) {
    nineDeck.shuffle();
    noShuffles9++;
  }
  
  cout << "Number of Shuffles to order 9 cards: " << noShuffles9;
  cout << endl;
 
  
  return 0;
}