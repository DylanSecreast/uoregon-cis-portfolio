class QuickSort
{
private:
	long *theArray;          // ref to array theArray
	int nElems;               // number of data items
	int medianIndex;

public:
	QuickSort(int max);          // constructor

	void insert(long value);    // put element into array
	void display();             // displays array contents
	void quickSort();
	int getMedian();
	void findMedianIndex(int left, int right);
	void recQuickSort(int left, int right);
	long medianOf3(int left, int right);
	void swap(int dex1, int dex2);
	int partitionIt(int left, int right, long pivot);
	void manualSort(int left, int right);
};