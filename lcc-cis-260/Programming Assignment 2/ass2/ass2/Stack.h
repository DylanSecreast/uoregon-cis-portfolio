//
//  Stack.h
//  Programming Assignment 2
//
//  Created by Dylan Secreast on 4/18/14.
//  Copyright (c) 2014 Dylan Secreast. All rights reserved.
//

#ifndef __Programming_Assignment_2__Stack__
#define __Programming_Assignment_2__Stack__

#include <string>
#include "Deque.h"

class Stack{
private:
	Deque q;
	Deque *myDeque;

public:
	Stack(){ myDeque = new Deque(); }
	Stack(int n){ myDeque = new Deque(n); }
	//~Stack(){ delete[] myArray; }

	void push(int n){ q.addLeft(n); }
	int pop(){ return q.getLeft(); }
	int peek();
	std::string dumpIt(){ return q.listLeftRight(); }
};

#endif /* defined(__Programming_Assignment_2__Stack__) */