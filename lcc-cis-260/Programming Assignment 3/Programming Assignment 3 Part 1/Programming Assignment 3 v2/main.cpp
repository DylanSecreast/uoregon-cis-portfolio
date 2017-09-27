//	
//	main.cpp
//	Programming Assignment 3
//	
//	Created by Dylan Secreast on 4/23/14.
//	Copyright (c) 2014 Dylan Secreast. All rights reserved.
//	

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main(int args, char * argv[]){                           
	cout << "***************************************\n";
	cout << "Test #1: Double Linked List of Integers\n";
	cout << "***************************************\n\n";
	
	DoublyLinkedList* list1 = new DoublyLinkedList();

	cout << "<< Inserting 11 at tail of list >>\n";
	list1->insertLast(11);

	cout << "<< Inserting 22 at tail of list >>\n";
	list1->insertLast(22);

	cout << "<< Inserting 33 at tail of list >>\n";
	list1->insertLast(33);

	cout << "<< Inserting 44 at tail of list >>\n";
	list1->insertLast(44);

	cout << "<< Inserting 55 at tail of list >>\n\n";
	list1->insertLast(55);

	cout << "<< Displaying current list >>\n";
	list1->displayForward();
	list1->displayBackward();
	cout << endl;

	cout << "<< Deleting 33 from list >>\n\n";
	list1->deleteKey(33);

	cout << "<< Displaying current list >>\n";
	list1->displayForward();
	list1->displayBackward();
	cout << endl;

	cout << "<< Deleting item at head of list >>\n";
	list1->deleteFirst();
	cout << endl;

	cout << "<< Displaying current list >>\n";
	list1->displayForward();
	list1->displayBackward();
	cout << endl;

	
	//cout << "\nDoes 69 exist?: " << list1->findKey(68);
	//cout << "\nDoes 22 exist?: " << list1->findKey(22) << endl;
	

	cout << "<< Finding 44, inserting 42 after it >>\n\n";
	list1->insertKey(44, 42);	// find 44, insert 42 after

	cout << "<< Displaying current list >>\n";
	list1->displayForward();
	list1->displayBackward();
	cout << endl;


}  // end main()
