/* Dictionary.cpp

*/

#include <iostream>

using namespace std;

int main() {
int ThreeCount = 0; // Number of three combinations
long long SevenCount = 0; // Number of seven combinations
char Three[3]; //Three letters
char Seven[7]; // Seven Letters


// Loop through the three letter combinations, skipping combinations with 3 letters in a row..
for(Three[0] = 'A'; Three[0] <= 'Z'; Three[0]++) {
	for(Three[1] = 'A'; Three[1] <= 'Z'; Three[1]++) {
		for(Three[2] = 'A'; Three[2] <= 'Z'; Three[2]++) {

			if(Three[2] == Three[1] && Three[1] == Three[0]) {
				continue;
			}
			else {
			ThreeCount++;
			}
		}
	}
}

cout << "Number of three letter names: " << ThreeCount << endl;

// Loop through seven letters, making sure no three are the same before continuing.
for(Seven[0] = 'A'; Seven[0] <= 'Z'; Seven[0]++) {
for(Seven[1] = 'A'; Seven[1] <= 'Z'; Seven[1]++) {
for(Seven[2] = 'A'; Seven[2] <= 'Z'; Seven[2]++) {
for(Seven[3] = 'A'; Seven[3] <= 'Z'; Seven[3]++) {
for(Seven[4] = 'A'; Seven[4] <= 'Z'; Seven[4]++) {
for(Seven[5] = 'A'; Seven[5] <= 'Z'; Seven[5]++) {
for(Seven[6] = 'A'; Seven[6] <= 'Z'; Seven[6]++) {

if((Seven[2] == Seven[1] && Seven[1] == Seven[0]) || (Seven[3] == Seven[2] && Seven[2] == Seven[1]) || (Seven[4] == Seven[3] && Seven[3] == Seven[2]) || (Seven[5] == Seven[4] && Seven[4] == Seven[3]) || (Seven[6] == Seven[5] && Seven[5]== Seven[4]) ) {

continue;

}

else SevenCount++;
}
}
}
}
}
}
}
cout << "Number of 7 letter combinations: " << SevenCount << endl;


return 0; 
}
