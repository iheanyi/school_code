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
for(int i = 0; i <= 51; i++) {
   myDeck.push_back(i); 
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
  
  if (cardNum == 1) {
   cardNum = 11; 
  }
  
  if (cardNum >= 10) {
   cardNum = 10; 
  }
  
  myDeck.pop_front();
  return cardNum;
}

void CardDeck::convertDeck() {
  for(int i = 0; i<=51; i++) {
   myDeck[i] = (myDeck[i] % 13)+1;
  }
  
}

string CardDeck::whoWon(int playTotal, int dealTotal) {
if((playTotal <= 21 && dealTotal > 21) || (playTotal <= 21 && (playTotal > dealTotal))) {
 return "player"; 
}

else if(playTotal > 21 || playTotal < dealTotal) {
 return "dealer"; 
}

else if(playTotal == dealTotal) {
 return "tie"; 
}
  
}

void CardDeck::play() {
  int playerTotal = 0;
  int compTotal = 0;
  string moveInput;
  string winner;
  int playerWins = 0;
  int compWins = 0;
  string playAgain;
  
  shuffle();
  convertDeck();

  while(1) {
    playerTotal = 0;
    compTotal = 0;
    
    if(getSize() < 15) {
    cout << "Busting out new deck..." << endl;
    myDeck.clear();	//Discard remaining cards
      //Refill with 52 fresh cards
    for(int i = 0; i < 52; i++) {
	 myDeck.push_back(i); 
      }
    cout << "Shuffling..." << endl;
    shuffle();
    convertDeck();    
    }
  while(1) {
  cout << "Player Total: " << playerTotal << endl;
  cout << "Player, would you like to (h)it or (s)tand? " << endl;
  cin >> moveInput;
  
  if(moveInput == "h") {
    playerTotal += Deal();
    cout << "Player Total: " << playerTotal << endl;
  }
  
  if(playerTotal > 21) {
   break;
  }
  
  else if(moveInput == "s") {
    break;
  }
  }
  
  
  //if(playerTotal < 21) {
  cout << "Currently dealing out dealer cards..." << endl;
  while(compTotal < 17) {
  compTotal = compTotal + Deal();
    }
  cout << "Dealer Total: " << compTotal << endl;
  //}

  //Determine who won based on totals
  winner = whoWon(playerTotal, compTotal);
  
  if(winner == "player") {
    cout << "Player wins!" << endl;
    playerWins++;
  }
  
  if(winner == "dealer") {
   cout << "Dealer wins!" << endl;
   compWins++;
  }
  
  if(winner == "tie") {
   cout << "It's a tie!" << endl; 
  }
  
  cout << "Would you like to play again (yes/no)?" << endl;
  cin >> playAgain;
  
  if(playAgain == "yes") {
    continue;
  }
  else if(playAgain == "no") {
    break;
  }
}

cout << "Player Wins: " << playerWins << endl;
cout << "Dealer Wins: " << compWins << endl;

cout << "Thanks for playing!" << endl;
}