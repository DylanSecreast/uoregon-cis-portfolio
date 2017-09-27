/*
Dylan Secreast
3/9/14
CS 162 CS+ Winter 2014
Lab 6 - Blackjack Player and Dealer
Player.cpp
*/

#include "Player.h"



// Default constructor
Player::Player()
{
	theHand = new BlackJackHand;	// Creates a new hand
	stake = 0;		// Sets the stake to 0
}


bool Player::takeCard(PlayingCard *c)
{ 
	if (c != NULL)
	{
		theHand->addCard(c);
		return true;
	}
	else
		return false;
}


// Returns high score unless it is over 21, then it returns lowScore
int Player::getScore()
{
	if (theHand->getHighScore() <= 21)
		return theHand->getHighScore();
	else
		return theHand->getLowScore();
}


// Returns true if the player busted
bool Player::busted()
{
	if (theHand->isBust())
		return true;
	else
		return false;
}


// Returns true if the player wants a card (getScore < 16)
bool Player::wantCard()
{
	if (getScore() < 16)
		return true;
	else
		return false;
}


// Saves the bet if it is less than the stake and returns true, otherwise returns false and does nothing
bool Player::makeBet(int userBet)
{
	if (userBet < stake)
	{
		bet = userBet;
		return true;
	}
	else
		return false;
}