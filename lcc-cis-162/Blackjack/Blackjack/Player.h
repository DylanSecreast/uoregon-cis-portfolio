/*
Dylan Secreast
3/9/14 (Revised 3/21/14)
CS 162 CS+ Winter 2014
Lab 6 - Blackjack Player and Dealer
Player.h
*/

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include "BlackJackHand.h"

// Player (parent) class. This is the class that you use to represent you in the Black Jack game.
// It holds your hand and your betting stake and provided methods to access both.
class Player
{
protected:
	int stake;
	int bet;
	BlackJackHand* theHand;

public:
	Player();		// DONE - creates a new hand and sets the stake to 0
	Player(int userStake){ stake = userStake; }	// DONE - takes one argument, uses that to set the stake
	~Player(){ theHand->deleteHand(); }			// DONE - deletes the hand when the game is over

	// Methods
	bool takeCard(PlayingCard *c);			// DONE - add a card to the player’s hand
	
	virtual std::string showHand() const { return theHand->getAllCardCodes(); }	// DONE - returns a string showing the contents of the hand
	
	int getLowScore(){ return theHand->getLowScore(); }				// DONE - returns the low score of the hand
	int getHighScore(){ return theHand->getLowScore(); }			// DONE - returns the high score of the hand
	int getScore();					// DONE - returns high score unless it is over 21, then it returns lowScore
	bool busted();					// DONE - returns true if the player busted
	bool wantCard();				// DONE - returns true if the player wants a card (getScore < 16)
	void clearHand(){ theHand->deleteHand(); }			// DONE - clears the cards from the hand for the next deal
	void setStake(int userStake){ stake = userStake; }	// DONE - sets the betting stake for the player
	int getStake(){ return stake; }	// DONE - returns the current value of the betting stake
	bool makeBet(int userBet);		// DONE - saves the bet if it is less than the stake and returns true, otherwise returns false and does nothing
	void won(){ stake += bet; }		// DONE - adds the bet to the stake
	void lost(){ stake -= bet; }	// DONE - subtracts the bet from the stake
};

#endif // PLAYER_H_INCLUDED