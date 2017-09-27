//
//  PriorityQueue.cpp
//  Programming Assignment 2
//
//  Created by Dylan Secreast on 4/18/14.
//  Copyright (c) 2014 Dylan Secreast. All rights reserved.
//

#include "PriorityQueue.h"
#include <sstream>


PriorityQueue::PriorityQueue(int n){
	maxSize = n;
	myArray = new int[maxSize];
	nElems = 0;
}


void PriorityQueue::addValue(int n){
	// Insertion runs in O(1) time
	if (!isFull()){
		myArray[nElems] = n;
		nElems++;
	}

	/*
	// Insertion runs in O(n) time
	int j;

	if (nElems == 0){
		myArray[nElems++] = n;
	}else{
		for (j = nElems - 1; j >= 0; j--){
			if (n > myArray[j]){
				myArray[j + 1] = myArray[j];
			}else{
				break;
			}
		}
		myArray[j + 1] = n;
		nElems++;
	}
	*/
}


void PriorityQueue::zeroOut(){
	for (int i = 0; i < maxSize; i++){
		myArray[i] = 0;
	}
}


std::string PriorityQueue::dumpArray(){
	std::ostringstream ss;
	std::string allElems = "";
	const int LINEBREAK = 10;
	int elemCount = 0;


	ss.str(std::string(""));   // clear stringstream
	ss.clear();     // reset stringstream flags

	for (int i = 0; i < maxSize; i++){
		ss << myArray[i] << " ";
		allElems = ss.str();
		elemCount++;
		if (elemCount % LINEBREAK == 0){
			ss << "\n";
		}
	}
	return allElems;
}


int PriorityQueue::getLargest(){
	int largest = myArray[0];
	int largestIndex = 0;
	
	if (isEmpty()){
		return 0;
	}
	for (int i = 1; i < maxSize; i++){
		if (myArray[i] > myArray[largestIndex]){
			largest = myArray[i];
			largestIndex = i;
		}
	}
	myArray[largestIndex] = myArray[nElems - 1];
	nElems--;
	return largest;
}


int PriorityQueue::getSmallest(){
	int smallest = myArray[0];
	int smallestIndex = 0;
	
	if (isEmpty()){
		return 0;
	}
	for (int i = 1; i < maxSize; i++){
		if (myArray[i] < myArray[smallestIndex]){
			smallest = myArray[i];
			smallestIndex = i;
		}
	}
	myArray[smallestIndex] = myArray[nElems - 1];
	nElems--;
	return smallest;
}


bool PriorityQueue::isEmpty(){
	if (nElems == 0){
		return true;
	}else{
		return false;
	}
}


bool PriorityQueue::isFull(){
	if (nElems == maxSize){
		return true;
	}else{
		return false;
	}
}