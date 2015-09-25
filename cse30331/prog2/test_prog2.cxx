// test_prog2.cxx
//
// Author: Brian DuSell
// Some updates by: Raul Santelices
// Contact: cse30331fa12_tas@listserv.nd.edu
//
// Do not modify this file.
// (Feel free to create your own test using this file, but do not submit it.)
//
// Course: CSE 30331

// Description:
//	The test program which will be used as the basis for grading P.A. #2.
//	It consists of two classes: one for private-member testing and the other
//	for public-only usage testing.

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <set>
#include <string>
#include <sstream>
#include "unit_test.h"
#include "pqueue.h"

using namespace std;

// typedefs to make it easier to access types within the pqueue class
typedef PriorityQueue::size_type size_type;

// HELPER FUNCTIONS FOR TESTING

// Postcondition: Popped all items. Returned true if items were sorted by
// decreasing priority. Returns false otherwise. Helper for test below.
static bool clear_sorted(PriorityQueue &pq) {
	if (pq.empty())
		return true;
	uint prev_prio = pq.front_priority();
	pq.pop_front();
	size_type sz = pq.size();
	for (size_type i = 0; i < sz; ++i) {
		// Priorities should come out in non-increasing order
		if (pq.front_priority() > prev_prio)
			return false;
		prev_prio = pq.front_priority();
		pq.pop_front();
	}
	return true;
}

// Integer log2 helper for print_heap
unsigned int log2_uint(unsigned int n) {
	unsigned int result = 0;
	while((n /= 2)) ++result;
	return result;
}

// Serialization (transformation to string) of heap's item entry
ostream& operator <<(ostream& outs, const ItemEntry& source) {
	outs << source.item << ":" << source.priority;
	return outs;
}

// Precondition: empty() and size() are correct, and i < pq.heap.size()
// Postcondition: printed a representation of the underlying heap to cout.
// Useful for debugging.
void print_heap(const char* message, PriorityQueue &pq) {
	// start with the custom message
	cout << message << endl;

	// what is printed depends on whether the heap is empty or not
	if (pq.empty())
		cout << "<Heap is empty>" << endl;
	else {
		// compute height and width of the text representation of the heap
		unsigned int h = pq.empty() ? 0 : log2_uint(pq.size()) + 1;
		unsigned int maxw = 0;
		for (int i = 0, n = pq.size(); i < n; ++i) {
			ostringstream s;
			s << pq.heap[i];
			maxw = max(maxw, (size_type)s.str().size());
		}
		maxw += 2;
		unsigned int w = maxw * (unsigned int) pow((float)2, (int)h - 1);

		// print the heap
		string line;
		unsigned int row = 0, m = 1;
		for(unsigned int i = 0, n = pq.size(); i < n; ++row, m *= 2) {
			line.assign(w, ' ');
			for(unsigned int j = 0; j < m && i < n; ++i, ++j) {
				int pos = line.size() * (1 + 2 * j) / (2 * m);
				ostringstream stream;
				stream << pq.heap[i];
				line.replace(pos, stream.str().size(), stream.str());
			}
			cout << line << endl;
		}
	}
}

void test_pqueue_private(unit_test& _tester);

