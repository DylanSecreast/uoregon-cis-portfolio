//	
//	TextClass.h
//	Programming Assignment 3
//	
//	Created by Dylan Secreast on 4/23/14.
//	Copyright (c) 2014 Dylan Secreast. All rights reserved.
//	

#include "DoublyLinkedList.h"

#pragma once
class TextClass
{
private:
	DoublyLinkedList x;

public:
	void push(std::string c){ x.insertLast(c); }	// Input character
	std::string pop(std::string c){ x.deleteKey(c); }		// Deletes first example of character

	bool findChar(std::string c){ x.findKey(c); }	// Finds character in list

	Link& deleteHead(){ x.deleteFirst(); }
	Link& deleteChar(std::string c){ x.deleteKey(c); }	// Deletes char/string

	void displayChars(){ x.displayForward(); }	// Displays all chars in list, head to tail

	void appendList(TextClass * & other);
	
	
};

