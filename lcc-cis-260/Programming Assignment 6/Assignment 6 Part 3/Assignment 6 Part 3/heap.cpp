// heap.cpp
// modified from heap.java by jim bailey
// demonstrates heaps

#include <iostream>
#include <string>
using namespace std;


class Node
{
    private:
        int iData;             // data item (key)

    public:
        Node(int key)           // constructor
        { 
            iData = key; 
        }

        int getKey()
        { 
            return iData; 
        }

        void setKey(int id)
        { 
            iData = id; 
        }

};  // end class Node


class Heap
{
    private:
        Node **heapArray;
        int maxSize;           // size of array
        int currentSize;       // number of nodes in array

    public:
        Heap(int mx)            // constructor
        {
            maxSize = mx;
            currentSize = 0;
            heapArray = new Node * [maxSize];  // create array
        }

        bool isEmpty()
        { 
            return currentSize == 0; 
        }

        bool insert(int key)
        {
            if( currentSize == maxSize )
                return false;
            
            Node * newNode = new Node(key);
            heapArray[currentSize] = newNode;
            trickleUp(currentSize++);
            return true;
        }  // end insert()

        void trickleUp(int index)
        {
            int parent = (index-1) / 2;
            Node * bottom = heapArray[index];

            while( index > 0 && heapArray[parent]->getKey() < bottom->getKey() )
            {
                heapArray[index] = heapArray[parent];  // move it down
                index = parent;
                parent = (parent-1) / 2;
            }  // end while
      
            heapArray[index] = bottom;
        }  // end trickleUp()

        Node * remove()           // delete item with max key
        {                           // (assumes non-empty list)
            Node * root = heapArray[0];
            heapArray[0] = heapArray[--currentSize];
            trickleDown(0);
            return root;
        }  // end remove()

        void trickleDown(int index)
        {
            int largerChild;
            Node * top = heapArray[index];       // save root
            
            while(index < currentSize/2)       // while node has at
            {                               //    least one child,
                int leftChild = 2*index+1;
                int rightChild = leftChild+1;
                                         // find larger child
                if(rightChild < currentSize && heapArray[leftChild]->getKey() < heapArray[rightChild]->getKey())
                    largerChild = rightChild;
                else
                    largerChild = leftChild;
                    
                                         // top >= largerChild?
                if( top->getKey() >= heapArray[largerChild]->getKey() )
                    break;
                                         // shift child up
                heapArray[index] = heapArray[largerChild];
                index = largerChild;            // go down
            }  // end while
            
            heapArray[index] = top;            // root to index
        }  // end trickleDown()

        bool change(int index, int newValue)
        {
            if(index<0 || index>=currentSize)
                return false;
                
            int oldValue = heapArray[index]->getKey(); // remember old
            heapArray[index]->setKey(newValue);  // change to new

            if(oldValue < newValue)             // if raised,
                trickleUp(index);                // trickle it up
            else                                // if lowered,
                trickleDown(index);              // trickle it down
                
            return true;
        }  // end change()

        void displayHeap()
        {
            cout << "heapArray: ";    // array format
            
            for(int m=0; m<currentSize; m++)
                if(heapArray[m] != NULL)
                    cout << heapArray[m]->getKey() << " ";
                else
                    cout << "-- ";
                    
            cout << endl;
                                          // heap format
            int nBlanks = 32;
            int itemsPerRow = 1;
            int column = 0;
            int j = 0;                          // current item
            string dots = "...............................";
            cout << dots+dots << endl;      // dotted top line

            while(currentSize > 0)              // for each heap item
            {
                if(column == 0)                  // first item in row?
                    for(int k=0; k<nBlanks; k++)  // preceding blanks
                        cout << ' ';
                                          // display item
                cout << heapArray[j]->getKey();

                if(++j == currentSize)           // done?
                    break;

                if(++column == itemsPerRow)        // end of row?
                {
                    nBlanks /= 2;                 // half the blanks
                    itemsPerRow *= 2;             // twice the items
                    column = 0;                   // start over on
                    cout << endl;         //    new row
                }
                else                             // next item on row
                    for(int k=0; k<nBlanks*2-2; k++)
                        cout << ' ';     // interim blanks
            }  // end while
      
            cout << "\n" << dots+dots << endl; // dotted bottom line
        }  // end displayHeap()

};  // end class Heap

/*
int main(int argc, char * argv[])
{
    int value, value2;
    Heap theHeap(31);  // make a Heap; max size 31
    bool done = false;

    theHeap.insert(70);           // insert 10 items
    theHeap.insert(40);
    theHeap.insert(50);
    theHeap.insert(20);
    theHeap.insert(60);
    theHeap.insert(100);
    theHeap.insert(80);
    theHeap.insert(30);
    theHeap.insert(10);
    theHeap.insert(90);

    while( !done )                
    {
        cout << "Enter first letter of ";
        cout << "show, insert, remove, change, or quit: ";\
        char choice;
        
        cin >> choice;

        switch(choice)
        {
            case 's':                        // show
                theHeap.displayHeap();
                break;
            case 'i':                        // insert
                cout << "Enter value to insert: ";
                cin >> value;

                if( !theHeap.insert(value) )
                    cout << "Can't insert; heap full" << endl;
                break;
            case 'r':                        // remove
                if( !theHeap.isEmpty() )
                {
                    value = theHeap.remove()->getKey();
                    cout << " removed " << value << endl;
                }
                else
                    cout << "Can't remove; heap empty" << endl;
                break;
            case 'c':                        // change
                cout << "Enter current index of item: ";
                cin >> value;
                cout << "Enter new key: ";
                cin >> value2;
                if( !theHeap.change(value, value2) )
                    cout << "Invalid index" << endl;
                break;
            case 'q':
                done = true;
                break;
            default:
                cout << "Invalid entry\n";
        }  // end switch
    }  // end while
} 
*/