#include "stack.h"
#include <cstdlib>

StackNode::StackNode(Tree *treeNode){
		this->treeNode = treeNode;
		next = NULL;
}