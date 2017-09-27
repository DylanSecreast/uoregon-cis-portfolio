/*
Dylan Secreast
1/30/14
CS 162 C+ Winter 2014
Lab 3 - Arrays
main.cpp
*/

using namespace std;
#include "RomanNumeral.h"
#include <iostream>


// Roman Numeral Conversion Function

int main()
{
	RomanNumeral roNum;
	int choice = 1;

	cout << "***********************\n"
		<< "Roman Numeral Converter\n"
		<< "***********************\n\n";

	for (int count = 0; count < RomanNumeral::ROMAN_NUMERALS; count++)
	{
		cout << "Enter a whole number 1-20 (0 to quit): ";
		// choice = 4;		// TEST DRIVER
		// choice = -2;		// TEST DRIVER
		cin >> choice;
		while (choice < 0 || choice > RomanNumeral::ROMAN_NUMERALS)
		{
			cout << "\n************************\n"
				<< choice << " is a invalid number\n"
				<< "************************\n\n"
				<< "Please reenter a whole number 1-20 (0 to quit): ";
			cin >> choice;
		}
		if (choice == 0)
		{
			break;
		}

		cout << "The number " << choice 
			<< " has a roman numeral equivalent of: "
			// roNum.getNumeral(4)		// TEST DRIVER
			<< roNum.getNumeral(choice) << endl << endl;
	}
	return 0;
}