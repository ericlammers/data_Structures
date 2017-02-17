#include <iostream>

#include "Heap.h"

using namespace std;
 
int main () {
	Heap myHeap;
	myHeap.insert(10);
	myHeap.insert(20);
	myHeap.insert(5);
	myHeap.insert(30);
	myHeap.insert(12);
	myHeap.insert(42);
	myHeap.insert(17);
	myHeap.insert(23);
	myHeap.removeLargestElement();
	myHeap.removeLargestElement();

	for(int i = 0; i < myHeap.size(); i++){
		std::cout << std::endl << myHeap.get(i) << std::endl;
	}
}

