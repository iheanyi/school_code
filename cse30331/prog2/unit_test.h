// unit_test.h
//
// Author: Brian DuSell
// Some updates by: Raul Santelices
// Contact: cse30331fa12_tas@listserv.nd.edu
//
// Do not modify this file. Make all your changes in pqueue.cpp and, if
//   necessary, pqueue.h

/* Description:
	A small unit testing framework for C++. */

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <iostream>
#include <cstring>
#include "color.h"

/* Macro functions which allow expressions' source code to be captured along
   with their results. */
#define UNIT_TEST_TRUE( expr , name ) \
	test_true( #expr , expr , name )

#define UNIT_TEST_EQUAL( expr , expected , name ) \
	test_equal( #expr , expr , expected , name )

/* A base class for writing unit test classes. The protected run_impl function
   should be overridden to perform a series of test cases conducted with the
   helper functions and macros provided by this framework. */
class unit_test {

public:

	/* Public data members for setting the colors which are printed by the
	   test. */
	color::code normal, success, failure;
	bool color_enabled;

	/* Default constructor. */
	unit_test() :
		normal(color::cyan),
		success(color::green),
		failure(color::red),
		color_enabled(false),
		_successes(0), _total(0) {}

	/* Run the unit test. The title of the unit test is passed as a
	   parameter. */
	int run(const std::string &title, int argc, char **argv) {

		color_enabled = false;
		for(char **str = argv, **end = argv + argc; str != end; ++str) {
			if(strcmp(*str, "-c") == 0 || strcmp(*str, "--colorize") == 0) {
				color_enabled = true;
				break;
			}
		}

		_successes = _total = 0;
		make_color(normal);
		std::cout << "==== " << title << " ====";
		make_color(color::clear);
		std::cout << std::endl
			<< std::endl;

		run_impl();

		make_color(normal);
		std::cout << "==== TEST COMPLETE ====";
		make_color(color::clear);
		std::cout << std::endl
			<< std::endl
			<< "Total tests: " << _total << std::endl;
		if(failures()) make_color(failure);
		std::cout << "Failures:    " << failures();
		make_color(color::clear);
		std::cout << std::endl;
		if(successes()) make_color(success);
		std::cout << "Successes:   " << successes();
		make_color(color::clear);
		std::cout << std::endl
			<< std::endl;

		if(succeeded()) {
			make_color(success);
			std::cout << "SUCCESS";
		}
		else {
			make_color(failure);
			std::cout << "FAILURE";
		}

		make_color(color::clear);
		std::cout << std::endl
			<< std::endl;

		return succeeded() ? 0 : 1;

	}

	inline unsigned int successes() const {
		return _successes;
	}

	inline unsigned int failures() const {
		return _total - _successes;
	}

	inline unsigned int total() const {
		return _total;
	}

	inline bool succeeded() const {
		return _successes == _total;
	}

protected:

	virtual void run_impl() = 0;

	void test_true(
		const std::string &expr,
		bool actual,
		const std::string &name) {

		begin_test(name);
		std::cout << expr << " should be true" << std::endl;
		if(actual) pass();
		else {
			std::cout << "... but " << expr << " is false" << std::endl;
			fail();
		}
	}

	template <typename T>
	void test_equal(
		const std::string &expr,
		const T &actual, const T &expected,
		const std::string &name) {

		begin_test(name);
		std::cout << expr << " should equal " << expected << std::endl;
		if(actual == expected) pass();
		else {
			make_color(failure);
			std::cout << actual << " != " << expected << std::endl;
			make_color(color::clear);
			fail();
		}

	}

private:

	unsigned int _successes, _total;

	void begin_test(const std::string &name) {
		++_total;
		make_color(normal);
		std::cout << "== TEST #" << _total << ": " << name << " ==";
		make_color(color::clear);
		std::cout << std::endl;
	}

	void pass() {
		make_color(success);
		std::cout << "PASSED";
		make_color(color::clear);
		std::cout << std::endl
			<< std::endl;
		++_successes;
	}

	void fail() const {
		make_color(failure);
		std::cout << "FAILED";
		make_color(color::clear);
		std::cout << std::endl
			<< std::endl;
	}

	inline void make_color(color::code c) const {
		if(color_enabled) std::cout << c;
	}

};

#endif
