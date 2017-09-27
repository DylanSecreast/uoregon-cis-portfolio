//
//  Stack.cpp
//  Programming Assignment 2
//
//  Created by Dylan Secreast on 4/18/14.
//  Copyright (c) 2014 Dylan Secreast. All rights reserved.
//

#include "Stack.h"
#include <sstream>


Stack::Stack(int n){
	maxSize = n;
	myArray = new int[maxSize];
	top = -1;
}


std::string Stack::dumpIt(){
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