// Tester class for PriorityQueue
class PQTester : public unit_test {
	friend void test_pqueue_private(unit_test& tester);
 protected:
	virtual void run_impl() {
		// Part 1: private members
		test_pqueue_private((unit_test&)*this);

		// Part 2: operations and tests for pqueue q1
		cout << "**** First priority queue: q1 ***" << endl;
		PriorityQueue q1;
		Item top_item;

		// Functions:
		UNIT_TEST_TRUE(q1.empty(),
			"The pqueue is initially empty");
		UNIT_TEST_EQUAL(q1.size(), 0u,
			"In other words, its size is 0");

		// 2.1 insert items
		q1.insert(1, 42u);
		UNIT_TEST_EQUAL(q1.size(), 1u,
			"An item is inserted");

		UNIT_TEST_TRUE(!q1.empty(),
			"The pqueue is not empty");

		q1.insert(2, 20u);
		UNIT_TEST_EQUAL(q1.size(), 2u,
			"A second item is inserted");

		UNIT_TEST_EQUAL(q1.front(), 1,
			"The largest item remains at the front");

		UNIT_TEST_EQUAL(q1.front_priority(), 42u,
			"The largest priority remains at the front");

		q1.insert(3, 50u);

		UNIT_TEST_EQUAL(q1.size(), 3u,
			"A third item is inserted");

		UNIT_TEST_EQUAL(q1.front(), 3,
			"The largest item goes to the front");

		UNIT_TEST_EQUAL(q1.front_priority(), 50u,
			"The largest priority goes to the front");

		q1.insert(4, 20u);

		UNIT_TEST_EQUAL(q1.size(), 4u,
			"A duplicate element is added");

		print_heap("Contents of q1:", q1);
		cout << endl;


		// 2.2 read and pop items
		top_item = q1.pop_front();

		UNIT_TEST_EQUAL(q1.size(), 3u,
			"An item is removed, size is decremented");

		cout << endl;
		UNIT_TEST_EQUAL(top_item, 3,
			"... and the correct item was removed");

		UNIT_TEST_EQUAL(q1.front(), 1,
			"The second largest item is now at the front");
		UNIT_TEST_EQUAL(q1.front_priority(), 42u,
			"... with the priority given to it when it was inserted");

		q1.pop_front();

		UNIT_TEST_EQUAL(q1.front(), 4,
			"The third largest item is now at the front");
		UNIT_TEST_EQUAL(q1.front_priority(), 20u,
			"... with the priority given to it when it was inserted");

		q1.pop_front();
		q1.pop_front();

		UNIT_TEST_TRUE(q1.empty(),
			"The pqueue has been emptied");

		// Part 3: operations and tests for pqueue q2
		cout << "**** Second priority queue: q2 ***" << endl;
		PriorityQueue q2;

		// prepare arrays of items and priorities to insert into pqueue
		Item items[]      = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 } ;
		uint priorities[] = { 27, 62, 73, 20, 77, 35, 79, 88, 49, 61, 68, 17, 45, 95, 1, 52, 16, 60, 54, 61, 45, 68, 67, 20, 1, 86, 21, 18, 70, 44, 66, 25, 32, 40, 63, 1, 66, 68, 83, 80, 56, 41, 85, 33, 4, 43, 50, 91, 2, 15 };
		const size_type NUM_ITEMS = sizeof(items) / sizeof(Item);
		cout << "Number of items to insert into q2: " << NUM_ITEMS << endl;
		assert(NUM_ITEMS == sizeof(priorities) / sizeof(uint));

		// while populating pqueue, keep track of greatest-priority item
		uint max_prio = 0;
		Item max_item;
		for (size_type i = 0; i < NUM_ITEMS; ++i) {
			q2.insert(items[i], priorities[i]);
			if (priorities[i] > max_prio) {
				max_prio = priorities[i];
				max_item = items[i];
			}
		}

		print_heap("Contents of q2: (best seen in a wide window or redirected to a text file)", q2);
		cout << endl;

		UNIT_TEST_EQUAL(q2.size(), NUM_ITEMS,
			"The right number of elements is in the pqueue");

		UNIT_TEST_EQUAL(q2.front(), max_item,
			"The greatest-priority item is at the front");
		UNIT_TEST_EQUAL(q2.front_priority(), max_prio,
			"... with the greatest priority");

		// remove and insert
		UNIT_TEST_EQUAL(q2.pop_front(), 14,
			"Popped greatest-priority item 14");
		UNIT_TEST_EQUAL(q2.front(), 48,
			"New top item is 48");

		q2.insert(51, 0u);
		q2.insert(52, 99u);
		UNIT_TEST_EQUAL(q2.front(), 52,
			"New top item after insertions");
		UNIT_TEST_EQUAL(q2.front_priority(), 99u,
			"New top priority after insertions");
		UNIT_TEST_EQUAL(q2.size(), 51u,
			"New size after insertions");

		UNIT_TEST_TRUE(clear_sorted(q2),
			"The big test: elements are removed in non-increasing order.");

		UNIT_TEST_TRUE(q2.empty(),
			"All elements have been removed");
	}
};

