#include "tree.h"

class StackNode
{
public:
	Tree *treeNode;
	StackNode *next;
	StackNode(Tree *treeNode);
};