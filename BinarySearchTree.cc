#include "BinarySearchTree.h"

#include <cstddef>

int BinarySearchTree::add(Node u) {
	if(root.getX() == NULL) {
		root = u;
		return 1;
	}

	Node* currNode = &root;
	Node* nextNode;
	while(true) {
		
	}
}

int BinarySearchTree::depth(Node* u) {
	int depth = 0;
	while(u->getParent() != NULL) {
		depth++;
		u = u->getParent();
	}
	return depth;
}

