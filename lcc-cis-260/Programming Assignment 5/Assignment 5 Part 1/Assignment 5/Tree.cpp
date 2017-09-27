// tree.cpp
// modified from tree.java by jim bailey
// edited by Dylan Secreast (5/4/14)
// demonstrates binary tree

#include "Tree.h"
#include <iostream>
#include <stack>
#include <string>



// Node class declarations
Node::Node(std::string i = 0, double d = 0.0){
	iData = i;
	dData = d;
	leftChild = rightChild = NULL;
}


void Node::displayNode(){
	std::cout << "{" << iData << ", " << dData << "}";
}



// Tree class declarations
    Tree::Tree(){
		root = NULL; 
    }


	Node * Tree::find(std::string key){      // find node with given key                
		if (root == NULL){
			return NULL;    // cant find in empty tree
		}

		Node * current = root;               // start at root

		while(current->iData != key){        // while no match,
			if (key < current->iData){         // go left?
				current = current->leftChild;
			}
			else{                            // or go right?
				current = current->rightChild;
			}
			if (current == NULL){             // if no child,
				return NULL;                 // didn't find it
			}
		}	// end while
            
            return current;                    // found it
        }  // end find()


	void Tree::insert(std::string id, double dd){
		Node * newNode = new Node(id, dd);  // make new node
 
		if (root == NULL){					// no node in root
			root = newNode;
		}
            else{                          // root occupied
                Node * current = root;     // start at root
                Node * parent;
         
                std::cout << " inserting node " << std::endl;
                newNode->displayNode();
                std::cout << std::endl;
                
                while(true){                // (exits internally)
                    parent = current;
                    
                    std::cout << " current is " << std::endl;
                    current->displayNode();
                    std::cout << std::endl;
                    
                    if(id < current->iData){				// go left?
                        current = current->leftChild;
                        if(current == NULL){				// if end of the line,               
                            parent->leftChild = newNode;	// insert on left
                            return;
                        }
                    }			// end if go left
                    else{		// or go right?
                        current = current->rightChild;
                        if(current == NULL){				// if end of the line          
                            parent->rightChild = newNode;	// insert on right
                            return;
                        }
                    }  // end else go right
                }  // end while
            }  // end else not root
	}  // end insert()


	bool Tree::remove(std::string key){ // remove node with given key                     
		Node * current = root;
		Node * parent = root;
		bool isLeftChild = true;
		Node * temp;
                
		if (root == NULL){ // empty tree
			return false;
		}
                
		while(current->iData != key){        // search for node
			parent = current;
			if(key < current->iData){         // go left?
                    isLeftChild = true;
                    current = current->leftChild;
			}
			else{                            // or go right?
                    isLeftChild = false;
                    current = current->rightChild;
			}
            
			if (current == NULL){             // end of the line,
				return false;                // didn't find it
			}
         
		}  // end while
            
                // found node to delete
                // save to remove
		temp = current;

                // if no children, simply delete it
		if(current->leftChild==NULL && current->rightChild==NULL){
			if (current == root){             // if root,
				root = NULL;                 // tree is empty
			}
			else{
				if (isLeftChild){
					parent->leftChild = NULL;     // disconnect
				}
				else{                            // from parent
					parent->rightChild = NULL;
				}
			}
		}
		else	// if no right child, replace with left subtree
			if(current->rightChild==NULL)
                    if(current == root)
                        root = current->leftChild;
                    else 
                        if(isLeftChild)
                            parent->leftChild = current->leftChild;
                        else
                            parent->rightChild = current->leftChild;

                    // if no left child, replace with right subtree
                else 
                    if(current->leftChild==NULL)
                        if(current == root)
                            root = current->rightChild;
                        else 
                            if(isLeftChild)
                                parent->leftChild = current->rightChild;
                            else
                                parent->rightChild = current->rightChild;
                                
                        // two children, so replace with inorder successor
                    else  
                    {
                        // get successor of node to delete (current)
                        Node * successor = getSuccessor(current);

                        // connect parent of current to successor instead
                        if(current == root)
                            root = successor;
                        else 
                            if(isLeftChild)
                                parent->leftChild = successor;
                            else
                                parent->rightChild = successor;

                        // connect successor to current's left child
                        successor->leftChild = current->leftChild;
                    }  // end else two children
                       // (successor cannot have a left child)

            delete temp;       
            return true;                                // success
        }  // end remove()


                // returns node with next-highest value after delNode
                // goes to right child, then right child's left descendents
	Node * Tree::getSuccessor(Node *delNode){
		Node * successorParent = delNode;
		Node * successor = delNode;
		Node * current = delNode->rightChild;   // go to right child
                   
		while(current != NULL){        // go left until no more left children                                       
                successorParent = successor;
                successor = current;
                current = current->leftChild;      
		}
                             
		if(successor != delNode->rightChild){	// if successor not right child                            
                successorParent->leftChild = successor->rightChild;		// make necessary connections
                successor->rightChild = delNode->rightChild;
		}

		return successor;
	}


	void Tree::traverse(int traverseType){
		switch(traverseType){
			case 1: 
				std::cout << "\nPreorder traversal: ";
				preOrder(root);
				break;
			case 2: 
				std::cout << "\nInorder traversal:  ";
				inOrder(root);
				break;
			case 3: 
				std::cout << "\nPostorder traversal: ";
				postOrder(root);
				break;
			default:
				std::cout << "must be 1, 2, or 3" << std::endl;
		}
		std::cout << std::endl;
	}


	void Tree::preOrder(Node * localRoot){
            if(localRoot != NULL){
				std::cout << localRoot->iData << " ";
                preOrder(localRoot->leftChild);
                preOrder(localRoot->rightChild);
            }
	}
    

	void Tree::inOrder(Node * localRoot){
            if(localRoot != NULL){
                inOrder(localRoot->leftChild);
				std::cout << localRoot->iData << " ";
                inOrder(localRoot->rightChild);
            }
	}


	void Tree::postOrder(Node * localRoot){
		if(localRoot != NULL){
                postOrder(localRoot->leftChild);
                postOrder(localRoot->rightChild);
				std::cout << localRoot->iData << " ";
		}
	}


	void Tree::displayTree(){
		std::stack <Node *> globalStack;
		globalStack.push(root);
		int nBlanks = 32;
		bool isRowEmpty = false;

		std::cout << "......................................................" << std::endl;
      
		while(isRowEmpty==false){
			std::stack <Node *> localStack;
			isRowEmpty = true;

			for(int j=0; j<nBlanks; j++)
					std::cout << ' ';

                while(globalStack.empty()==false)
                {
                    Node * temp = globalStack.top();
                    globalStack.pop();
                    if(temp != NULL)
                    {
						std::cout << temp->iData;
                        localStack.push(temp->leftChild);
                        localStack.push(temp->rightChild);

                        if(temp->leftChild != NULL || temp->rightChild != NULL)
                            isRowEmpty = false;
                    }
                    else
                    {
						std::cout << "--";
                        localStack.push(NULL);
                        localStack.push(NULL);
                    }
            
                    for(int j=0; j<nBlanks*2-2; j++)
						std::cout << ' ';
                }  // end while globalStack not empty
         
				std::cout << std::endl;
                nBlanks /= 2;
                while(localStack.empty()==false)
                {
                    Node * temp = localStack.top();
                    localStack.pop();
                    globalStack.push( temp );
                }
            }  // end while isRowEmpty is false

			std::cout << "......................................................" << std::endl;
        }  // end displayTree()

