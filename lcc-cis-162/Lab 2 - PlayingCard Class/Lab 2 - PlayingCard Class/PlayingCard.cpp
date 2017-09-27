/*
Dylan Secreast
2/7/14
CS 162 C+ Winter 2014
Lab 2 - PlayingCard Class (Revised 2/7/14)
PlayingCard.cpp
*/

#include "PlayingCard.h"
#include <iostream>
#include <string>


/*****************************
PlayingCard Class Definitions:
*****************************/


// Overloaded constructor, checks for valid myValue and mySuit. If they are valid it sets value and suit to those values. If either of them is not valid, it sets them both to '0'.
PlayingCard::PlayingCard(char myValue, char mySuit)
{
	if (isGood(myValue, mySuit) == true)
	{
		value = myValue;
		suit = mySuit;
	}
	else
	{
		value = '0';
		suit = '0';
	}
}


// Checks for valid myValue and mySuit. If they are valid it sets value and suit to those values. If either of them is not valid, it returns false and does not change any values.
bool PlayingCard::setCard(char myValue, char mySuit)
{
	if (isGood(myValue, mySuit) == true)
	{
		value = myValue;
		suit = mySuit;
		return value, suit;
	}
	else
	{
		return false;
	}
}


// Returns a string containing the 2 characters associated with the card
std::string PlayingCard::getCardCode()
{
	cardCode = value;
	cardCode += suit;
	return cardCode;
}


// Tests for good card values
bool PlayingCard::isGood(char myValue, char mySuit)
{
	if (myValue == 'A' || myValue == 'T' || myValue == 'J' || myValue == 'Q' || myValue == 'K' || (myValue >= '2' && myValue <= '9'))
	{
		if (mySuit == 'C' || mySuit == 'D' || mySuit == 'S' || mySuit == 'H')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}