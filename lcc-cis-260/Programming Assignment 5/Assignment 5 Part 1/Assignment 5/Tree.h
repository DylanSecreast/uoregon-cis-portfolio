#pragma once
#include <string>


class Node
{
public:
	std::string iData;              // data item (key)
	double dData;           // data item
	Node * leftChild;         // this node's left child
	Node * rightChild;        // this node's right child

public:
	Node(std::string i, double d);
	void displayNode();      // display ourself

};  // end class Node


class Tree
{
private:
	Node * root; 

public:
	Tree();  

	Node * find(std::string key);
	Node * getSuccessor(Node *delNode);

	void insert(std::string id, double dd);
	bool remove(std::string key);

	void traverse(int traverseType);
	void preOrder(Node * localRoot);
	void postOrder(Node * localRoot);
	void inOrder(Node * localRoot);
	void displayTree();

};  // end class Tree

