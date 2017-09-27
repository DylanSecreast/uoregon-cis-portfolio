/*
Dylan Secreast
2/14/14 (Revised 3/14/14)
CS 162 C+ Winter 2014
Lab 5 - PlayingCard Deck
PlayingCardDeck.h
*/


#ifndef PLAYINGCARDDECK_H_INCLUDED
#define PLAYINGCARDDECK_H_INCLUDED

#include "PlayingCard.h"
#include <string>


/*********************************
PlayingCardDeck Class Declaration:
*********************************/

class PlayingCardDeck
{
private:
	static const int DECK_SIZE = 52;
	static const int SUIT_SIZE = 13;
	static const int NUM_SUITS = 4;
	PlayingCard* deck[DECK_SIZE];			// Deck of cards implemented as array of pointers to PlayingCards
	void createDeck();
	void clearDeck();

public:
	PlayingCardDeck(){ createDeck(); }						// Default constructor
	PlayingCardDeck(int numShuffles);		// Overloaded constructor
	~PlayingCardDeck(){ clearDeck(); }		// Destructor

	int cardsUsed;					// # of cards used from deck
	
	PlayingCard* dealCard();
	bool shuffle(int numShuffles);
	void reset();
	std::string getAllCardCodes();
	int getCountUsed(){ return cardsUsed; }
	int getCountRemain(){ return (DECK_SIZE - cardsUsed); }
};

#endif // PLAYINGCARDDECK_H_INCLUDED