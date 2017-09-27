#pragma once
#include "Link.h"

//	
//	DoublyLinkedList.h
//	Programming Assignment 3
//	
//	Created by Dylan Secreast on 4/23/14.
//	Copyright (c) 2014 Dylan Secreast. All rights reserved.
//	

#pragma once

class DoublyLinkedList
{
private:
	Link * first;	// ref to first item
	Link * last;	// ref to last item

public:
	DoublyLinkedList(){ first = last = NULL; }	// No items in list yet
	~DoublyLinkedList();

	void insertFirst(long d);				// Insert a link containing val at the head of the list
	void insertLast(long d);				// Insert a link containing val at the end of the list
	bool insertKey(long key, long d);		// Insert a link just after key. Return true if succeed, false if fail. (Assumes non-empty list)


	Link & deleteFirst();			// Delete first link and retun its value (may assume non-empty list)
	Link & deleteLast();			// Delete last link and retun its value (may assume non-empty list)
	Link & deleteKey(long key);		// Delete the first link you find that contains key. Return true if succeed, false if fail.

	bool isEmpty(){ return first == NULL; }		// Return true if list is empty
	bool findKey(long key);		// Returns true if a link exists containing a key. If find key, sets class variable pointing to the link containing it for later reference. If key not found in list, return false.

	void displayForward();		// Displays list head to tail
	void displayBackward();		// Displays list tail to head

};  // end class DoublyLinkedList
