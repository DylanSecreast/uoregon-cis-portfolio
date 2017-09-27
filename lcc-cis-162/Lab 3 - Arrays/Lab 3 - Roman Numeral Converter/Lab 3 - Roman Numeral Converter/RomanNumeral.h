/*
Dylan Secreast
1/30/14
CS 162 C+ Winter 2014
Lab 3 - Arrays
Roman Numeral Header.h
*/

#ifndef ROMANNUMERAL_HEADER
#define ROMANNUMERAL_HEADER

#include <string>


// Roman Numeral Class Declaration

class RomanNumeral
{
public:
	static const int ROMAN_NUMERALS = 20;

private:
	std::string numeral[ROMAN_NUMERALS];
	int numbers[ROMAN_NUMERALS];

public:
	RomanNumeral();								// Initialize numeral string array
	std::string getNumeral(int myNumber);		// Returns valid roman numeral	
};


#endif // ROMANNUMERAL_HEADER