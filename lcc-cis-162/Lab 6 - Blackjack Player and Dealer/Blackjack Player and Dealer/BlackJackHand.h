/*
Dylan Secreast
2/7/14 (Revised 3/10/14)
CS 162 C+ Winter 2014
Lab 4 - Blackjack Hand
BlackJackHand.h
*/

#ifndef BLACKJACKHAND_H_INCLUDED
#define BLACKJACKHAND_H_INCLUDED

#include "PlayingCard.h"
#include <string>


/*******************************
BlackJackHand Class Declaration:
*******************************/

class BlackJackHand
{
public:
	static const int MAX_CARDS = 5;		// Maximum value of cards (5) allowed in hand at any one time

private:
	PlayingCard *cardsInHand[MAX_CARDS];	// Array of pointers to PlayingCard class
	int cardCount;					// Holds the current number of cards in hand
	static const int BUST = 21;		// In blackjack, a hand with a numerical sum of 21 or greater = bust
	int handScore(char cardRank);	// Calculates numerical sum of all current cards in hand

public:
	BlackJackHand();									// Default constructor. Initializes private member variables.
	BlackJackHand(PlayingCard *c1, PlayingCard *c2);	// Overloaded constructor. Initializes private member variables and adds c1 and c2 to the hand.
	~BlackJackHand(){ deleteHand(); }					// Deconstructor. Deletes any remaining cards.

	bool addCard(PlayingCard *card);		// For adding a card to the hand. It will print a warning, not add the card, and return false if one of these conditions is true: •	 The low score of the hand is 21, •	The hand is bust (low value > 21), •	The hand is full (the full number of cards has been added to the hand). If the card is successfully added, this function returns true.
	int getCardCount(){ return cardCount; }	// Returns the number of cards that are in the hand.
	int getHighScore();				// Blackjack allows an ace to count as either a 1 or an 11. This function returns the score of the hand counting the first ace in the hand as an 11. Make sure you don't count all the aces as 11.
	int getLowScore();				// Returns the score counting all the aces as 1.
	void deleteHand();				// This function clears the hand. Any cards in the hand are deleted. Deleted means that the delete operator is used on every card in the hand.
	bool isBust();					// Returns true if the lowScore is above 21, false if not.
	bool isFull();					// Returns true if the hand is full, i.e. the hand has 5 cards in it.
	bool canTakeCard();				// Returns true if the hand can take another card. That means that the low score is less than 21 and the hand has less than 5 cards in it.
	std::string getAllCardCodes();	// Displays the cards in the hand. Each card is displayed followed by a space.
};

#endif // BLACKJACKHAND_H_INCLUDED