/*
Dylan Secreast
2/7/14 (Revised 3/14/14)
CS 162 C+ Winter 2014
Lab 2 - PlayingCard Class (Revised 2/7/14)
PlayingCard.h
*/

#ifndef PLAYINGCARD_H_INCLUDED
#define PLAYINGCARD_H_INCLUDED

#include <string>


/******************************
Playing Card Class Declaration:
******************************/


class PlayingCard
{
private:
	char value;									// Holds valid card value
	char suit;									// Holds valid card suit
	std::string cardCode;						// Holds valid card value & suit (card code)
	bool isGood(char myValue, char mySuit);		// Tests for valid card value & suit. Returns true if the card is a valid card, false if it is not.

public:
	PlayingCard(){ value = '0', suit = '0'; }			// Default constructor
	PlayingCard(char myValue, char mySuit);				// Overloaded constructor
	bool setCard(char myValue, char mySuit);			// Checks for valid myValue and mySuit
	char getValue() { return value; }					// Returns the card's value, one of "A23456789TJQK"
	char getSuit() { return suit; }						// Returns the card's suit, one of "CHDS"
	std::string getCardCode();							// Returns a string containing the 2 characters associated with the card
	bool isValid(){ return isGood(value, suit); }		// Returns valid card value & suit
	};


#endif	// PLAYINGCARD_H_INCLUDED