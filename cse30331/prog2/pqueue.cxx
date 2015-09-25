// pqueue.cxx
//
// Authors: Brian DuSell
//          Raul Santelices
// Contact: cse30331fa12_tas@listserv.nd.edu
//
// This is the file where you must implement the indicated functions.
//
// Course: CSE 30331

// Description:
//	The implementation of the PriorityQueue class.

#include "pqueue.h"

#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

// TYPEDEFS for convenience (less typing)
typedef PriorityQueue::size_type size_type;

// CONSTRUCTORS

// PriorityQueue()
//   Postcondition: The PriorityQueue has been initialized with no Items.
PriorityQueue::PriorityQueue() {} // GIVEN FOR YOU -- DO NOT (RE)IMPLEMENT

// MODIFICATION MEMBER FUNCTIONS

// void PriorityQueue::insert(Item item, uint priority)
//   Postcondition: A new copy of item has been inserted with the specified
//   priority.
void PriorityQueue::insert(Item item, uint priority) {
	//  -- Student will implement this -- 4 pt

	// Push an entry onto the heap if it is empty...
	if(size() == 0) {
		ItemEntry entry;
		entry.item = item;
		entry.priority = priority;
		heap.push_back(entry);
	}


	// Else, push an entry at the next available position, then sort the heap upwards. 

	else {
		ItemEntry entry;
		entry.item = item;
		entry.priority = priority;
		heap.push_back(entry);

		size_type index = size() - 1;
		
		while(parent_priority(index) < this_priority(index) && index != 0) {
			swap_with_parent(index);
			index = parent_index(index);

			if(index == 0) break; // Prevents errors
		}

	}
}

// void PriorityQueue::pop_front()
//   Precondition: !empty()
//   Postcondition: The highest priority item has been returned and removed.
//   (If several items have equal priority, then there is no guarantee about
//   which one will come out first)
Item PriorityQueue::pop_front() {
	//  -- Student will implement this -- 4 pt

	//assert(size() > 0);

	// If ther eis only one item on the stack, save it in an entry and then delete 

	if(size() == 1) {
	ItemEntry temp_root = heap[0]; 
	heap.erase(heap.begin()+0);

	return temp_root.item;
	}


	// Else, you have to delete the out of place entry and then perform reheapification downard

	else {
		ItemEntry temp_root = heap[0];
		ItemEntry temp_last = heap[size() - 1];
		heap[0] = temp_last;
		heap[0].item = temp_last.item;
		heap[0].priority = temp_last.priority;				// Overwrite root with last entry

		heap.erase(heap.begin()+size()-1); // Erase last entry

		size_type index = 0;				// Want to start at the root

		// Reheapification downward process
		while((this_priority(index) < big_child_priority(index)) && (is_leaf(index) == 0) && (index < size())) {
			if(is_leaf(index) == 1) break;
			size_type big_index = big_child_index(index);
			//cout << "Priority: " << big_child_priority(index) << endl;
			swap_with_parent(big_index);
			index = big_index;

			

		}

		return temp_root.item;
	}
}


// NON-MODIFYING MEMBER FUNCTIONS

// Item PriorityQueue::front() const
//   Precondition: !empty()
//   Postcondition: The highest priority item has been returned.
//   (If several items have equal priority, then there is no guarantee about
//   which one will be at the front)
Item PriorityQueue::front() const {
	//  -- Student will implement this -- small or private function #1 - 0.5 pt

	//assert(heap.size() > 0);


	uint highest = 0;
	uint location = 0;

	// Loop through all elements, finding their highest value
	for(size_type i = 0; i < size(); ++i) {
		if(heap[i].priority > highest) {
			highest = heap[i].priority;
			location = i;
		}

	}
	return heap[location].item; // Return the highest item
}

// uint PriorityQueue::front_priority() const
//   Precondition: !empty()
//   Postcondition: The highest priority of all items has been returned.
uint PriorityQueue::front_priority() const {
	//  -- Student will implement this -- small or private function #2 - 0.5 pt

	//assert(heap.size() > 0);

	// Loop through all elements, finding the highest priority
	uint highest = 0;
	for(size_type i = 0; i < size(); ++i) {
		if(heap[i].priority > highest) {
			highest = heap[i].priority;
		}

	}
	return highest; // Loop through the queue, finding the highest item
}

// size_type size() const
//   Postcondition: The number of items in the priority queue has been returned.
size_type PriorityQueue::size() const {
	//  -- Student will implement this -- small or private function #3 - 0.5 pt


	size_type no_items = heap.size();

	return no_items; // Use vector.size() to get size of the Priority Queue
}

