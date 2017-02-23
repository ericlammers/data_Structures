#include "Node.h"
#include <cstddef>

Node::Node(int value){
	right = NULL;
	left = NULL;
	parent = NULL;
	x = value;
}

int Node::getX() { return x; }
Node* Node::getRight() { return right; }
Node* Node::getLeft() { return left; }
Node* Node::getParent() {return parent; }