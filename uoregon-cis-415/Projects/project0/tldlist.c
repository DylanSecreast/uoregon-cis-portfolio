/* Dylan Secreast
 * dsecrea2@uoregon.edu
 * CIS 415 Project 0
 * This is my own work except for the following:
 * - AVL Tree was modeled after: gist.github.com/tonious/1377768
 * - Iterator was modeled after CIS 415 lecture slides
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tldlist.h"
#include "date.h"


static TLDNode *createNode(char *hostname);
static int insertNode(TLDList *tld, char *hostname, TLDNode *node);
static TLDNode *findDeepestNode(TLDNode *node);
static void rightRightAVL(TLDNode *node);
static void leftLeftAVL(TLDNode *node);
static long findAVLHeight(TLDNode *node);
static void balanceAVL(TLDNode *node);


struct tldlist {
	TLDNode *root;
	Date *begin, *end;
	long count;
};

struct tldnode {
	TLDNode *parent, *left, *right;
	char *data;
	long count, height;
};

struct tlditerator {
	TLDList *tld;
	TLDNode *nodes;
	long count;
};


TLDList *tldlist_create(Date *begin, Date *end) {

	TLDList *tld = (TLDList *) malloc(sizeof(TLDList));

	tld->begin = date_duplicate(begin);
	tld->end = date_duplicate(end);

	tld->root = NULL;
	tld->count = 0;

	return tld;

} // end *tldlist_create


void tldlist_destroy(TLDList *tld) {

	TLDIterator *iterator = tldlist_iter_create(tld);
	TLDNode *node;

	while ((node = tldlist_iter_next(iterator)) != NULL) {
		free(node->data);
		free(node);
	}

	date_destroy(tld->begin);
	date_destroy(tld->end);
	free(tld);
	tldlist_iter_destroy(iterator);

} // end tldlist_destroy


int tldlist_add(TLDList *tld, char *hostname, Date *d) {

	long i;
	for (i = 0; hostname[i] != '\0'; i++) {
		hostname[i] = tolower(hostname[i]);
	}

	if (date_compare(tld->begin, d) >= 0) {
		if (date_compare(tld->end, d) >= 0) {
			return 0;
		}
	}

	char *setLoc = strrchr(hostname, '.')+1;
	char *data = (char *) malloc(sizeof(setLoc));
	strcpy(data, setLoc);

	if (insertNode(tld, data, tld->root) != 0) {
		tld->count++;
	} else {
		free(data);
	}
	return 1;

} //end tldlist_add


static TLDNode *createNode(char *hostname) {
	
	TLDNode *newNode = (TLDNode *) malloc(sizeof(TLDNode)+1);

	if (newNode == NULL) {
		free(newNode);
		return NULL;
	
	} else {
		newNode->parent = NULL;
		newNode->data = hostname;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->height = 1;
		newNode->count = 1;
	}
	
	return newNode;

} // end *createNode


static int insertNode(TLDList *tld, char *hostname, TLDNode *node) {

	if (tld->root == NULL) {
		TLDNode *newNode = createNode(hostname);
		newNode->parent = NULL;
		tld->root = newNode;
		return 1;
	} else {
		int compare = strcmp(hostname, node->data);

		if (compare < 0 ) {
			if (node->left != NULL) {
				return insertNode(tld, hostname, node->left);
			} else {
				TLDNode *newNode = createNode(hostname);
				newNode->parent = node;
				node->left = newNode;
				balanceAVL(node->left);
				return 1;
			}
		} else if (compare > 0) {
			if (node->right != NULL) {
				return insertNode(tld, hostname, node->right);
			} else {
				TLDNode *newNode = createNode(hostname);
				newNode->parent = node;
				node->right = newNode;
				balanceAVL(node->right);
				return 1;
			}
		} else if (compare == 0) {
			node->count++;
			free(hostname);
			return 1;
		}
	}
	
	int invalidInsert = NULL;
	return invalidInsert;

} // end insertNode


static void balanceAVL(TLDNode *node) {

	long bal = 0;

	if ((node->height = findAVLHeight(node)) > 2) {
		bal = findAVLHeight(node->right) - findAVLHeight(node->right);
		if (!abs((int)bal) < 2) {
			if (bal > 0) {
				if (findAVLHeight(node->left->right) > findAVLHeight(node->left->left)) {
					leftLeftAVL(node->left);
					node->left->left->height = findAVLHeight(node->left->left);
					node->left->height = findAVLHeight(node->left);
				} else {
					rightRightAVL(node);
					node->right->height = findAVLHeight(node->right);
					node->height = findAVLHeight(node);
				}
			} else {
				if (findAVLHeight(node->right->left) > findAVLHeight(node->right->right)) {
					rightRightAVL(node->right);
					node->right->right->height = findAVLHeight(node->right->right);
					node->right->height = findAVLHeight(node->right);
				} else {
					leftLeftAVL(node);
					node->left->height = findAVLHeight(node->left);
					node->height = findAVLHeight(node);
				}
			}
		}
	}

} // end balanceAVL


static long findAVLHeight(TLDNode *node) {

	long height, left, right;

	if (node == NULL) {
		height = 0;
	}

	if (node->left == NULL) {
		left = 0;
	} else {
		left = node->left->height;
	}

	if (node->right == NULL) {
		right = 0;
	} else {
		right = node->right->height;
	}

	if (left > right) {
		height = left+1;
	} else {
		height = right+1;
	}

	return height;

} // end findAVLHeight


static void rightRightAVL(TLDNode *node) {

	node->parent->left = node->left;
	node->left->parent = node->parent;
	node->parent = node->left;
	node->left = node->left->right;
	node->left->parent = node;
	node->parent->right = node;

} // end rightRightAVL


static void leftLeftAVL(TLDNode *node) {

	node->parent->right = node->right;
	node->right->parent = node->parent;
	node->parent = node->right;
	node->right = node->right->left;
	node->right->parent = node;
	node->parent->left = node;

} // end leftLeftAVL


long tldlist_count(TLDList *tld) {

	return tld->count;
	
} // end tldlist_count


TLDIterator *tldlist_iter_create(TLDList *tld) {

	TLDIterator *iterator = (TLDIterator *) malloc(sizeof(TLDIterator));

	if (iterator == NULL) {
		return NULL;
	}

	iterator->nodes = findDeepestNode(tld->root);
	iterator->count = 0;

	return iterator;

} // end *tldlist_iter_create


static TLDNode *findDeepestNode(TLDNode *node) {

	TLDNode *check = node;
	
	if (check != NULL) {
		if ((check = findDeepestNode(node->left)) != NULL || (check = findDeepestNode(node->right)) != NULL) {
			return check;
		} else {
			return node;
		}
	} else {
		return node;
	}

} //end *findDeepestNode


TLDNode *tldlist_iter_next(TLDIterator *iter) {

	TLDNode *next = iter->nodes;
	
	if (next == NULL) {
		return NULL;
	}

	if (iter->nodes->parent == NULL) {
		iter->nodes = NULL;
		return next;
	}

	int compare = NULL;
	if ((iter->nodes->parent->right != iter->nodes->parent->right) != compare) {
		iter->nodes = findDeepestNode(iter->nodes->parent->right);
	} else {
		iter->nodes = iter->nodes->parent;
	}

	return next;

} // end *tldlist_iter_next


void tldlist_iter_destroy(TLDIterator *iter) {

	free(iter->nodes);
	free(iter);

} // end tldlist_iter_destroy


char *tldnode_tldname(TLDNode *node) {

	return node->data;

} // end *tldnode_tldname


long tldnode_count(TLDNode *node) {

	return node->count;

} // end tldnode_count
