// hash.cpp
// modified from hash.java by jim bailey
// demonstrates hash table with linear probing

#include <iostream>
using namespace std;

class DataItem
{                                
    private:
        int iData;               // data item (key)

    public:
        DataItem(int ii)          // constructor
        { 
            iData = ii; 
        }

        int getKey()
        { 
            return iData; 
        }
};  // end class DataItem


class HashTable
{
    private:
        DataItem ** hashArray;    // array holds hash table (pointers to DataItems)
        int arraySize;
        int numItems;
        DataItem * nonItem;        // for removed items
    
    public:
        HashTable(int size)       // constructor
        {
            arraySize = size;
            numItems = 0;
            hashArray = new DataItem * [arraySize];
            
                // create a nonItem with a key of -1
            nonItem = new DataItem(-1);   
            
                // initialize array to NULLs
            for ( int i = 0; i < arraySize; i++ )
                hashArray[i] = NULL;
        }

        void displayTable()
        {
            cout << "Table: ";
      
            for(int j=0; j<arraySize; j++)
                if(hashArray[j] != NULL)
                    cout << hashArray[j]->getKey() << " ";
                else
                    cout << "** ";

            cout << endl;
        }

        int hashFunc(int key)
        {
            return key % arraySize;       // hash function
        }

        void insert(DataItem * item) // insert a DataItem
        {
                // note, keep count one less than max to allow find to not loop forever
            if ( numItems == arraySize -1 )
            {
                cout << "array is full, can not insert!!" << endl;
                return;
            }
      
            int key = item->getKey();      // extract key
            int hashVal = hashFunc(key);  // hash the key
            
                // until empty cell or removed cell,
            while(hashArray[hashVal] != NULL && hashArray[hashVal] != nonItem)
            {
                ++hashVal;                 // go to next cell
                hashVal %= arraySize;      // wraparound if necessary
            }
            
            hashArray[hashVal] = item;    // insert item
            numItems++;                   // increment count
        }  // end insert()

 
        DataItem * remove(int key)  // remove a DataItem
        {
            int hashVal = hashFunc(key);  // hash the key

            while(hashArray[hashVal] != NULL)  // until empty cell,
            {                               
                    // found the key?
                if(hashArray[hashVal]->getKey() == key)
                {
                    DataItem * temp = hashArray[hashVal]; // save item
                    hashArray[hashVal] = nonItem;       // remove item
                    numItems--;                         // decrement count
                    return temp;                        // return item
                }
         
                ++hashVal;                 // go to next cell
                hashVal %= arraySize;      // wraparound if necessary
            }
      
            return NULL;                  // can't find item
        }  // end remove()

        DataItem * find(int key)    // find item with key
        {
            int hashVal = hashFunc(key);  // hash the key

            while(hashArray[hashVal] != NULL)  // until empty cell,
            {                               // found the key?
                if(hashArray[hashVal]->getKey() == key)
                    return hashArray[hashVal];   // yes, return item
                    
                ++hashVal;                 // go to next cell
                hashVal %= arraySize;      // wraparound if necessary
            }
      
            return NULL;                  // can't find item
        }
        
};  // end class HashTable


