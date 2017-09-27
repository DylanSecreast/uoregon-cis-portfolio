/*
Dylan Secreast
1/26/14
CS 162 C+ Winter 2014
Lab 3 - Chips and Salsa (Revised)
ChipsAndSalsa.h
*/

#ifndef CHIPSANDSALSA_H
#define CHIPSANDSALSA_H

#include <string>


// SALSA CLASS DECLARATION //
class Salsa
{
	public:
		const static int NUM_OF_SALSAS = 5;

    private:
		std::string salsaNames[NUM_OF_SALSAS];
		int jars[NUM_OF_SALSAS];

    public:
        Salsa();								// Salsa names stored in array
        std::string getSalsaName(int index);	// Returns name of salsa as string
		bool setJars(int index, int choice);	// Sets input values into jar array
		int getJars(int index);					// Returns jars array values
		int getTotalSales();					// Calculates and returns total jar sales
		std::string getBestSeller();			// Returns best selling salsa
		std::string getWorstSeller();			// Returns worst selling salsa

};
#endif // CHIPSANDSALSA_H