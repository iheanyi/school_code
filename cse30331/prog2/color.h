// color.h
//
// Author: Brian DuSell
// Contact: cse30331fa12_tas@listserv.nd.edu
//
// Do not modify this file.

/* Description:
	A simple API for changing text color on ANSI terminals. */

#ifndef COLOR_H
#define COLOR_H

#include <iostream>

namespace color {

enum code { black, red, green, yellow, blue, magenta, cyan, white, clear };

inline std::ostream &operator<<(std::ostream &output, color::code c) {
	char str[6] = {033, '[', '3', 0, 'm', 0};
	if(c == clear) {
		char *temp = str + 2;
		*temp = '0';
		*++temp = 'm';
		*++temp = 0;
	}
	else {
		str[3] = '0' + c;
	}
	return output << str;
}

}

#endif

