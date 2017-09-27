//
//  PriorityQueue.h
//  Programming Assignment 2
//
//  Created by Dylan Secreast on 4/18/14.
//  Copyright (c) 2014 Dylan Secreast. All rights reserved.
//

#ifndef __Programming_Assignment_2__PriorityQueue__
#define __Programming_Assignment_2__PriorityQueue__

#include <string>

class PriorityQueue{
private:
	int *myArray;
	int nElems;
	int maxSize;

public:
	PriorityQueue();
	PriorityQueue(int n);
	~PriorityQueue(){ delete[] myArray; }

	void addValue(int n);
	int remove(){ return myArray[--nElems]; }

	void zeroOut();
	std::string dumpArray();
	int getLargest();
	int getSmallest();

	bool isEmpty();
	bool isFull();
};



#endif /* defined(__Programming_Assignment_2__PriorityQueue__) */