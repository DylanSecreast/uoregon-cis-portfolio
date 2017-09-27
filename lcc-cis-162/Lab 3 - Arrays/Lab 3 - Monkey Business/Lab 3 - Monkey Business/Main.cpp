/*
Dylan Secreast
1/29/14
CS 162 C+ Winter 2014
Lab 3 - Monkey Business
Main.cpp
*/

#include "Monkey.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	Monkey business;

	cout << "***************\n"
		<< "Monkey Business\n"
		<< "***************\n";

	// Get input data from user
	for (int mnky = 0; mnky < Monkey::NUM_MONKEYS; mnky++)
	{
		cout << "\nEnter lbs. of food eaten by Monkey #" << (mnky + 1) << " on...\n";
		for (int day = 0; day < Monkey::NUM_DAYS; day++)
		{
			int food = 0;
			cout << "Day " << (day + 1) << ": ";
			cin >> food;
			if (food < 0)
			{
				cout << "********************************\n"
					<< food << " is an invalid amount of food\n"
					<< "********************************\n"
					<< "Please enter lbs. of food eaten by Monkey # " << (mnky + 1) << " on...\n"
					<< "Day " << (day + 1) << ": ";
				cin >> food;
			}
			business.setMonkeyFood(mnky, day, food);
		}
	}


	// Report data
	cout << "\n\n----------------------\n"
		<< "Food Report:\n"
		<< "----------------------\n";


	// Display average lbs per day
	cout << "Average lbs. of food consumed by whole family of monkeys on...";
	for (int day = 0; day < Monkey::NUM_DAYS; day++)
	{
		cout << "\nDay " << (day +1) << ": " << setprecision(3) << business.getAveragePerDay(day);
	}


	// Display the least amount of food eaten during the week by any one monkey
	cout << "\n\nThe least amount of food eaten during the week by any one monkey: " << business.getSkinnyMonkey() << " lbs.\n";


	// Display the greatest amount of food eaten during the week by any one monkey
	cout << "The greatest amount of food eaten during the week by any one monkey: " << business.getFatMonkey() << " lbs.\n";






	return 0;
}