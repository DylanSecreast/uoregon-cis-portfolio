#include "Link.h"
using namespace std;

int main(){
	Link x;

	cout << "<< Inserting 'a' to list >>\n";
	x.insertItem('a');

	cout << "<< Inserting 'b' to list >>\n";
	x.insertItem('b');

	cout << "<< Inserting 'c' to list >>\n";
	x.insertItem('c');

	cout << "<< Inserting 'd' to list >>\n\n";
	x.insertItem('d');

	cout << "<< Displaying currernt list >>\n";
	x.displayList();

	cout << "\n<< Stepping forward 3 steps >>\n\n";
	x.stepLink(3);

	cout << "<< Deleting current link, returning value >>\n";
	x.deleteItem();

	cout << "\n\n<< Inserting '0' to list >>\n\n";
	x.insertItem('0');

	cout << "<< Displaying current list >>\n";
	x.displayList();

	return 0;
}