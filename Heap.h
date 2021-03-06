#include <vector>

class Heap {

private:
	std::vector<int> values;
	int leftChildIndex(int index);
	int rightChildIndex(int index);
	int parentIndex(int index);
	int shiftDown(int index);
	
public:
	Heap();
	int topDownHeapify(int* intArray, int size);
	int bottomUpHeapify(int* intArray, int size);
	int insert(int num);
	int removeLargestElement();
	int size();
	int get(int i);
};