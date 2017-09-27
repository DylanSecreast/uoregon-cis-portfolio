// priorityQ.cpp
// modified from priorityQ.java by jim bailey
// demonstrates priority queue

////////////////////////////////////////////////////////////////
#include <iostream>
#include "heap.cpp"

using namespace std;


class PriorityQ
{
   // array in sorted order, from max at 0 to min at size-1
    private:
		Heap* heap;
        int maxSize;
        long *queArray;
        int nItems;

    public:
        PriorityQ(int s)          // constructor
        {
            maxSize = s;
            queArray = new long(maxSize);
            nItems = 0;
        }

        void insert(long item)    // insert item
        {
            int j;

                // if no items insert new item at location 0
            if(nItems == 0)                         
                queArray[nItems++] = item; 
                
                // else, start at end, move smaller items up and insert in hole     
            else                               
            {
                for(j=nItems-1; j>=0; j--)        
                    if( item > queArray[j] )      
                        queArray[j+1] = queArray[j]; 
                    else                        
                        break;                    
        
                queArray[j+1] = item;           
                nItems++;
            }  
        }  

        long remove()             // remove minimum item
        { 
            return queArray[--nItems]; 
        }
        
        long peekMin()            // peek at minimum item
        { 
            return queArray[nItems-1]; 
        }

        bool isEmpty()         // true if queue is empty
        { 
            return (nItems == 0); 
        }

        bool isFull()          // true if queue is full
        { 
            return (nItems == maxSize); 
        }

};  

