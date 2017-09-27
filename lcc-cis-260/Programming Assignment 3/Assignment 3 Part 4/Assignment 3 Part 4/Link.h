#pragma once

#include "Node.h"
#include <iostream>

class Link
{
private:
	Node *start;

public:
	Link(){ start = NULL; }
	~Link();

	void insertItem(char val);		// Inserts link containing val after the link pointed to by current
	char deleteItem();				// Delete link after the link pointed to by current and return its value
	void stepLink(int count);		// Move the current pointer forward count links in the list
	void displayList();				// Display values in the nodes of the list starting at the current point
};

