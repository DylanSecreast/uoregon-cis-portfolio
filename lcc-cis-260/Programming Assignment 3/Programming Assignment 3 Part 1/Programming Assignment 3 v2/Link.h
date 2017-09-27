//	
//	Link.h
//	Programming Assignment 3
//	
//	Created by Dylan Secreast on 4/23/14.
//	Copyright (c) 2014 Dylan Secreast. All rights reserved.
//	

#pragma once
#include <iostream>

class Link
{
private:


public:
	long data;                   // data item
	Link* next;                  // next link in list
	Link* previous;              // previous link in list

	Link(long d, Link* n = NULL, Link* p = NULL){ data = d; next = n; previous = p; }			// Constructor
	void displayLink(){ std::cout << data << " "; }
	
	void setNext(Link* n){ next = n; }
	void setPrevious(Link* p){ previous = p; }

	Link* getNext(){ return next; }
	Link* getPrev(){ return previous; }

	int getData(){ return data; }

};  // end class Link