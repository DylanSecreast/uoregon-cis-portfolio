#include "tree234.cpp"

int main(int argc, char * argv[])
{
	long value;
	Tree234 theTree;
	bool done = false;

	theTree.insert(50);
	theTree.insert(40);
	theTree.insert(60);
	theTree.insert(30);
	theTree.insert(70);

	while (!done)
	{
		cout << "Enter first letter of ";
		cout << "show, insert, find, or quit: ";

		char choice;
		cin >> choice;

		switch (choice)
		{
		case 's':
			theTree.displayTree();
			break;
		case 'i':
			cout << "Enter value to insert: ";
			cin >> value;
			theTree.insert(value);
			break;
		case 'f':
			cout << "Enter value to find: ";
			cin >> value;
			if (theTree.find(value) != -1)
				cout << "Found " << value << endl;
			else
				cout << "Could not find " << value << endl;
			break;
		case 'q':
			done = true;
			break;
		default:
			cout << "Invalid entry\n";
		}  // end switch
	}  // end while
}  // end main()
