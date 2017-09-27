#include <iostream>
#include <time.h>
#include "Player.h"
#include "Dealer.h"
#include "PlayingCard.h"


using namespace std;

int main() {
	
		// initialize random number generator
	srand( (unsigned int)time(NULL) );
		// Create a Blackjack hand object
	Dealer myHand(3);
	
		// arrays of values and suits for normal cards
	char
		*values = "A23456789TJQK",
		*suits = "CHDS";

	const int DECK_SIZE = 52;
	const int SUIT_SIZE = 13;
	PlayingCard *deck[DECK_SIZE]; // array of pointers to class objects

		// Initialize and display a card deck
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j<SUIT_SIZE; j++) {
			deck[i * SUIT_SIZE + j] = new PlayingCard(values[j], suits[i]);
			cout << deck[i * SUIT_SIZE + j]->getCardCode();
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	
		// Add each from deck to hand, then remove card from hand
		// before adding next card. Check funcs.
	for(int i = 0; i < DECK_SIZE; i++) {
		cout << deck[i]->getCardCode();
		myHand.takeCard(deck[i]);

		deck[i] = NULL;  // Remove card from deck
		cout << " : ";
		cout << myHand.showHand();
		cout << " : " << myHand.getLowScore()
			 << " : " << myHand.getHighScore()
			 << " : " << myHand.busted()
			 << endl;
		if(!myHand.wantCard()) {
			cout << "\nClearing hand\n";
			myHand.clearHand();
		}

	} // end for
	
		// check dealing capability
	cout << "dealer dealing 32 cards" << endl;
	int cardsOnLine = 0;
	while ( myHand.cardsLeft() > 20 )
	{
		cout << myHand.dealCard()->getCardCode() << " ";
		cardsOnLine++;
		if ( cardsOnLine > 12 )
		{
			cout << endl;
			cardsOnLine = 0;
		}
	}

		// reset and redeal
	cout << " second deck" << endl;
	myHand.shuffle();
	cout << "dealer dealing 10 cards" << endl;
	while ( myHand.cardsLeft() > 42 )
	{
		cout << myHand.dealCard()->getCardCode() << " ";
		cardsOnLine++;
		if ( cardsOnLine > 12 )
		{
			cout << endl;
			cardsOnLine = 0;
		}
	}
	
	return 0;
}

