/* Driver/Test program for parse.cpp, which parses a text-file of students */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "parse.h"

using namespace std;

int main(int argc, char* argv[]) {


char buffer[256];
char * filename = buffer;

if(argc != 2) {
	cout << "Please enter a filename: " << endl;
	cin >> filename;
}

else {
		filename = argv[1];
}

Parse Student(filename);

Student.printVector();

return 0;

}