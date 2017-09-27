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

class Stack{
private:
	int maxSize;
	int *myArray;
	int top;

public:
	Stack();
	Stack(int n);
	~Stack(){ delete[] myArray; }

	void push(int n){ myArray[++top] = n; }
	int pop(){ return myArray[top--]; }
	int peek(){ return myArray[top]; }
	std::string dumpIt();
};

#endif /* defined(__Programming_Assignment_2__Stack__) */