#include <stdlib.h>
#include <stdio.h> 
#include "linkedList.h"

struct listnode{
 int val;
 struct listnode * next;
 struct listnode * prev;
};

struct linkedlist {
  int size;
  struct listnode * header;
  struct listnode * trailer;
};

struct listiterator{



};


/* 
 * Linked list of integers 
 */ 
/*
LinkedList_destroy destroys the list structure in `tld' 
 * 
 * all heap allocated storage associated with the list is returned to the 
heap 
 */ 
void list_destroy(LinkedList *l){
	int value = remove(l);
	while(l->size != 0) {
		remove(l);
	}

  	free( l -> header);
  	free ( l -> trailer);
        free ( l); 

}
/* creates linked list */
LinkedList * list_create(){

  LinkedList * l =  calloc(1, sizeof(LinkedList));
    l -> header = calloc(1, sizeof(ListNode));
    l -> trailer = calloc(1,sizeof(ListNode));
    l -> size = 0;


return l;

}
/* 
 * add node at the end of the list 
 */ 

void list_add(LinkedList *l, int value){
    
     ListNode * n = l -> trailer -> prev;
     ListNode * newNode = calloc(1, sizeof(ListNode) );
     newNode -> val = value; 
     newNode -> prev = n;
     newNode -> next = l -> trailer;
     l -> trailer -> prev = newNode;
     n -> next = newNode;
     l-> size++;        
}

/*remove node from the front of the list*/
int list_remove(LinkedList *l){
	if (l->size == 0) {
		return -1;
	}

	ListNode *element = l->header->next;
	int value = element->val;
	l->header = element->next;
	(l->size)--;
	free(element);

	if (l->size == 0) {
		l->header->next = l->trailer;
		l->trailer->prev = l->header;
	}

  return value;
}
/*function returns the size of the list */
int list_size(LinkedList *l){
  return l -> size;
} 
/* 
 * list_iter_create creates an iterator over the LinkedList; returns a 
pointer 
 * to the iterator if successful, NULL if not 
 */ 
ListIterator *list_iter_create(LinkedList *l){

  return NULL;
}
/* 
 * list_iter_next returns the next element in the list; returns a pointer 
 * to the TLDNode if successful, NULL if no more elements to return 
 */ 
ListNode *list_iter_next(ListIterator *iter){

  return NULL;
}
/* 
 * tldlist_iter_destroy destroys the iterator specified by `iter' 
 */ 
void list_iter_destroy(ListIterator *iter){

 
}
/* 
 * get_value returns the value associated with the ListNode
 */ 

void display(LinkedList * l){
     ListNode * curr = l -> header;
     ListNode * end = l -> trailer;
     while ( curr != end){
        printf("%d\n", curr -> val );
        curr = curr -> next;
     }
}
int get_value(ListNode *node){
  return node -> val;
}
