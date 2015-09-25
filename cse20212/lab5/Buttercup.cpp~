/* Buttercup.cpp 

Coded by Iheanyi Ekechukwu */

#include <iostream>
#include <deque>
#include <vector>
#include "cdl_list.h"

using namespace std;

int main() {
cdl_list<int> myList;
int n;

cout << "What should the value of n be?";
cin >> n;

//Fill the list with the number of n elements
for(int i = 1; i < n; i++) {
  myList.insertFromFront(i); 
}

myList.reset();
//Determine where the suitor should stand
cout << "Now deleting suitors..." << endl;

while(myList.getSize() > 1) {

if(myList.currentValue() % 3 == 0) {
 myList.Delete();
 //myList.next();
 myList++;
}

else if(myList.currentValue() % 6 == 0) {
 myList.reset();
}

else {
//myList.next();
myList++;
}

}

cout << "Wesley should stand in spot: ";

myList.print();

return 0; 
}
