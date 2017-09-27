#ifndef _LINKEDLIST_H_INCLUDED_ 
#define _LINKEDLIST_H_INCLUDED_ 

typedef struct linkedlist LinkedList; 
typedef struct listnode ListNode; 
typedef struct listiterator ListIterator; 
/* 
 * Linked list of integers 
 */ 
/*
LinkedList_destroy destroys the list structure in `tld' 
 * 
 * all heap allocated storage associated with the list is returned to the 
heap 
 */ 
void list_destroy(LinkedList *l); 

/*create linked list */
LinkedList * list_create();
void init(LinkedList *l);
/* 
 * add node to list
 */ 
void list_add(LinkedList *l, int val); 


/*function returns the size of the list */
int list_size(LinkedList *l); 
/* 
 * list_iter_create creates an iterator over the LinkedList; returns a 
pointer 
 * to the iterator if successful, NULL if not 
 */ 
ListIterator *list_iter_create(LinkedList *l); 
/* 
 * list_iter_next returns the next element in the list; returns a pointer 
 * to the TLDNode if successful, NULL if no more elements to return 
 */ 
ListNode *list_iter_next(ListIterator *iter); 
/* 
 * tldlist_iter_destroy destroys the iterator specified by `iter' 
 */ 
void list_iter_destroy(ListIterator *iter); 
/* 
 * get_value returns the value associated with the ListNode
 */ 
int get_value(ListNode *node); 

/* display the linked list */
void display(LinkedList * l);

#endif /* _TLDLIST_H_INCLUDED_ */ 
