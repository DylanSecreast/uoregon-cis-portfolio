#include "Link.h"


Link::Link()
{
}


Link::~Link()
{
}


// Inserts link containing val after the link pointed to by current
void Link::insertItem(char val){
	Node* temp;

	if (start == NULL){
		start = new Node[1];
		start->current = NULL;
		val->data;
	}
	else{
		temp = start;
		while (temp->current != NULL){
			temp = temp->current;
		}
		temp->current = new Node[1];
		temp = temp->current;
		val->data;
		temp->current = NULL;
	}
}


char Link::deleteItem(){
	Node* temp, *prev;

	if (start == NULL){
		return;
	}
	else{
		delete 
	}

}


void Link::stepLink(int count){
	Node* temp;

	temp = temp->current;
	temp = temp + count;
	temp->current;
}


void Link::displayList(){
	Node* temp;
	temp->current;

	while (temp->current != NULL){
		std::cout << "" << temp->data << " ";
		temp = temp->data;
	}
	std::cout << temp->data << std::endl;
}