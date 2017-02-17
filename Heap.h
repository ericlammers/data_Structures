#include <vector>

class Heap {

private:
	std::vector<int> values;
	
public:
	Heap();
	void insert(int num);
	int removeLargestElement();
	int size();
	int get(int i);
};