// bool empty() const
//   Postcondition: Return value is true if the priority queue has any items or false otherwise.
bool PriorityQueue::empty() const {
	//  -- Student will implement this -- small or private function #4 - 0.5 pt

	if(heap.size() > 0) {
		return false; // If size of the heap is greater than zero, return false
	}

	else { 
		return true; // Else return true
	}
}

// PRIVATE MEMBER FUNCTIONS

// Precondition: i >= 0 and i < size()
// Postcondition: The return value is the priority of the element at index i in the heap.
uint PriorityQueue::this_priority(size_type i) const {
	//  -- Student will implement this -- small or private function #5 - 0.5 pt

	//assert(i >= 0);
	//assert(i < size());
	return heap[i].priority; // Return priority of specified index
}

// Precondition: i > 0 and i < size()
// Postcondition: The priority of the parent item of the item of index i in the heap.
uint PriorityQueue::parent_priority(size_type i) const {
	//  -- Student will implement this -- small or private function #6 - 0.5 pt
	//cout << "i is: " << i << endl;
	//assert(i > 0);
	//assert(i <= size());

	return heap[parent_index(i)].priority; // Return priority of parent of specified index
}

// Precondition: i >= 0 and i < size()
// Postcondition: If item at index i has no children in the heap, then the function
// returns true. Otherwise the function returns false.
bool PriorityQueue::is_leaf(size_type i) const {
	//  -- Student will implement this -- small or private function #7 - 0.5 pt
	//assert(i >= 0);
	//assert(i < size());

	return (left_child_index(i) >= size()); // If the index of the left child of the item is greater
										    // than the size of the heap, the item is a leaf
}

// Precondition: i >= 0 and i < size()
// Postcondition: If item at index i is the root of the heap tree, then the function
// returns true. Otherwise the function returns false.
bool PriorityQueue::is_root(size_type i) const {
	//  -- Student will implement this -- small or private function #8 - 0.5 pt
	//assert(i >= 0);
	//assert(i < size());
	
	return (i == 0); // If the index specified is 0, then it should be the root of the tree. Otherwise
					 // it is not.
}

// Precondition: !is_leaf(i)
// Postcondition: The return value is the index of a child of the item of index i in the heap.
// This is the child with the larger priority.
size_type PriorityQueue::big_child_index(size_type i) const {
	//  -- Student will implement this -- small or private function #9 - 0.5 pt
	//assert(is_leaf(i) == 0);

	size_type left = left_child_index(i);
	size_type right = right_child_index(i); 

	// To make sure both are there, you have to check for a right node
	if(right < size()) {

		if(heap[left].priority > heap[right].priority) {
			return left;	// Return left, if it's priority > right priority
		}

		else {
			return right; // Else return right
		}
	}

	// Else, you just return the left node
	else {
		return left;
	}
}

// Precondition: !is_leaf(i)
// Postcondition: The return value is the priority of one child of the item of index i in the heap.
// This is the child with the larger priority.
uint PriorityQueue::big_child_priority(size_type i) const {
	//  -- Student will implement this -- small or private function #10 - 0.5 pt

	////assert(is_leaf(i) == 0);

	return heap[big_child_index(i)].priority; // -- replace with your implementation
}

// Precondition: i > 0 and i < size()
// Postcondition: The item entry at index i has been swapped with its parent entry in the heap.
void PriorityQueue::swap_with_parent(size_type i) {
	//  -- Student will implement this -- small or private function #11 - 0.5 pt

	//assert(i > 0);
	//assert(i < size());

	size_type p_index = parent_index(i); // Index of parent node

	ItemEntry child = heap[i];	// Child of parent
	ItemEntry parent = heap[p_index]; // Parent node


	heap[i] = parent; // Child node now equals parent
	heap[i].item = parent.item;
	heap[i].priority = parent.priority;

	heap[p_index] = child; // Parent now equals child
	heap[p_index].item = child.item;
	heap[p_index].priority = child.priority;

}

// PRIVATE STATIC FUNCTIONS

// Precondition: i > 0
// Postcondition: The index of the parent of an item of index i in a heap
size_type PriorityQueue::parent_index(size_type i) {
	//  -- Student will implement this -- small or private function #12 - 0.5 pt
	//assert(i > 0);

	return ((i-1)/2); // Formula for calculating parent index according to the book
}

// Postcondition: The index of the left child of an item of index i in a heap
size_type PriorityQueue::left_child_index(size_type i) {
	//  -- Student will implement this -- small or private function #13 - 0.5 pt
	return (2*i + 1); // Formula for calculating left child according to the book
}

// Postcondition: The index of the right child of an item of index i in a heap
size_type PriorityQueue::right_child_index(size_type i) {
	//  -- Student will implement this -- small or private function #14 - 0.5 pt
	return (2*i + 2); // Formula for claculating the right child location according to the book
}
