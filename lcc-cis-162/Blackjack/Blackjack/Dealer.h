/*
Dylan Secreast
3/9/14 (Revised 3/21/14)
CS 162 CS+ Winter 2014
Lab 6 - Blackjack Player and Dealer
Dealer.h
*/

#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED

#include "Player.h"
#include "PlayingCardDeck.h"

// Dealer class inherits from player class. Adds the ability to deal cards and manage the deck.
// Does not use the methods for managing bets or stake.
class Dealer : public Player
{
protected:
	PlayingCardDeck* theDeck;

public:
	Dealer(){ theDeck = new PlayingCardDeck; }	// creates a PlayingCardDeck
	Dealer(int numShuffles){ theDeck = new PlayingCardDeck(numShuffles); }		// takes one argument, uses that to create a PlayingCardDeck and shuffle it
	~Dealer(){ theDeck->deleteDeck(); }	// deletes the deck when the game is over

	virtual std::string showHand();		// this is different from the Player showHand in that the first card is shown as XX to indicate that it is face down.
	
	std::string fullHand(){ return theHand->getAllCardCodes(); }		// this is used to show the dealer’s full hand after the player is done taking cards.
	PlayingCard* dealCard(){ return theDeck->dealCard(); }	// return the next card from the deck
	int cardsLeft(){ return theDeck->getCountRemain(); }	// return how many cards are left in the deck
	void shuffle(){ theDeck->reset(); theDeck->shuffle(0); }		// this resets and shuffles the deck to start play over again

};




#endif // DEALER_H_INCLUDED