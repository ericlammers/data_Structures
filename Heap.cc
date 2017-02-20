#include "Heap.h"

#include <iostream>

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

int Heap::insert(int num){
	if(num < 0) return -1;
	values.push_back(num);
	int index = values.size() - 1;

	while(index != 0 && values[index] > values[parentIndex(index)]) {
		values[index] = values[parentIndex(index)];
		values[parentIndex(index)] = num;
		index = parentIndex(index);
	}
}

int Heap::removeLargestElement(){
	if(size() == 0) return -1;

	int index = values.size() - 1;
	int numToDelete = values[0];
	values[0] = values[index];
	values.pop_back();
	index = 0;

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

	return numToDelete;
}

int Heap::get(int i) {
	if(i < 0 || i >= values.size()) return -1;
	return values[i];
}

int Heap::size() {
	return values.size();
}