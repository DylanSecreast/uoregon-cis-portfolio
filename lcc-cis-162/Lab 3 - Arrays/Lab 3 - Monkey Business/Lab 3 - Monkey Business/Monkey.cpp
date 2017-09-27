/*
Dylan Secreast
1/29/14
CS 162 C+ Winter 2014
Lab 3 - Monkey Business
Monkey.cpp
*/

#include "Monkey.h"

// MONKEY CLASS DEFINITIONS //


// Initialize 2D array in default constructor
Monkey::Monkey()
{
	for (int mnky = 0; mnky < NUM_MONKEYS; mnky++)
	{
		for (int days = 0; days < NUM_DAYS; days++)
		{
			monkeyFood[mnky][days] = 0;
		}
	}
}


// Set input data into 2D array
bool Monkey::setMonkeyFood(int mnky, int day, int food)
{
	if (mnky <= NUM_MONKEYS && day <= NUM_DAYS && food >= 0)
	{
		monkeyFood[mnky][day] = food;
		return true;
	}
	else
	{
		return false;
	}
}


// Calculate and return average lbs of food consumed per day from input data in 2D monkeyFood array
double Monkey::getAveragePerDay(int day)
{
	double averageDay = 0;
	double total = 0;

		for (int row = 0; row < NUM_MONKEYS; row++)		// Sums columns
		{
			total += monkeyFood[row][day];
		}

	averageDay = (total / NUM_MONKEYS);
	return averageDay;
}


// Calculate and return least amount of food eaten during the week by any one monkey
int Monkey::getSkinnyMonkey()
{
	int minMonkey = 0;
	int minDay = 0;
	int min = monkeyFood[0][0];

	for (int mnky = 0; mnky < NUM_MONKEYS; mnky++)
	{
		for (int day = 0; day < NUM_DAYS; day++)
		{
			if (min > monkeyFood[mnky][day])
			{
				min = monkeyFood[mnky][day];
				minMonkey = mnky;
				minDay = day;
			}
		}
	}
	return monkeyFood[minMonkey][minDay];

}


// Calculate and return largest amount of food eaten during the week by any one monkey
int Monkey::getFatMonkey()
{
	int maxMonkey = 0;
	int maxDay = 0;
	int max = monkeyFood[0][0];

	for (int mnky = 0; mnky < NUM_MONKEYS; mnky++)
	{
		for (int day = 0; day < NUM_DAYS; day++)
		{
			if (max < monkeyFood[mnky][day])
			{
				max = monkeyFood[mnky][day];
				maxMonkey = mnky;
				maxDay = day;
			}
		}
	}
	return monkeyFood[maxMonkey][maxDay];

}



