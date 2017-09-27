/*
Dylan Secreast
3/9/14 (Revised 3/21/14)
CS 162 CS+ Winter 2014
Lab 6 - Blackjack Player and Dealer
Dealer.cpp
*/

#include "Dealer.h"


// this is used to show the dealer’s full hand after the player is done taking cards.
std::string Dealer::showHand()
{
	std::string dealerHand = "";
	dealerHand = theHand->getAllCardCodes();
	dealerHand.replace(0, 2, "XX");
	return dealerHand;
}
