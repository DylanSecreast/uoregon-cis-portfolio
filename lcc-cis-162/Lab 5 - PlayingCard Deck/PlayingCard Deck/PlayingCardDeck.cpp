/*
Dylan Secreast
2/14/14 (Revised 3/14/14)
CS 162 C+ Winter 2014
Lab 5 - PlayingCard Deck
PlayingCardDeck.cpp
*/


#include "PlayingCard.h"
#include "PlayingCardDeck.h"
#include <iostream>
#include <ctime>



using namespace std;


/*********************************
PlayingCardDeck Class Definitions:
*********************************/


// Overloaded constructor. Shuffles the deck numShuffles times.
PlayingCardDeck::PlayingCardDeck(int numShuffles)
{
	createDeck();
	shuffle(numShuffles);
}


// Initializes card counters & creates new deck of 52 unshuffled cards
void PlayingCardDeck::createDeck()
{
	// Initialize card counters
	cardsUsed = 0;

	// Arrays of values and suits for normal cards
	char
		*values = "A23456789TJQK",
		*suits = "DCHS";

	// Creates unshuffled deck of 52 cards, implemented as pointers to PlayingCards.
	for (int i = 0; i < NUM_SUITS; i++)
		for (int j = 0; j < SUIT_SIZE; j++)
			deck[i * SUIT_SIZE + j] = new PlayingCard(values[j], suits[i]);
}


// Frees dynamically allocated memory
void PlayingCardDeck::clearDeck()
{
	for (int i = 0; i < DECK_SIZE; i++)
		if (deck[i] != NULL)
			delete deck[i];
}

// Returns a pointer to a PlayingCard object taken from "the top" of the deck.
// If there are no more cards in the deck, it returns a null pointer and displays a warning.
PlayingCard* PlayingCardDeck::dealCard()
{
	PlayingCard* cardOffTop;
	
	if ((DECK_SIZE - cardsUsed) > 0)
		{
			cardOffTop = deck[cardsUsed];
			deck[cardsUsed] = NULL;
			cardsUsed++;
			return cardOffTop;
		}
		else
			return cardOffTop = NULL;
}


// Shuffles cards numShuffles times, only if no cards have been dealt from the deck.
// If one or more cards have been dealt, then the function returns false and no shuffling will be done.
bool PlayingCardDeck::shuffle(int numShuffles)
{
	int i = 0;
	if (cardsUsed == 0)
	{
		while (i <= numShuffles)
		{
			int j;
			PlayingCard* temp;
			srand(time(NULL));

			for (int i = DECK_SIZE - 1; i > 0; i--)
			{
				j = rand() % DECK_SIZE;
				temp = deck[i];
				deck[i] = deck[j];
				deck[j] = temp;
			}
			i++;
		}
		return true;

	}
	else if (cardsUsed > 0)
		return false;
}


// Resets the deck to a full deck of 52 unshuffled cards.
void PlayingCardDeck::reset()
{
	clearDeck();
	createDeck();
}


// Returns a string containing all the value and suit codes for the deck.
// If there have been cards dealt from the deck, those cards will not be displayed.
string PlayingCardDeck::getAllCardCodes()
{
	string allCodes = "";

	for (int i = 0; i < 13; i++)
		if (deck[i] != NULL)
			allCodes += deck[i]->getCardCode() + " ";

	allCodes += "\n";

	for (int i = 13; i < 26; i++)
		if (deck[i] != NULL)
			allCodes += deck[i]->getCardCode() + " ";
	
	allCodes += "\n";

	for (int i = 26; i < 39; i++)
	if (deck[i] != NULL)
		allCodes += deck[i]->getCardCode() + " ";

	allCodes += "\n";

	for (int i = 39; i < 52; i++)
		if (deck[i] != NULL)
			allCodes += deck[i]->getCardCode() + " ";
	
	allCodes += "\n";

	return allCodes;
}

