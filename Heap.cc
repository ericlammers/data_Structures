#include "Heap.h"

#include <iostream>
#include <math.h>
#include <algorithm>

Heap::Heap() : values(0){
}

int Heap::leftChildIndex(int index){
	if((2*index) + 1 > values.size()) return -1;
	return (2*index) + 1;
}

int Heap::rightChildIndex(int index){
	if((2*index) + 2 > values.size()) return -1;
	return (2*index) + 2;}

int Heap::parentIndex(int index){
	if(index == 0 || index > values.size()) return -1;
	return (index - 1)/2;
}

// Insert does at most logn comparisons  (if the element added is the new largest element in the heap)
// Insert takes O(logn) time
int Heap::insert(int num){
	if(num < 0) return -1;
	values.push_back(num);
	int index = values.size() - 1;

	// add the element to the last index in the vector
	// compare it to the parent, if it is larger switch the two
	// this is at most logn comparisons
	while(index != 0 && values[index] > values[parentIndex(index)]) {
		values[index] = values[parentIndex(index)];
		values[parentIndex(index)] = num;
		index = parentIndex(index);
	}
	return num;
}

int Heap::removeLargestElement(){
	if(size() == 0) return -1;

	int index = values.size() - 1;
	int numToDelete = values[0];
	values[0] = values[index];
	values.pop_back();

	shiftDown(0);

	return numToDelete;
}


// Inserting n = size elements, Insert takes at most logn time => worst case = nlogn
// topDownHeapify takes O(nlogn) time
int Heap::topDownHeapify(int* intArray, int size) {
	int success;
	int amountInserted = 0;

	// Insert n = size elements => this takes at most nlogn time 
	// (since insert takes at most logn time)
	for(int i = 0; i < size; i++) {
		success = insert(intArray[i]);
		if(success > 0) amountInserted++;
	}
	return amountInserted;
}

// O(n), since we only encounter logn time when the node being shifted down is the root
// The worst case improves as the number of nodes increases making this more efficient then
// Shifting up
// So worsts case are as follows:
//  For: 1 Node (level 0) : logn
//       2 Nodes (level 1) : log(n-1)
//       4 Nodes (Level 2) : log(n-2)
//     2^i Nodes (Level i) : log(n - i)
//     2^t Nodes (Level t) : log1 = 0 // last level it takes no time
int Heap::bottomUpHeapify(int* intArray, int size) {
	// throw all the elements into the vector in the order they are given
	// unless the number is negative
	int amountInserted = 0;
	for(int i = 0; i < size; i++) {
		if(intArray[i] > 0) {
			values.push_back(intArray[i]);
			amountInserted++;
		}
	}

	if(values.size() == 0) return -1;

	// need to find the index of the first element that is not in the last row of the tree
	int sum = 0;
	int n = 0;
	while(sum < values.size()) {
		sum += pow(2, n);
		n++;
	}
	int index = n - 1;

	while(index >= 0){
		shiftDown(index);
		index--;
	}

	return amountInserted;
}

// Takes O(logn) time, where n is the height of the node at index i
int Heap::shiftDown(int index){
	while(true) {
		if((2*index+1) >= values.size()){
			break;
		}
		else if ((2*index+2) >= values.size() || values[leftChildIndex(index)] > values[rightChildIndex(index)]) {
			if(values[index] >= values[leftChildIndex(index)]) {
				break;
			}
			// switch the values
			values[index] += values[leftChildIndex(index)];
			values[leftChildIndex(index)] = values[index] - values[leftChildIndex(index)];
			values[index] -= values[leftChildIndex(index)];
			index = leftChildIndex(index);
		}
		else {
			if(values[index] >= values[rightChildIndex(index)]) {
				break;
			}
			//switch the values
			values[index] += values[rightChildIndex(index)];
			values[rightChildIndex(index)] = values[index] - values[rightChildIndex(index)];
			values[index] -= values[rightChildIndex(index)];
			index = rightChildIndex(index);
		}
	}
	return 1;
}


int Heap::get(int i) {
	if(i < 0 || i >= values.size()) return -1;
	return values[i];
}


int Heap::size() {
	return values.size();
}