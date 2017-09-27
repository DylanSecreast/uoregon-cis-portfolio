#include "QuickSort.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	int maxSize = 21;             // array size
	QuickSort arr(maxSize);        // create the array


	for (int j = 0; j<maxSize; j++)  // fill array with
	{                          // random numbers
		long n = (long)(rand() % 100);
		arr.insert(n);
	}

	arr.display();                // display items
	arr.quickSort();              // quicksort them
	arr.display();                // display them again
	cout << endl;
	cout << "Median: " << arr.getMedian() << endl;
}