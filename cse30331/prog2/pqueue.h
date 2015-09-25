// pqueue.h
//
// Adapted from Main-Savitch example online
// Modified by: Brian DuSell
//              Raul Santelices
// Contact: cse30331fa12_tas@listserv.nd.edu
//
// Do not modify this file, except for any private members you need to add.
//
// Course: CSE 30331
//
///////////////////////////////////////////////////////////////////////////////
//
// PriorityQueue is a priority queue class for integers, implemented as a "max-heap"
// (greatest priority item is at the front of the queue)
//
// CONSTRUCTORS for the PriorityQueue class:
//   PriorityQueue()
//     Postcondition: The PriorityQueue has been initialized with no Items.
//
// MODIFICATION MEMBER FUNCTIONS for the PriorityQueue class:
//   void insert(const Item& entry, uint priority)
//     Postcondition: A new copy of entry has been inserted with the specified
//     priority.
//
//   Item pop_front()
//     Precondition: size() > 0
//     Postcondition: The highest priority item has been returned and removed.
//     (If several items have equal priority, then there is no guarantee about
//     which one will come out first)
//
// NON-MODIFYING MEMBER FUNCTIONS for the PriorityQueue class:
//
//   Item front() const
//     Precondition: size() > 0
//     Postcondition: The highest priority item has been returned.
//     (If several items have equal priority, then there is no guarantee about
//     which one will be at the front)
//
//   uint front_priority() const
//     Precondition: !empty()
//     Postcondition: The highest priority of all items has been returned.
//
//   size_type size() const
//     Postcondition: The number of items in the priority queue has been returned.
//
//   bool empty() const
//     Postcondition: Whether there are any items in the priority queue has been returned.
//
// PRIVATE MEMBER VARIABLE for the PriorityQueue class:
//   vector<ItemEntry> heap
//     A vector (an STL array) organized to follow the heap rules from Chapter 11.
//
// PRIVATE MEMBER FUNCTIONS -- see pqueue.cxx for documentation


#ifndef PQUEUE_H
#define PQUEUE_H

#include <vector>
using namespace std;

// TYPEDEFS
typedef int Item; // for data elements (NOT THE SAME AS PRIORITIES)
typedef unsigned int uint; // for priorities

// STRUCT DEFINITION to store information about one item in the pqueue
struct ItemEntry {
	Item item; // the data item
	uint priority; // the priority of the data item
};

class unit_test;

// A priority queue class for items of integer type, implemented as a "max-heap"
// (greatest priority item is at the front of the queue)
class PriorityQueue {
	friend void print_heap(const char* message, PriorityQueue &pq); // helps testing
	friend void test_pqueue_private(unit_test& tester); // helps testing
public:
	// TYPEDEFS
	typedef unsigned int size_type; // indices in heap
	// CONSTRUCTORS
	PriorityQueue();
	// MODIFICATION MEMBER FUNCTIONS
	void insert(Item item, uint priority);
	Item pop_front();
	// NON-MODIFYING MEMBER FUNCTIONS
	Item front() const;
	uint front_priority() const;
	size_type size() const;
	bool empty() const;

private:
	// PRIVATE MEMBER VARIABLES
	vector<ItemEntry> heap;
	// PRIVATE MEMBER FUNCTIONS -- see pqueue.cxx for documentation
	uint this_priority(size_type i) const;
	uint parent_priority(size_type i) const;
	bool is_root(size_type i) const;
	bool is_leaf(size_type i) const;
	size_type big_child_index(size_type i) const;
	uint big_child_priority(size_type i) const;
	void swap_with_parent(size_type i);
	// PRIVATE STATIC FUNCTIONS -- see pqueue.cxx for documentation
	static size_type parent_index(size_type i);
	static size_type left_child_index(size_type i);
	static size_type right_child_index(size_type i);
};

#endif // PQUEUE_H
