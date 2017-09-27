//	
//	DoublyLinkedList.cpp
//	Programming Assignment 3
//	
//	Created by Dylan Secreast on 4/23/14.
//	Copyright (c) 2014 Dylan Secreast. All rights reserved.
//	

#include "DoublyLinkedList.h"


// Destructor
DoublyLinkedList::~DoublyLinkedList(){
	Link* ptr = first;

	while (ptr != NULL){
		Link* temp = ptr;
		ptr = ptr->getNext();
		delete temp;
	}
}


// Insert a link containing val at the head of the list
void DoublyLinkedList::insertFirst(std::string d){
	Link * newLink = new Link(d);   // make new link

	if (isEmpty()){                // if empty list,
		last = newLink;             // newLink <-- last
	}
	else{
		first->previous = newLink;   // newLink <-- old first
	}

	newLink->next = first;          // newLink --> old first
	first = newLink;               // first --> newLink
}


// Insert a link containing val at the end of the list
void DoublyLinkedList::insertLast(std::string d){
	Link * newLink = new Link(d);   // make new link

	if (isEmpty()){                // if empty list,
		first = newLink;            // first --> newLink
	}
	else{
		last->next = newLink;        // old last --> newLink
		newLink->previous = last;    // old last <-- newLink
	}

	last = newLink;                // newLink <-- last
}


// Insert a link just after key. Return true if succeed, false if fail. (Assumes non-empty list)
bool DoublyLinkedList::insertKey(std::string key, std::string d){
	Link * current = first;          // start at beginning

	while (current->data != key){    // until match is found,
		current = current->next;     // move to next link
		if (current == NULL){
			return false;            // didn't find it
		}
	}

	Link * newLink = new Link(d);   // make new link

	if (current == last){              // if last link,
		newLink->next = NULL;        // newLink --> NULL
		last = newLink;             // newLink <-- last
	}
	else{                           // not last link,
		newLink->next = current->next; // newLink --> old next
		// newLink <-- old next
		current->next->previous = newLink;
	}

	newLink->previous = current;    // old current <-- newLink
	current->next = newLink;        // old current --> newLink

	return true;                   // found it, did insertion
}


// Delete first link and retun its value (may assume non-empty list)
Link& DoublyLinkedList::deleteFirst(){
	Link * temp = first;

	if (first->next == NULL)         // if only one item
		last = NULL;                // NULL <-- last
	else
		first->next->previous = NULL; // NULL <-- old next

	first = first->next;            // first --> old next
	return *temp;
}


// Delete last link and retun its value (may assume non-empty list)
Link& DoublyLinkedList::deleteLast(){
	Link * temp = last;

	if (first->next == NULL)         // if only one item
		first = NULL;               // first --> NULL
	else
		last->previous->next = NULL;  // old previous --> NULL

	last = last->previous;          // old previous <-- last
	return *temp;
}


// Delete the first link you find that contains key. Return true if succeed, false if fail.
Link& DoublyLinkedList::deleteKey(std::string key){
	Link * current = first;          // start at beginning

	while (current->data != key){    // until match is found,
		current = current->next;     // move to next link
		if (current == NULL){
			return *current;             // didn't find it
		}
	}

	if (current == first){            // found it; first item?
		first = current->next;       // first --> old next
	}
	else{                           // not first
		// old previous --> old next
		current->previous->next = current->next;
	}

	if (current == last){              // last item?
		last = current->previous;    // old previous <-- last
	}
	else{                           // not last
		// old previous <-- old next
		current->next->previous = current->previous;
	}

	return *current;                // return value
}


// Returns true if a link exists containing a key. If find key, sets class variable pointing to the link containing it for later reference. If key not found in list, return false.
bool DoublyLinkedList::findKey(std::string key){
	if (first == NULL){
		return false;
	}

	Link * ptr = first;

	while (ptr != NULL){
		if (ptr->getData() == key){
			return true;
		}
		ptr = ptr->getNext();
	}
	return false;
}


void DoublyLinkedList::displayForward(){
	std::cout << "List (first-->last): ";

	Link * current = first;          // start at beginning

	while (current != NULL){         // until end of list,
		current->displayLink();      // display data
		current = current->next;     // move to next link
	}

	std::cout << std::endl;
}


void DoublyLinkedList::displayBackward(){
	std::cout << "List (last-->first): ";

	Link * current = last;           // start at end

	while (current != NULL){         // until start of list,
		current->displayLink();      // display data
		current = current->previous; // move to previous link
	}

	std::cout << std::endl;
	
}