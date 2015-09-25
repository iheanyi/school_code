/*
Test program for Programming Assignment #1.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include "simple_string.h"
//#include "simple_string.h"

using namespace std;
using goirish::simple_string;

/* Operator overload for printing the contents of any STL vector to an output
stream, such as cout. This is to ensure that operator<< may be used with
simple_string<std::vector<char> >. */
template <typename T>
std::ostream& operator <<(std::ostream& outs, const vector<T>& source) {
	outs << "{ ";
	for(int i = 0, n = source.size(); i < n; ++i) {
		if(i > 0) outs << ", ";
		outs << source[i];
	}
	return outs << " }";
}

/* A helper function to print a simple_string using operator<< and validate the
printed result. */
template <typename T>
void test_output(const T &s, const string &expected) {
	ostringstream stream;
	stream << s;
	cout << '[' << stream.str() << "] -- ";
	if(stream.str() == expected) cout << "PASSED" << endl;
	else {
		cout << "FAILED" << endl
			<< "\texpected:" << endl
			<< '\t' << expected << endl;
	}
}

/* A helper function for checking that two values are equal. */
template <typename T, typename U>
void test_equal(const T &t, const U &u) {
	cout << t << " == " << u <<
		" -- " << (t == u ? "PASSED" : "FAILED") << endl;
}

/* Test T = char. */
void testChar() {

	cout << "==== simple_string<char> ====" << endl << endl;

	typedef simple_string<char> CharString;

	// test_output uses operator<< to check the contents of a
	// simple_string<char>.

	// Default-constructing an empty string
	test_output(CharString(), "");

	// Constructing a list with a single element
	test_output(CharString('a'), "a");

	// Constructing a list from a null-terminated string
	CharString::NULL_ELEMENT = '\0';
	test_output(CharString("alpha"), "alpha");

	// Copy-constructing a list
	CharString string1("copy me");
	CharString string2(string1);
	test_output(string2, "copy me");

	// Adding another simple_string
	CharString string3("alpha");
	string3 += CharString(" beta");
	test_output(string3, "alpha beta");

	// Adding a null-terminated string
	string3 += " gamma";
	test_output(string3, "alpha beta gamma");

	// Adding a single character
	string3 += '.';
	test_output(string3, "alpha beta gamma.");

	// Assignment
	string3 = CharString("assign me");
	test_output(string3, "assign me");

	// Length
	CharString string4("measure me");
	test_equal(string4.length(), strlen("measure me"));

	// Subscript operator
	CharString string5("abcde");
	test_equal(string5[2], 'c');
	test_equal(string5[4], 'e');

	// Adding simple_string objects
	test_output(
	CharString("data") + CharString(" ") + CharString("structures"),
		"data structures"
	);

	// Adding a simple_string to itself
	CharString string6("repeat me");
	string6 += string6;
	test_output(string6, "repeat merepeat me");
	string6 = string6 + string6;
	test_output(string6, "repeat merepeat merepeat merepeat me");

	cout << endl;

}

void testInt() {

	cout << "==== simple_string<int> ====" << endl << endl;

	typedef simple_string<int> IntString;

	// Default-constructing an empty string
	test_output(IntString(), "");

	// Constructing a list with a single element
	test_output(IntString(5), "5");

	// Constructing a list from a 0-terminated array
	IntString::NULL_ELEMENT = 0;
	int array1[] = {1, 2, 3, 4, 5, 0};
	test_output(IntString(array1), "12345");

	// Copy-constructing a list
	test_output(IntString(IntString(array1)), "12345");

	// Adding another simple_string
	IntString string1(array1);
	string1 += IntString(array1);
	test_output(string1, "1234512345");

	// Adding a 0-terminated array
	string1 += array1;
	test_output(string1, "123451234512345");

	// Adding a single element
	string1 += 6;
	test_output(string1, "1234512345123456");

	// Assignment
	int array2[] = {7, 8, 9, 0};
	string1 = IntString(array2);
	test_output(string1, "789");

	// Length
	test_equal(string1.length(), 3u);

	// Subscript operator
	test_equal(string1[0], 7);
	test_equal(string1[2], 9);

	// Adding two simple_string objects
	test_output(IntString(array1) + IntString(array2), "12345789");

	cout << endl;

}

// ADVANCED: this test is disabled, and WILL NOT be used for grading,
//           but you can try it if you implement operators == and != for simple_string
/*void testLinkedString() {

	cout << "==== simple_string< simple_string<char> > ====" << endl
		<< endl;

	typedef simple_string<char> CharString;
	typedef simple_string<CharString> StringString;

	// Default-constructing an empty string
	test_output(StringString(), "");

	// Constructing a list with a single element
	test_output(StringString(CharString("inception")), "inception");

	// Constructing a list from an array terminated by the string "end"
	StringString::NULL_ELEMENT = CharString("end");
	CharString array1[] =
		{CharString("one"), CharString("two"), CharString("three"),
		CharString("end")};
	test_output(StringString(array1), "onetwothree");

	// Copy-constructing a list
	test_output(StringString(StringString(array1)), "onetwothree");

	// Adding another simple_string
	StringString string1(array1);
	string1 += StringString(array1);
	test_output(string1, "onetwothreeonetwothree");

	// Adding an array
	CharString array2[] =
		{CharString("four"), CharString("five"),
		CharString("end")};
	StringString string2(array1);
	string2 += array2;
	test_output(string2, "onetwothreefourfive");

	// Adding a single element
	string2 += CharString("six");
	test_output(string2, "onetwothreefourfivesix");

	// Assignment
	string1 = StringString(array2);
	test_output(string1, "fourfive");

	// Length
	test_equal(string1.length(), 2u);

	// Subscript operator
	test_output(string2[3], "four");

	// Adding two simple_string objects
	test_output(StringString(array1) + StringString(array2),
		"onetwothreefourfive");

	cout << endl;

}*/

void testVector() {

	cout << "==== simple_string< vector<char> > ====" << endl << endl;

	typedef simple_string< vector<char> > VecString;

	// Default-constructing an empty string
	test_output(VecString(), "");

	// Constructing a list with a single element
	vector<char> vector1;
	for(char c = 'a'; c <= 'e'; ++c) {
		vector1.push_back(c);
	}
	test_output(VecString(vector1), "{ a, b, c, d, e }");

	// Constructing a list from an array terminated by an empty vector
	VecString::NULL_ELEMENT = vector<char>();
	vector<char> vector2(vector1.begin(), vector1.begin() + 2);
	vector<char> array1[] = {vector2, vector2, vector<char>()};
	string output1 = "{ a, b }{ a, b }";
	test_output(VecString(array1), output1);

	// Copy-constructing a list
	test_output(VecString(VecString(array1)), output1);

	// Adding another simple_string
	VecString string1(array1);
	string1 += VecString(array1);
	test_output(string1, output1 + output1);

	// Adding an array
	string1 += array1;
	test_output(string1, output1 + output1 + output1);

	// Adding a single element
	VecString string2;
	string2 += vector<char>();
	test_output(string2, "{  }");

	// Assignment
	string1 = string2;
	test_output(string1, "{  }");

	// Length
	test_equal(string1.length(), 1u);

	// Subscript operator
	//test_equal(string2[0], vector<char>());

	// Adding two simple_string objects
//	test_output(string1 + string2, "{  }{  }");

	cout << endl;

}

int main(int argc, char **argv) {

	testChar();
	testInt();
	//testLinkedString(); // disabled test, not used for grading
	testVector();

	return 0;
}
