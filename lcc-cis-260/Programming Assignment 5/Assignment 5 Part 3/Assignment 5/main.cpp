// reading a text file
// this does not do full error checking

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	// open the file for reading
	ifstream myfile("diamond_input.txt", ios::in);

	// if was not able to open, go away
	if (!myfile.is_open())
	{
		cout << "Unable to open file";
		return 1;
	}

	int numDiamonds;
	int numTaxes;
	int * diamonds;
	int * taxes;
	bool done = false;

	while (!done)
	{
		// get the number of diamonds
		// if -1 done with input
		myfile >> numDiamonds;
		if (numDiamonds == -1)
		{
			done = true;
			break;
		}

		// allocate space to save diamonds
		// and get them
		diamonds = new int[numDiamonds];
		for (int i = 0; i < numDiamonds; i++)
		{
			myfile >> diamonds[i];
		}

		// get the number of taxes
		myfile >> numTaxes;

		// allocate space to save taxes
		// and get them
		taxes = new int[numTaxes];
		for (int i = 0; i < numTaxes; i++)
		{
			myfile >> taxes[i];
		}

		// show what we got
		cout << " There were " << numDiamonds << " diamonds read: ";
		for (int i = 0; i < numDiamonds; i++)
		{
			cout << diamonds[i] << " ";
		}
		cout << endl;
		cout << " There were " << numTaxes << " taxes read: ";
		for (int i = 0; i < numTaxes; i++)
		{
			cout << taxes[i] << " ";
		}
		cout << endl << endl;

		// delete allocated space
		delete[] diamonds;
		delete[] taxes;

	}

	cout << "Done with file \n";


	// close the file before quitting
	myfile.close();

	return 0;
}