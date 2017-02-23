
class Node {
public:
	Node(int value);
	int getX();
	Node* getRight();
	Node* getLeft();
	Node* getParent();

private:
	Node* right;
	Node* left;
	Node* parent;
	int x;
};
