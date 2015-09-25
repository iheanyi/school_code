/* Parse.cpp

*/

#include <vector>
#include <iterator>
#include <istream>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "parse.h"

using namespace std;

Parse::Parse(char* c) {

cout << "Program successfully initialized with filename: " << c << endl;

ifstream myfile(c);
string line;
string str;
string entry;
vector<string> tempVector; // Vector for storing ID information
int i = 0;
int j = j;
size_t found;

if (myfile.is_open()) {

	cout << "Successfully opened file." << endl;

	while(myfile.good()) {
		while(getline(myfile,line)) {
			stringstream ss(line);

			while(getline(ss, entry, ',')) {
				if(entry.at(0) == '"') {
					tempVector.push_back(string(entry, 1, entry.length()-2));
				}

				else {
					tempVector.push_back(entry);

				}
			}

			entryVector.push_back(tempVector);
			tempVector.clear();
		}

	}
myfile.close();

}

else {
	cout << "Invalid filename specified, please re-run program with a valid filename." << endl;
	exit(1);
}

}

void Parse::printVector() {
	vector<int>::iterator it;
	ostream_iterator<string> ot(cout, " ");

	for(int i = 0; i < entryVector.size(); ++i) {
		cout << "Found New Entry!" << endl;

		for(int j = 0; j < entryVector[i].size(); ++j) {
			cout << i << " " << j << ":" << entryVector[i][j] << endl;

		}
	}

}