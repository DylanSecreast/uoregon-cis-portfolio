/*
Dylan Secreast
1/26/14
CS 162 C+ Winter 2014
Lab 3 - Chips and Salsa (Revised)
main.cpp
*/

#include <iostream>
#include "ChipsAndSalsa.h"


using namespace std;

int main()
{
	Salsa sales;
	int salsaChoice = 0,
		jarsChoice = 0;
	

	cout << "***************\n" 
		<< "Chips and Salsa\n"
		<< "***************\n\n";
	
	// Input jars sold for each type of salsa
	for (int index = 0; index < Salsa::NUM_OF_SALSAS; index++)
	{
		cout << "Enter # of " << sales.getSalsaName(index) << " jars sold: ";
		cin >> jarsChoice;
		if (jarsChoice < 0)		// Do not accept negative values
		{
			cout << "****************************\n"
				<< jarsChoice << " is an invalid # of jars"
				<< "\n****************************\n"
				<< "Please reinput # of " << sales.getSalsaName(index) << " jars sold: ";
			cin >> jarsChoice;
			cout << endl;
		}
		sales.setJars(index, jarsChoice);
	}
	
	
	// Independently displays all values inputed to jars array
	cout << "\n------------------\n";
	cout << "Sales Report:\n"
		<< "------------------\n";
	for (int index = 0; index < Salsa::NUM_OF_SALSAS; index++)
	{
		cout << "# of " << sales.getSalsaName(index) << " jars sold: " << sales.getJars(index) << endl;
	}
	cout << endl;


	// Displays sum value of all # inputed to jars array
	cout << "Total # of jars sold: " << sales.getTotalSales() << endl << endl;


	// Displays best selling salsa
	cout << "Best selling salsa: " << sales.getBestSeller() << endl;


	// Displays worst selling salsa
	cout << "Worst selling salsa: " << sales.getWorstSeller() << endl;

	




	/*	
	// TEST DRIVERS FOR ALL FUNCTIONS IN SALSA CLASS

	int salsaChoice = 0;
	int jarsChoice = 0;
    Salsa sales;

	// Test salsa array values
	cout << "Test 'salsaNames' string array value (0-4): ";
	cin >> salsaChoice;
	cout << "salsaNames[" << salsaChoice << "]" << " is: " << sales.getSalsaName(salsaChoice) << endl;

	cout << "------------------------------\n";

	// Test jar array input
	for (int index = 0; index < 5; index++)
	{
		cout << "Enter # of jars for array value jars[" << index << "]: ";
		cin >> jarsChoice;
		sales.setJars(index, jarsChoice);
	}

	cout << "------------------------------\n";

	// Independently displays all values inputed to jars array
	for (int index = 0; index < 5; index++)
	{
		cout << "Value stored in jars[" << index << "]: " << sales.getJars(index) << endl;
	}
	
	cout << "------------------------------\n";

	// Displays sum value of all # inputed to jars array
	cout << "Total # of jars entered: " << sales.getTotalSales() << endl;

	cout << "------------------------------\n";

	// Displays best selling salsa
	cout << "Best selling salsa: " << sales.getBestSeller() << endl;
	

	// Displays worst selling salsa
	cout << "Worst selling salsa: " << sales.getWorstSeller() << endl;
	*/


    return 0;
}