// Private-member tester that is friend of PriorityQueue
void test_pqueue_private(unit_test& _tester) {
	PQTester& tester = (PQTester&) _tester;
	cout << "PRIVATE member functions of PriorityQueue" << endl << endl;

	// Set up a large priority queue with 50 elements
	PriorityQueue pq;
	Item items[]      = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 } ;
	uint priorities[] = { 27, 62, 73, 20, 77, 35, 79, 88, 49, 61, 68, 17, 45, 95, 1, 52, 16, 60, 54, 61, 45, 68, 67, 20, 1, 86, 21, 18, 70, 44, 66, 25, 32, 40, 63, 1, 66, 68, 83, 80, 56, 41, 85, 33, 4, 43, 50, 91, 2, 15 };
	const size_type NUM_ITEMS = sizeof(items) / sizeof(Item);
	assert(NUM_ITEMS == sizeof(priorities) / sizeof(uint));
	multiset<uint> prio_set;
	size_type i;
	for (i = 0; i < NUM_ITEMS; ++i)
		pq.insert(items[i], priorities[i]);

	cout << endl;
	print_heap("PQ for testing private members:", pq);
	cout << endl;

	// Functions tested: insert
	prio_set.clear(); // make sure it's empty
	prio_set.insert(&priorities[0], &priorities[NUM_ITEMS]); // create set with all priorities
	tester.UNIT_TEST_EQUAL((size_type)prio_set.size(), pq.size(),
		"Set has same priorities as pqueue");

	// Functions tested: this_priority
	// remove all priorities found in pqueue; set should end up empty
	for (i = 0; i < NUM_ITEMS; ++i) {
		multiset<uint>::iterator it_found = prio_set.find(pq.this_priority(i));
		if (it_found == prio_set.end())
			break;
		prio_set.erase(it_found);
	}
	tester.UNIT_TEST_TRUE(prio_set.empty(),
		"The priorities in the pqueue are those inserted with the items");

	// Functions tested: parent_priority
	prio_set.clear();
	prio_set.insert(&priorities[0], &priorities[NUM_ITEMS]); // re-fill set with all priorities
	// remove pqueue priorities from set
	for (i = 1; i < NUM_ITEMS; i += 2) {
		multiset<uint>::iterator it_found = prio_set.find(pq.parent_priority(i));
		if (it_found == prio_set.end())
			break; // not in set!
		if (it_found != prio_set.find(pq.parent_priority(i+1))) // right child's parent prio should be the same
			break; // not in set!
		prio_set.erase(it_found);
	}
	tester.UNIT_TEST_EQUAL((size_type)prio_set.size(), 25u,
		"There are 25 priorities in set (from the heap leaves)");

	// Functions tested: is_root
	i = NUM_ITEMS - 1;
	while (i != ((uint)-1) && !pq.is_root(i))
		--i;
	tester.UNIT_TEST_EQUAL(i, 0u,
		"The root of the heap can be found");

	// Functions tested: is_leaf
	// remove remaining pqueue priorities from set
	for (i = 0; i < NUM_ITEMS; ++i) {
		if (pq.is_leaf(i)) {
			multiset<uint>::iterator it_found = prio_set.find(pq.this_priority(i));
			if (it_found == prio_set.end())
				break; // not in set!
			prio_set.erase(it_found);
		}
	}
	tester.UNIT_TEST_TRUE(prio_set.empty(),
		"No priorities left in the set after removing pqueue leaves");

	// check each big child from root
	bool correct_big_child_indices = true, correct_big_child_priorities = true;
	for (i = 0; i < pq.size(); ++i) {
		if (!pq.is_leaf(i)) {
			size_type j = pq.big_child_index(i);
			size_type l = PriorityQueue::left_child_index(i);
			size_type r = PriorityQueue::right_child_index(i);
			if (j != l && j != r)
				correct_big_child_indices = false;

			uint prio_l = pq.heap[l].priority;
			uint prio_r = (r < pq.heap.size())? pq.heap[r].priority : 0;
			uint prio_big_child = pq.big_child_priority(i);
			if (prio_big_child != max(prio_l, prio_r))
				correct_big_child_priorities = false;
		}
	}
	// Functions tested: big_child_index
	tester.UNIT_TEST_TRUE(correct_big_child_indices,
		"Indices of largest-priority children are correct");
	// Functions tested: big_child_priority
	tester.UNIT_TEST_TRUE(correct_big_child_priorities,
		"Priorities of largest-priority children are correct");

	// Functions tested: swap_with_parent
	for (i = 1; i < pq.size(); ++i) {
		Item item_parent = pq.heap[PriorityQueue::parent_index(i)].item;
		Item item_this = pq.heap[i].item;
		pq.swap_with_parent(i);
		if (pq.heap[PriorityQueue::parent_index(i)].item != item_this || pq.heap[i].item != item_parent)
			break;
		pq.swap_with_parent(i); // swap back into place
	}
	tester.UNIT_TEST_EQUAL(i, pq.size(),
		"Swapping all children with parents works");

	// repair pq, in case previous test broke the heap
	pq.heap.clear();
	for (i = 0; i < NUM_ITEMS; ++i)
		pq.insert(items[i], priorities[i]);

	bool correct_parent = true, correct_left = true, correct_right = true;
	for (i = 0; i < pq.size(); ++i) {
		size_type l = PriorityQueue::left_child_index(i);
		size_type r = PriorityQueue::right_child_index(i);
		if (PriorityQueue::parent_index(l) != i || PriorityQueue::parent_index(r) != i)
			correct_parent = false;
		if ((l-1)/2 != i)
			correct_left = false;
		if ((r-1)/2 != i)
			correct_right = false;
	}
	// Functions tested: parent_index
	tester.UNIT_TEST_TRUE(correct_parent,
		"Parent indices are correct");
	// Functions tested: left_child_index
	tester.UNIT_TEST_TRUE(correct_left,
		"Left children indices are correct");
	// Functions tested: right_child_index
	tester.UNIT_TEST_TRUE(correct_right,
		"Right children indices are correct");
}

int main(int argc, char **argv) {
	PQTester().run("PriorityQueue's comprehensive test", argc, argv);
	return 0;
}
