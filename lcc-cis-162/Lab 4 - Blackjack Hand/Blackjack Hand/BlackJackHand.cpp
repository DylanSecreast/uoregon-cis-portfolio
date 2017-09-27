/*
Dylan Secreast
2/7/14 (Revised 3/14/14)
CS 162 C+ Winter 2014
Lab 4 - Blackjack Hand
BlackJackHand.cpp
*/

#include "BlackJackHand.h"
#include "PlayingCard.h"
#include <iostream>


/*******************************
BlackJackHand Class Definitions:
*******************************/


// Default constructor
BlackJackHand::BlackJackHand()
{
	cardCount = 0;							// Initialize private member variable
	for (int i = 0; i < MAX_CARDS; i++)		
	{
		cardsInHand[i] = NULL;		// Initialize all the elements of the array to NULL
	}
}


// Overloaded constructor
BlackJackHand::BlackJackHand(PlayingCard *c1, PlayingCard *c2)
{
	cardCount = 0;							// Initialize private member variable
	for (int i = 0; i < MAX_CARDS; i++)		
	{
		cardsInHand[i] = NULL;		// Initialize all the elements of the array to NULL
	}

		cardsInHand[cardCount] = c1;		// Add c1 to the hand
		cardsInHand[cardCount + 1] = c2;	// Add c2 to the hand
		cardCount = cardCount + 2;			// Update cardCount with two initial cards added
}


// For adding a card to the hand
bool BlackJackHand::addCard(PlayingCard *card)
{
	if (getLowScore() == BUST || isBust() || isFull())	// If score of hand, counting all aces as 1, is = to 21 (const int), or score of hand, counting all aces as 1, is > 21 (const int), or # of cards in hand >= 5 (const int), then:
	{
		return false;
	}
	else
	{
		if (cardCount < MAX_CARDS)		// If # of cards in hand is < 5 (const int)
		{
			cardsInHand[cardCount] = card;	
			cardCount++;	// Update cardCount each time a card is successfully added to hand
			return true;
		}
		else
			return false;
	}
}


// Calculates numerical sum of all current cards in hand
int BlackJackHand::handScore(char cardRank)
{
	int score = 0;	// Temp variable to hold and return hand score as int 
		switch (cardRank)
		{
		case 'A': score += 1;
			break;
		case '2': score += 2;
			break;
		case '3': score += 3;
			break;
		case '4': score += 4;
			break;
		case '5': score += 5;
			break;
		case '6': score += 6;
			break;
		case '7': score += 7;
			break;
		case '8': score += 8;
			break;
		case '9': score += 9;
			break;
		case 'T': score += 10;
			break;
		case 'J': score += 10;
			break;
		case 'Q': score += 10;
			break;
		case 'K': score += 10;
			break;
		}
		return score;
}



// Blackjack allows an ace to count as either a 1 or an 11.
// This function returns the score of the hand counting the first ace in the hand as an 11.
// Make sure you don't count all the aces as 11.
int BlackJackHand::getHighScore()
{
	int highScore = 0;
	int aceCount = 0;
	for (int i = 0; i < cardCount; i++)
	{
		highScore += handScore(cardsInHand[i]->getValue());		// Get sum of numerical values of cards in hand
		
		if ((cardsInHand[i]->getValue()) == 'A')	// If card in hand has a char value of A
		{
			aceCount++;		// Keeps up to date count of aces in hand
			if (aceCount == 1)		// Finds first ace in hand
			{
				highScore += 10;		// Adds 10 to the first ace encountered in hand, giving it a total value of 11
			}
		}
	}
	return highScore;
}


// Returns the score counting all the aces as 1.
int BlackJackHand::getLowScore()
{
	int lowScore = 0;
	for (int i = 0; i < cardCount; i++)
	{
		lowScore += handScore(cardsInHand[i]->getValue());		// Get sum of numerical values of cards in hand
	}
	return lowScore;
}


// This function clears the hand
void BlackJackHand::clearHand()
{
	for (int i = 0; i < cardCount; i++)
	{
		cardsInHand[i] = NULL;
		delete cardsInHand[i];		// Deletes every card in hand
	}
	cardCount = 0;					// Reinitialize private variable
}


// Returns true if the lowScore is above 21, false if not.
bool BlackJackHand::isBust()
{
	if (getLowScore() > BUST)		// If score of hand, counting all aces as 1, is > 21 (const int)
		return true;
	else
		return false;
}


// Returns true if the hand is full, i.e. the hand has 5 cards in it.
bool BlackJackHand::isFull()
{
	if (cardCount >= MAX_CARDS)		// If # of cards in hand >= 5 (const int)
		return true;
	else
		return false;
}


// Returns true if the hand can take another card.
// That means that the low score is less than 21 and the hand has less than 5 cards in it.
bool BlackJackHand::canTakeCard()
{
	if (cardCount < MAX_CARDS)		// If # of cards in hand is < 5 (const int)
	if (getLowScore() < BUST)	// If score of hand, counting all aces as 1, is < 21 (const int)
			return true;
		else
			return false;
	else
		return false;
}


// Displays the cards in the hand. Each card is displayed followed by a space.
std::string BlackJackHand::getAllCardCodes()
{
	std::string cardCodes = "";		// Initalize temp value
	for (int i = 0; i < cardCount; i++)
	{
		cardCodes += cardsInHand[i] -> getCardCode() + " ";		// Link card codes as string to temp value
	}
	return cardCodes;
}