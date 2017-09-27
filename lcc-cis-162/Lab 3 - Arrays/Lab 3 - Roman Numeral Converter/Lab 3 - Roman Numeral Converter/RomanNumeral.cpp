/*
Dylan Secreast
1/30/14
CS 162 C+ Winter 2014
Lab 3 - Arrays
Roman Numerals.cpp
*/

#include "RomanNumeral.h"


// Roman Numeral Class Definition

// Default constructor
RomanNumeral::RomanNumeral()
{
	// Initialize numeral string array
	numeral[0] = "I";
	numeral[1] = "II";
	numeral[2] = "III";
	numeral[3] = "IV";
	numeral[4] = "V";
	numeral[5] = "VI";
	numeral[6] = "VII";
	numeral[7] = "VIII";
	numeral[8] = "IX";
	numeral[9] = "X";
	numeral[10] = "XI";
	numeral[11] = "XII";
	numeral[12] = "XIII";
	numeral[13] = "XIV";
	numeral[14] = "XV";
	numeral[15] = "XVI";
	numeral[16] = "XVII";
	numeral[17] = "XVIII";
	numeral[18] = "XIX";
	numeral[19] = "XX";
}


// Convert number and return equivalent numeral value after input validation
std::string RomanNumeral::getNumeral(int myNumber)
{
	if (myNumber >= 0 && myNumber <= 20)
	{
		for (int count = 0; count <= ROMAN_NUMERALS; count++)
			return numeral[myNumber - 1];
	}
	else
	{
		return "Invalid Number";
	}
}

