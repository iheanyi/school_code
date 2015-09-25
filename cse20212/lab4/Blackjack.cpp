/* Blackjack.cpp

Coded by Iheanyi Ekechukwu */


#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "CardDeck.h"
 
using namespace std;
int main() {
  CardDeck gameDeck;
  srand(time(NULL)); // Seed random time
  
  gameDeck.play();
  
  return 0;
}