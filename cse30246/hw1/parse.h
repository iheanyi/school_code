/* Parse.h

Parses a data file makes a data structure filled with the details */

#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#ifndef PASRSE_H
#define PARSE_H

using namespace std;

class Parse {

	public:
		Parse(char*);
		void fillVector();
		void printVector();	

	private:
		vector< vector<string> > entryVector;
};

#endif