//	
//	main.cpp
//	Programming Assignment 3
//	
//	Created by Dylan Secreast on 4/25/14.
//	Copyright (c) 2014 Dylan Secreast. All rights reserved.
//	

#include "TextClass.h"
#include <iostream>
using namespace std;

int main(int args, char* argv[]){

	cout << "*****************************************\n";
	cout << "Test #2: Double Linked List of Characters\n";
	cout << "*****************************************\n\n";
	
	TextClass* list2 = new TextClass();

	
	cout << "<< Inserting 'D' at tail of list >>\n";
	list2->push("D");

	cout << "<< Inserting 'y' at tail of list >>\n";
	list2->push("y");

	cout << "<< Inserting 'l' at tail of list >>\n";
	list2->push("l");

	cout << "<< Inserting 'a' at tail of list >>\n";
	list2->push("a");

	cout << "<< Inserting 'n' at tail of list >>\n\n";
	list2->push("n");

	cout << "<< Displaying current list >>\n";
	list2->displayChars();

	cout << "\n<< Inserting 'Secreast' at tail of list >>\n\n";
	list2->push(" Secreast");

	cout << "<< Displaying current list >>\n";
	list2->displayChars();
	

	TextClass* list3 = new TextClass();

	cout << "\n<< Inserting 'That is a test.' to tail of list >>\n\n";
	list3->push("That is a test.");

	cout << "<< Displaying current list >>\n";
	list3->displayChars();

	TextClass* dogList = new TextClass;
	TextClass* catList = new TextClass;
	catList->appendList(dogList);


	/*
	cout << "<< Finding 'is', changing to 'was' >>\n\n";
	list3->deleteChar("is");

	cout << "<< Displaying current list >>\n";
	list3->displayChars();
	*/

	return 0;
}