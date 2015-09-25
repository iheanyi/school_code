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
   myDeck.push_back(i); 
  }
  
//shuffle();

//Initialize Visible deck, sizing each number according to the pile number
      Invisible.resize(7);
      Visible.resize(7);
      Suits.resize(4);

//Deal out cards into each pile, according to its number
for(int i = 0; i < 7; i++) {
  //Visible[i].resize(i+1);
  //Invisible[i].resize(i);
  for(int j = 0; j < i+1; j++) {
    if(i == j) {
    //Visible[i][0] = Deal();
    Visible[i].push_back(Deal());
    }
    else {
    //Invisible[i][j] = Deal();
    Invisible[i].push_back(Deal());
    }
  }
}

//Deal cards into stock pile
while(myDeck.size() > 0) {
 Stock.push_back(Deal());
}

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

int CardDeck::DealStock() {
 int cardNum = Stock.front();
 
 Stock.pop_front();
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

void CardDeck::printBoard() {
  ostream_iterator<int> output(cout, " ");
  
  cout << "Visible:" << endl;
  for(int i = 0; i < 7; i++) {
     copy(Visible[i].begin(), Visible[i].end(), output);
     cout << endl;
  }

  cout << "Suits Visible:" << endl;
  for(int i = 0; i < 4; i++) {
    copy(Suits[i].begin(), Suits[i].begin()+1, output); 
  }

  cout << endl;

}

int CardDeck::determineSuit(int cardNum){
    int Suit = cardNum % 4;
  
  return Suit;  
}

void CardDeck::solve() {
  int cardSuit;
  int cardNum;
  int frontCard;
  int frontSuit;
  int frontColor;
  int cardColor;
  int stockCard;
  int stockSuit;
  int stockColor;
  int suitCard;
  int stockSuitCard;
  deque<int>::iterator it;
  deque<int>::iterator ix;
  
while(!checkDone()) {
  for(int i = 0; i < 7; ++i) {
    //int length = Visible[i].size();
   for(int j = 0; j < Visible[i].size(); ++j) {
     //frontCard = Visible[i].front();
     cardNum = Visible[i][j];
     cardSuit = determineSuit(cardNum);
     cardColor = suit % 2;
     //Loop through each column, checking to see if a card can be moved in front of a card
     for(int k = 0; k < 7; ++k) {
       
       if(Visible[k].empty()) continue;
       
       frontCard = Visible[k].back();
       frontSuit = determineSuit(frontCard);
       frontColor = frontSuit % 2;
     
       suitCard = Suits[frontSuit].front();
       
       //If cardNum is opposite in color to frontCard and one less, move over entire pile
       
       if(((cardNum % 13)+1 == (frontCard % 13)) && cardColor != frontColor) {
	 it = Visible[k].end();
	 Visible[k].insert(it, Visible[i].begin()+j, Visible[i].end());
	 Visible[i].erase(Visible[i].begin()+j, Visible[i].end());
	 if(Invisible[i].empty()) continue;
	 Visible[i].push_back(Invisible[i].back());
	 Invisible[i].pop_back();
	 
       }
       
       // If frontmost card is one more than the front card in it's respective pile, move it to that pile
       else if((frontCard % 13)+1 == (suitCard % 13) + 2) {
	Suits[frontSuit].push_back(frontCard);
	Visible[k].pop_back();
       }
       
      
       //If stack is empty and there is an empty column, move king to that column
       else if(Visible[k].empty() && ((cardNum % 13) + 1 == 13)) {
	it = Visible[k].begin();
	Visible[k].insert(it, Visible[i].begin()+j, Visible[i].end());
	Visible[i].erase(Visible[i].begin()+j, Visible[i].end());
       }
       
       
       
       else {
       // Else, loop through entire stock pile, searching for a valid move
	  for(int x = 0; x < Stock.size(); x++) {
	  
	  stockCard = DealStock();
	  stockSuit = determineSuit(stockSuit);
	  stockColor = stockSuit % 2;
	  stockSuitCard = (Suits[stockSuit].front() % 13);
	  
	  if(Stock.empty()) {
	      it = Stock.begin();
	      Stock.insert(it, Discard.begin(), Discard.end());
	      Discard.erase(Discard.begin(), Discard.end());
	      continue;
	  }
	  
	  if((stockCard%13)+1 == (stockSuitCard % 13) + 2) {
		      Suits[stockSuit].push_back(stockCard);
		      break;
	    }
	    
	    else if(((stockCard % 13) + 1 == (frontCard % 13)) && stockColor != frontColor) {
		Visible[k].push_back(stockCard);
		break;
		
	    }
	    
	    else if(((stockCard%13)+1 == 13) && Visible[k].empty()) {
	      Visible[k].push_back(stockCard);
	      break;
	    }
	    
	    else {
	      Discard.push_back(stockCard); 
	    }
       
       }
       
       }
       
     
   }
  }
}
  printBoard();
}
}

int CardDeck::checkDone() {
 for(int i = 0; i < 4; i++) {
   if(Suits[i].size() < 13) return 0;
 }
 
 return 1;
}