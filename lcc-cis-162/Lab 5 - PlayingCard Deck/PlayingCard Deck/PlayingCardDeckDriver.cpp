/************************************************************
** Unknown author - Test Driver for PlayingCardDeck class
**
** File: PlayingCardDeckDriver.cpp
** Author: Unknown
** Created: Unknown
**
** Test driver for the PlayingCardDeck class
**
** Update History
**
** 2/8/10 - Brian Bird
**  Modified for functions that return bool status

************************************************************/

#include <iostream>
#include "PlayingCardDeck.h"
// #include "../../lab1/PlayingCard/PlayingCard.h"
#include "PlayingCard.h"

using namespace std;

int main(){
	int
		checkDeck[4][13] = {},
		checkNdx = 0,
		suitNdx = 0,
		valueNdx = 0,
		i,
		j;

	PlayingCardDeck
		deck,
		*deckPtr;

	PlayingCard
		*myCard;

	bool
		found = false;

	char
		values[] = "A23456789TJQK",
		suits[] = "DCHS";

	cout << "Original Deck:\n";
	cout << deck.getAllCardCodes();

	
	cout << "\n\nDealing some cards:\n";
	for (i = 0; i<22; i++) {
		myCard = deck.dealCard();
		if (myCard != NULL)
		{
			cout << myCard->getCardCode();
			cout << " ";
			if (!((i + 1) % 13))
				cout << endl;
			delete myCard;
		}
		myCard = 0;
	}
	
	cout << "\n\nRest of deck" << endl;
	cout << deck.getAllCardCodes();
	
	cout << "\nShould get shuffle error, 22 cards used, 30 cards remaining:\n\n";
	deck.shuffle(1);
	cout << "Used: " << deck.getCountUsed() << " Remaining: " << deck.getCountRemain() << endl << endl;

	deck.reset();
	
	cout << "\nTesting overloaded constructor. Should get shuffled deck:\n\n";

	deckPtr = new PlayingCardDeck(20);
	cout << deckPtr->getAllCardCodes();
	delete deckPtr;
	
	cout << "\nReset deck:\n\n";
	cout << deck.getAllCardCodes();

	cout << "\nTesting empty deck:\n";
	for (i = 0; i<52; i++) {
		myCard = deck.dealCard();
		if (myCard != NULL)
			delete myCard;
		myCard = 0;
	}
	cout << "\nShould get 2 deal errors, 1 empty display msg, \n";
	cout << "52 cards used, 0 cards remaining\n";
	cout << "myCard is null\n\n";

	myCard = deck.dealCard();
	myCard = deck.dealCard();
	cout << deck.getAllCardCodes();
	cout << "Used: " << deck.getCountUsed() << " Remaining: " << deck.getCountRemain() << endl;
	if (!myCard)
		cout << "myCard is null\n";
	else
		cout << "ERROR myCard is not null\n";
	
	deck.reset();
	
	cout << "\nShuffle test. Should see unshuffled, shuffled, Array of 52 1's:\n\n";

	cout << deck.getAllCardCodes();
	deck.shuffle(50);
	cout << endl << endl;
	cout << deck.getAllCardCodes();
	cout << endl << endl;

	for (i = 0; i<52; i++) {
		suitNdx = 0;
		found = false;
		myCard = deck.dealCard();
		while (suitNdx < 4 && !found && myCard != NULL) {
			valueNdx = 0;
			while (valueNdx < 13 && !found) {
				if (myCard->getSuit() == suits[suitNdx] &&
					myCard->getValue() == values[valueNdx]){
					checkDeck[suitNdx][valueNdx]++;
					found = true;
				} // if
				valueNdx++;
			} // while
			suitNdx++;
		} // while
		delete myCard;
	} // for

	for (i = 0; i<4; i++) {
		for (j = 0; j<13; j++) {
			cout << checkDeck[i][j] << "  ";
		}
		cout << endl;
	}
	
	cout << endl;
	
	cout << "reset() memory leak test. This may take a while\n";
	for (i = 0; i<1000000; i++) {
		deck.reset();
		if (!((i + 1) % 2000))
			cout << ".";
		if (!((i + 1) % 100000))
			cout << endl;
	}

	cout << "Passed\n\n";

	cout << "destructor memory leak test. This may take a while\n";
	for (i = 0; i<1000000; i++) {
		deckPtr = new PlayingCardDeck;
		delete deckPtr;
		if (!((i + 1) % 2000))
			cout << ".";
		if (!((i + 1) % 100000))
			cout << endl;
	}

	cout << "Passed\n\n";
	
	cout << "Testing Complete!\n";
	
	
	return 0;
} // int main()