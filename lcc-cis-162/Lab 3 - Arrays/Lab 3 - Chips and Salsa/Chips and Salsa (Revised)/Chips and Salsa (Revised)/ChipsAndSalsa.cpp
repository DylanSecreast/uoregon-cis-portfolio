/*
Dylan Secreast
1/26/14
CS 162 C+ Winter 2014
Lab 3 - Chips and Salsa (Revised)
ChipsAndSalsa.cpp
*/

#include "ChipsAndSalsa.h"

//	SALSA CLASS DEFINITIONS //


// Default constructor
Salsa::Salsa()
{
	// Initialize salsaNames string array
    salsaNames[0] = "Mild";
	salsaNames[1] = "Medium";
	salsaNames[2] = "Sweet";
	salsaNames[3] = "Hot";
	salsaNames[4] = "Zesty";

	// Initialize jars array with empty int data
	for (int count = 0; count < NUM_OF_SALSAS; count++)
	{
		jars[count] = 0;
	}
}


// Returns name of salsa as string
std::string Salsa::getSalsaName(int index)
{
	if (index >= 0 && index <= NUM_OF_SALSAS)
	{
		return salsaNames[index];
	}
	else
	{
		return "Invalid salsa choice.";
	}
}


// Sets input values into jar array after data validation (no negative values)
bool Salsa::setJars(int index, int choice)
{
	if (index >= 0 && index <= NUM_OF_SALSAS)
	{
		if (choice >= 0)
		{
			jars[index] = choice;
			return true;
		}
		else
		{
			return false;
		}
	}
}


// Returns jars array values
int Salsa::getJars(int index)
{
	for (int count = 0; count < NUM_OF_SALSAS; count++)
	{
		return jars[index];
	}
}


// Calculates and returns total jar sales
int Salsa::getTotalSales()
{
	int total = 0;
	for (int count = 0; count < NUM_OF_SALSAS; count++)
	{
		total += jars[count];
	}
	return total;
}


// Returns best selling salsa type
std::string Salsa::getBestSeller()
{
	int maxIndex = 0;
	int max = jars[0];
	
	for (int count = 1; count < NUM_OF_SALSAS; count++)
	{
		if (max < jars[count])
		{
			max = jars[count];
			maxIndex = count;
		}
	}
	return salsaNames[maxIndex];
}


// Returns worst selling salsa
std::string Salsa::getWorstSeller()
{
	int minIndex = 0;
	int min = jars[0];

	for (int count = 1; count < NUM_OF_SALSAS; count++)
	{
		if (min > jars[count])
		{
			min = jars[count];
			minIndex = count;
		}
	}
	return salsaNames[minIndex];
}