// tree234.cpp
// modified from tree234.java by jim bailey
// demonstrates 234 tree

#include <iostream>
using namespace std;

class DataItem
{
    public:
        long dData;          // one data item

        DataItem(long dd)    // constructor
        { 
            dData = dd; 
        }

        void displayItem()   // display item, format "/27"
        { 
            cout << "/" << dData; 
        }

};  // end class DataItem

class Node
{
    private:
        static const int ORDER = 4;
        int numItems;
        Node * parent;
        Node ** childArray;
        DataItem ** itemArray;
    
    public:
        Node()  // constructor
        {
            parent = NULL;
            childArray = new Node * [ORDER];
            itemArray = new DataItem * [ORDER-1];
            numItems = 0;
            for ( int i = 0; i < ORDER; i++ )
                childArray[i] = NULL;
            
            for ( int i = 0; i < ORDER-1; i++ )
                itemArray[i] = NULL;
        }
        ~Node()
        {
            for ( int i = 0; i < ORDER; i++ )
                if ( childArray[i] != NULL )
                    delete childArray[i];
            for ( int i = 0; i < ORDER-1; i++ )
                if ( itemArray[i] != NULL )
                    delete itemArray[i];
         }
   
            // connect child to this node
        void connectChild(int childNum, Node * child)
        {
            childArray[childNum] = child;
            if(child != NULL)
                child->parent = this;
        }


            // disconnect child from this node, return it
        Node * disconnectChild(int childNum)
        {
            Node * tempNode = childArray[childNum];
            childArray[childNum] = NULL;
            return tempNode;
        }

        Node * getChild(int childNum)
        { 
            return childArray[childNum]; 
        }

        Node * getParent()
        { 
            return parent; 
         }

        bool isLeaf()
        { 
            return (childArray[0] == NULL); 
        }

        int getNumItems()
        { 
            return numItems; 
        }

        DataItem * getItem(int index)   // get DataItem at index
        { 
            return itemArray[index]; 
        }

        bool isFull()
        { 
            return (numItems == ORDER-1); 
        }

        int findItem(long key)       // return index of
        {                                    // item (within node)
            for(int j=0; j<ORDER-1; j++)         // if found,
            {                                 // otherwise,
                if(itemArray[j] == NULL)          // return -1
                    break;
                else 
                    if(itemArray[j]->dData == key)
                        return j;
            }
      
            return -1;
        }  // end findItem

        int insertItem(DataItem * newItem)
        {
                // assumes node is not full
                
            numItems++;                          // will add new item
            long newKey = newItem->dData;         // key of new item

            for(int j=ORDER-2; j>=0; j--)        // start on right,
            {                                 //    examine items
                if(itemArray[j] == NULL)          // if item null,
                    continue;                      // go left one cell
                else                              // not null,
                {                              // get its key
                    long itsKey = itemArray[j]->dData;
                    if(newKey < itsKey)            // if it's bigger
                        itemArray[j+1] = itemArray[j]; // shift it right
                    else
                    {
                        itemArray[j+1] = newItem;   // insert new item
                        return j+1;                 // return index to
                    }                           //    new item
                }  // end else (not null)
            }  // end for                     // shifted all items,
      
            itemArray[0] = newItem;              // insert new item
            return 0;
        }  // end insertItem()

        DataItem * removeItem()        // remove largest item
        {
                // assumes node not empty
            
            DataItem * temp = itemArray[numItems-1];  // save item
            itemArray[numItems-1] = NULL;           // disconnect it
            numItems--;                             // one less item
            return temp;                            // return item
        }

        void displayNode()           // format "/24/56/74/"
        {

            for(int j=0; j<numItems; j++)
                itemArray[j]->displayItem();   // "/56"
            
            cout << "/" <<endl;         // final "/"
        }
};  // end class Node


class Tree234
{
    private:
        Node * root;            
    
    public:
        Tree234()
        {
            root = new Node();
        }
        
        int find(long key)
        {
            Node * curNode = root;
            int childNumber;
            while(true)
            {
                if(( childNumber=curNode->findItem(key) ) != -1)
                    return childNumber;               // found it
                else 
                    if( curNode->isLeaf() )
                        return -1;                        // can't find it
                    else                                 // search deeper
                        curNode = getNextChild(curNode, key);
            }  // end while
        }

            // insert a DataItem
        void insert(long dValue)
        {
            Node * curNode = root;
            DataItem * tempItem = new DataItem(dValue);
            
            while(true)
            {
                if( curNode->isFull() )               // if node full,
                {            
                    split(curNode);                   // split it
                    curNode = curNode->getParent();    // back up one level
                                                        
                    curNode = getNextChild(curNode, dValue);
                }  
                
                else 
                    if( curNode->isLeaf() )          // if node is leaf,
                        break;                            // go insert
      
                    else   // node is not full, not a leaf; so go to lower level
                        curNode = getNextChild(curNode, dValue);
            }  // end while

            curNode->insertItem(tempItem);       // insert new DataItem
        }  // end insert()

        void split(Node * thisNode)     // split the node
        {
                // assumes node is full
            DataItem * itemB, * itemC;
            Node * parent, * child2, * child3;
            int itemIndex;

            itemC = thisNode->removeItem();    // remove items from
            itemB = thisNode->removeItem();    // this node
            child2 = thisNode->disconnectChild(2); // remove children
            child3 = thisNode->disconnectChild(3); // from this node

            Node * newRight = new Node();       // make new node

            if( thisNode == root )                // if this is the root,
            {
                root = new Node();                // make new root
                parent = root;                    // root is our parent
                root->connectChild(0, thisNode);   // connect to parent
            }
            else                              // this node not the root
                parent = thisNode->getParent();    // get parent

                // deal with parent
            itemIndex = parent->insertItem(itemB); // item B to parent
            int n = parent->getNumItems();         // total items?
            for(int j=n-1; j>itemIndex; j--)          // move parent's
            {                                      // connections
                Node * temp = parent->disconnectChild(j); // one child
                parent->connectChild(j+1, temp);        // to the right
            }
                // connect newRight to parent
            parent->connectChild(itemIndex+1, newRight);

                // deal with newRight
            newRight->insertItem(itemC);       // item C to newRight
            newRight->connectChild(0, child2); // connect to 0 and 1
            newRight->connectChild(1, child3); // on newRight
        }  // end split()

            // gets appropriate child of node during search for value
        Node * getNextChild(Node * theNode, long theValue)
        {
            int j;
      
                    // assumes node is not empty, not full, not a leaf
            int numItems = theNode->getNumItems();
            for(j=0; j<numItems; j++)          // for each item in node
            {                               // are we less?
                if( theValue < theNode->getItem(j)->dData )
                    return theNode->getChild(j);  // return left child
            }                               // we're greater, so
            return theNode->getChild(j);     // return right child
        }

        void displayTree()
        {
            recDisplayTree(root, 0, 0);
        }

        void recDisplayTree(Node * thisNode, int level, int childNumber)
        {
            cout << "level=" << level << " child=" << childNumber << " ";
            thisNode->displayNode();               // display this node

            // call ourselves for each child of this node
            int numItems = thisNode->getNumItems();
            for(int j=0; j<numItems+1; j++)
            {
                Node * nextNode = thisNode->getChild(j);
                if(nextNode != NULL)
                    recDisplayTree(nextNode, level+1, j);
                 else
                    return;
            }
        }  // end recDisplayTree()

};  // end class Tree234

