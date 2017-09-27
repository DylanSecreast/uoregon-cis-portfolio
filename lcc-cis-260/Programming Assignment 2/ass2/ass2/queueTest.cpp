#include <iostream>
#include <iomanip>

#include "Deque.h"
#include "Stack.h"
#include "PriorityQueue.h"


using namespace std;

int main()
{
    int lineCount = 0;
    const int countPerLine = 7;
	/*
        // testing double ended queue
    cout << "testing double ended queue \n";
    cout << "first as fifo from each side \n";
	Deque aQ(9);

	cout << "first add left, get left\n";
    aQ.addLeft(1);
    aQ.addLeft(2);
    aQ.addLeft(3);
    cout << "  last, sb 3 = " << aQ.getLeft() << " ";
    cout << " next, sb 2 = " << aQ.getLeft() << " ";
    cout << " first, sb 1 = " << aQ.getLeft() << endl;
	
	cout << "\nnext add right, get right\n";
	aQ.addRight(6);
	aQ.addRight(7);
	aQ.addRight(8);
    cout << "  last, sb 8 = " << aQ.getRight() << " ";
    cout << " next, sb 7 = " << aQ.getRight() << " ";
    cout << " first, sb 6 = " << aQ.getRight() << endl;
	
    cout << "\nnext as lifo from each side\n";
	Deque bQ(9);
	
	cout << "first add left, get right\n";
	aQ.addLeft(1);
    aQ.addLeft(2);
    aQ.addLeft(3);
    cout << "  first, sb 1 = " << aQ.getRight() << " ";
    cout << " next, sb 2 = " << aQ.getRight() << " ";
    cout << " last, sb 3 = " << aQ.getRight() << endl;

	cout << "now add right, get left\n";
	aQ.addRight(6);
	aQ.addRight(7);
	aQ.addRight(8);
	cout << "  first, sb 6 = " << aQ.getLeft() << " ";
    cout << " next, sb 7 = " << aQ.getLeft() << " ";
    cout << " last, sb 8 = " << aQ.getLeft() << endl;
	
	cout << "\n\nnow testing list functions\n";
	aQ.zeroOut();	// zero out array to make values more visible
    aQ.addLeft(33);
    aQ.addRight(43);
    aQ.addLeft(34);
    aQ.addRight(47);
	
		//cout << "array is " << aQ.dumpArray();
	cout << "listing left to right " << aQ.listLeftRight() << endl;
    cout << "listing right to left " << aQ.listRightLeft();
	*/
	
        // testing stack
    cout << " \n\nnow testing stack \n";
    Stack aStack(10);

    aStack.push(6);
    aStack.push(7);

    cout << " first peek, sb 7 = " << aStack.peek() << endl;
    cout << " next pop, sb 7 = " << aStack.pop() << endl;
    cout << " final pop, sb 6 = " << aStack.pop() << endl;
	/*
		// testing priorityQueue
	cout << "\n\nnow testing priority queue\n";
	PriorityQueue pQ(9);
	pQ.zeroOut(); // for display purposes
	pQ.addValue(1);
	pQ.addValue(33);
	pQ.addValue(23);
	pQ.addValue(2);
	pQ.addValue(17);
	pQ.addValue(95);
	pQ.addValue(6);
	pQ.addValue(6);
	pQ.addValue(7);
	cout << " before starting array is " << pQ.dumpArray() << endl;

	cout << " largest sb 95 = " << pQ.getLargest() << endl;
	cout << " next largest sb 33 = " << pQ.getLargest() << endl;
	cout << " smallest sb 1 = " << pQ.getSmallest() << endl;
	cout << " next smallest sb 2 = " << pQ.getSmallest() << endl;
	*/

	return 0;
}
