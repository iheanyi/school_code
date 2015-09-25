/* CardDeck.cpp

CardDeck constructor

Coded by Iheanyi Ekechukwu
*/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <deque>
#include <iterator>
#include <cstdlib>
#include "CardDeck.h"

using namespace std;

CardDeck::CardDeck() {
  
  deque<int> tempDeck;
  for(int i = 0; i <= 51; i++) {
   myDeck.resize(1); 
  }

 for(int i = 0; i <= 51; i++) {
   myDeck[i].resize(1);
	for(int j = 0; j < 1; j++) {
		
}
}
  
shuffle();
convertDeck();

//Initialize Piles deck, sizing each number according to the pile number
for(int i = 0; i < 7; i++) {
      Piles.resize(i+1);
}

//Deal out cards into each pile, according to its number
for(int i = 0; i < 7; i++) {
  Piles[i].resize(i+1);
  for(int j = 0; j < i+1; j++) {
    Piles[i][j] = Deal();
  }
}

//Deal cards into stock pile
while(myDeck.size() > 0) {
 Stock.push_back(Deal());
}
  
  cout << "Testing each pile" << endl;
cout << Piles[0][0] << endl;
cout << Piles[0][1] << endl;
cout << Piles[0][2] << endl;
cout << Piles[0].size() << endl;

cout << endl;

cout << Piles[1][0] << endl;
cout << Piles[1][1] << endl;
cout << Piles[1][2] << endl;
cout << Piles[1].size() << endl;

cout << endl;

cout << Piles[2][0] << endl;
cout << Piles[2][1] << endl;
cout << Piles[2][2] << endl;
cout << Piles[2].size() << endl;
cout << endl;

cout << "Stock Pile" << endl;
cout << Stock[0] << endl;
cout << Stock[1] << endl;
cout << Stock.size() << endl;

cout << "Card Deck Size" << endl;
cout << myDeck.size() << endl;

}


CardDeck::CardDeck(int num) {
  for(int i = 0; i <= num-1; i++) {
   myDeck.push_back(i); 
  }
}


int CardDeck::getSize() {
  return myDeck.size();
}

void CardDeck::shuffle() {
random_shuffle(myDeck.begin(), myDeck.end());

}

void CardDeck::printDeck() const {
  ostream_iterator<int> output(cout, ", ");
  copy(myDeck.begin(), myDeck.end(), output);
}

int CardDeck::inOrder() {
deque<int>::iterator dt;

for(dt = myDeck.begin()+1; dt != myDeck.end(); dt++) {
  if(*(dt-1) > *dt) {
    return 0; 
 }
}
  return 1;
}

int CardDeck::Deal() {
  int cardNum = myDeck.front();
  
  myDeck.pop_front();
  return cardNum;
}

void CardDeck::convertDeck() {
  for(int i = 0; i<=51; i++) {
   myDeck[i] = (myDeck[i] % 13)+1;
  }
  
}

void CardDeck::play() {
  shuffle();
  convertDeck();

  
}