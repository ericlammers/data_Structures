#include "Heap.h"

#include <iostream>

Heap::Heap() : values(0){
}

void Heap::insert(int num){
	values.push_back(num);

	int index = values.size() - 1;

	while(index != 0 && values[index] > values[(index - 1)/2]) {
		values[index] = values[(index - 1)/2];
		values[(index - 1)/2] = num;
		index = (index - 1)/2;
	}
}

int Heap::removeLargestElement(){
	int index = values.size() - 1;
	int numToDelete = values[0];

	values[0] = values[index];
	values.pop_back();
	index = 0;

	while(true) {
		if((2*index+1) >= values.size()){
			break;
		}
		else if ((2*index+2) >= values.size() || values[2*index+1] > values[2*index+2]) {
			if(values[index] >= values[2*index+1]) {
				break;
			}
			// switch the values
			values[index] += values[2*index+1];
			values[2*index+1] = values[index] - values[2*index+1];
			values[index] -= values[2*index+1];
			index = 2*index+1;
		}
		else {
			if(values[index] >= values[2*index+2]) {
				break;
			}
			//switch the values
			values[index] += values[2*index+2];
			values[2*index+2] = values[index] - values[2*index+2];
			values[index] -= values[2*index+2];
			index = 2*index+2;
		}
	}


}

int Heap::get(int i) {
	if(i < 0 || i >= values.size()) {
		return -1;
	}
	return values[i];
}

int Heap::size() {
	return values.size();
}