#include "heap.cpp"

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

	while (!done)
	{
		cout << "Enter first letter of ";
		cout << "show, insert, remove, change, or quit: "; \
			char choice;

		cin >> choice;

		switch (choice)
		{
		case 's':                        // show
			theHeap.displayHeap();
			break;
		case 'i':                        // insert
			cout << "Enter value to insert: ";
			cin >> value;

			if (!theHeap.insert(value))
				cout << "Can't insert; heap full" << endl;
			break;
		case 'r':                        // remove
			if (!theHeap.isEmpty())
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
			if (!theHeap.change(value, value2))
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