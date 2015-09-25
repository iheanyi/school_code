/* Klondike Simulator 

*/

#include <iostream>
#include "CardDeck.h"

using namespace std;

int main(void) {
srand(time(NULL));
CardDeck Klondike;

Klondike.solve();

return 0;
}