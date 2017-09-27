#pragma once


class Node
{
public:
	int iData;              // data item (key)
	double dData;           // data item
	Node * leftChild;         // this node's left child
	Node * rightChild;        // this node's right child

public:
	Node(int i, double d);
	void displayNode();      // display ourself

};  // end class Node


class Tree
{
private:
	Node * root; 

public:
	Tree();  

	Node * find(int key);
	Node * getSuccessor(Node *delNode);

	void insert(int id, double dd);
	bool remove(int key);

	void traverse(int traverseType);
	void preOrder(Node * localRoot);
	void postOrder(Node * localRoot);
	void inOrder(Node * localRoot);
	void displayTree();
	int findNext(int val);
	int deleteNext(int val);

};  // end class Tree

