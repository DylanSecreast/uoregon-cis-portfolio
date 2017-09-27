//
//  Deque.h
//  Programming Assignment 2
//
//  Created by Dylan Secreast on 4/8/14.
//  Copyright (c) 2014 Dylan Secreast. All rights reserved.
//

#ifndef __Programming_Assignment_2__Deque__
#define __Programming_Assignment_2__Deque__

#include <string>

class Deque{
private:
	int *myArray;
    int maxSize = 100;
	int left = 0,
		right = -1,
		nElems = 0;
    
public:
	Deque();
	Deque(int n);
	//~Deque(){ delete[] myArray; }		// destructor causes program to crash..?
	
    void addLeft(int n);
    void addRight(int n);
	int getLeft();
	int getRight();

	std::string listRightLeft();
	std::string listLeftRight();
    
    bool isEmpty();
    bool isFull();
	void zeroOut();
};





#endif /* defined(__Programming_Assignment_2__Deque__) */
