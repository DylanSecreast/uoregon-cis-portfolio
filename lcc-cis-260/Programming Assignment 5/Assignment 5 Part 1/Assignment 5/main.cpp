#include "Tree.h"
#include <iostream>
#include <string>
using namespace std;


// Main from Tree.h
int main(int argc, char * argv[])
{
string value;
int traverse;
bool done = false;
Node * found;
Tree theTree;

cout << " before insert " << endl;

theTree.insert("middle", 1.5);

cout << " after first insert " << endl;
theTree.insert("grape", 1.2);
cout << " after second insert " << endl;
theTree.insert("apple", 1.7);
theTree.insert("house", 1.5);
theTree.insert("pine", 1.2);
theTree.insert("tree", 1.7);
theTree.insert("never", 1.5);


while (!done){

	cout << "\nEnter first letter of show, ";
	cout << "insert, find, remove, traverse, or quit: ";

	char choice;
	cin >> choice;
	cout << endl;

	switch (choice){
	case 's':
		theTree.displayTree();
		break;
	case 'i':
		cout << "Enter word to insert: ";
		cin >> value;
		theTree.insert(value, 0.9);
		//theTree.insert(value, value + 0.9);
		break;
	case 'f':
		cout << "Enter word to find: ";
		cin >> value;
		found = theTree.find(value);
		if (found != NULL)
		{
			cout << "Found: ";
			found->displayNode();
			cout << endl;
		}
		else
			cout << "Could not find '" << value << "'" << endl;
		break;
	case 'r':
		cout << "Enter word to remove: ";
		cin >> value;
		if (theTree.remove(value))
			cout << "Removed '" << value << "'" << endl;
		else
			cout << "'" << value << "' " << "not found, could not remove" << endl;
		break;
	case 't':
		cout << "Enter 1 (preorder), 2 (inorder), or 3 (postorder): ";
		cin >> traverse;
		theTree.traverse(traverse);
		break;
	case 'q':
		done = true;
		break;
	default:
		cout << "Invalid entry\n";
	}// end switch
}  // end while

return 0;
}  // end main()
