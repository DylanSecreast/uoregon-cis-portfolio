#include "hash.cpp"

int main(int argc, char * argv[])
{
	DataItem * aDataItem;
	int aKey, size, n, keysPerCell;
	bool done = false;
	char choice;
	// get sizes
	cout << "Enter size of hash table: ";
	cin >> size;

	cout << "Enter initial number of items: ";
	cin >> n;

	keysPerCell = 10;
	// make table
	HashTable theHashTable(size);

	for (int j = 0; j<n; j++)        // insert data
	{
		aKey = (int)(rand() % (keysPerCell * size));
		aDataItem = new DataItem(aKey);
		theHashTable.insert(aDataItem);
	}

	while (!done)                   // interact with user
	{
		cout << "Enter first letter of ";
		cout << "show, insert, remove, find, or quit: ";

		cin >> choice;

		switch (choice)
		{
		case 's':
			theHashTable.displayTable();
			break;
		case 'i':
			cout << "Enter key value to insert: ";
			cin >> aKey;
			aDataItem = new DataItem(aKey);
			theHashTable.insert(aDataItem);
			break;
		case 'r':
			cout << "Enter key value to remove: ";
			cin >> aKey;
			aDataItem = theHashTable.remove(aKey);
			if (aDataItem != NULL)
			{
				cout << "Found and removed " << aKey << endl;
				delete aDataItem;
			}
			else
				cout << "Could not find " << aKey << endl;
			break;
		case 'f':
			cout << "Enter key value to find: ";
			cin >> aKey;
			aDataItem = theHashTable.find(aKey);
			if (aDataItem != NULL)
				cout << "Found " << aKey << endl;
			else
				cout << "Could not find " << aKey << endl;
			break;
		case 'q':
			done = true;
			break;
		default:
			cout << "Invalid entry\n";
		}  // end switch
	}  // end while
}  // end main()