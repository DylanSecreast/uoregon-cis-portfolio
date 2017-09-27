//
//  Deque.cpp
//  Programming Assignment 2
//
//  Created by Dylan Secreast on 4/8/14.
//  Copyright (c) 2014 Dylan Secreast. All rights reserved.
//

#include "Deque.h"
#include <sstream>


// Overloaded constructor creates array of n elements
Deque::Deque(int n){
	maxSize = n;
	myArray = new int[maxSize];
}


void Deque::addLeft(int n){
	if (!isFull()){
		if (left == maxSize){		// wrap around
			left = 0;
		}
		myArray[left++] = n;
		nElems++;
	}

}


void Deque::addRight(int n){
	if (!isFull()){
		if (right == maxSize-1){		// wrap around
			right = -1;
		}
		myArray[right--] = n;
		nElems++;
	}
}


int Deque::getLeft(){
	if (isEmpty()){
		return 0;
	}
	int getLeft = myArray[--left];
	if (left == maxSize){
		left = 0;		// wrap around
	}
	nElems--;
	return getLeft;
}


int Deque::getRight(){
	if (isEmpty()){
		return 0;
	}
	int getRight = myArray[++right];
	if (right == maxSize - 1){
		right = -1;		// wrap around
	}
	nElems--;
	return getRight;
}


std::string Deque::listLeftRight(){
	std::ostringstream ss;
	std::string leftRight = "";
	ss.str(std::string(""));   // clear stringstream
	ss.clear();     // reset stringstream flags

	for (int i = left; i < nElems; i++){
		if (i == maxSize){
			i = 0;	// Wrap around
		}
		ss << myArray[i] << " ";
		leftRight = ss.str();
	}
	return leftRight;
}


std::string Deque::listRightLeft(){
	std::ostringstream ss;
	std::string rightLeft = "";
	ss.str(std::string(""));   // clear stringstream
	ss.clear();     // reset stringstream flags

	for (int i = right; i < nElems; i++){
		if (i == maxSize-1){
			i = -1;	// Wrap around
		}
		ss << myArray[i] << " ";
		rightLeft = ss.str();
	}
	return rightLeft;
}



// Returns true if queue is empty
bool Deque::isEmpty(){
	if (nElems == 0){
		return true;
	}else{
		return false;
	}
}


// Returns true if queue is full
bool Deque::isFull(){
	if (nElems == maxSize){
		return true;
	}else{
		return false;
	}
}



void Deque::zeroOut(){
	for (int i = 0; i < maxSize; i++){
		myArray[i] = 0;
	}
}