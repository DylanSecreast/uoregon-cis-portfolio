/************************************************************
** Tim Sheehan - Test Driver for BlackJackHand class
**
** File: BlackJackHandDriver.cpp
** Author: Tim Sheehan
** Created: 2009.01.18
**
** Program runs through a deck of cards testing the
** BlackJackHand class
**
** Update History
**
** 2009.01.18 - tjs
**  Creating initial driver
** 2009.01.28
**  Added test for 2 aces
** 2010.02.01
**  Changed display() to getAllCardCodes() - Brian Bird
** 2013.02.02
**  Changed the cleanup code at the end to delete the cards in
**  deck rather than deleting deck, which was incorrect.
**  Added named constants for DECK_SIZE and SUIT_SIZE
************************************************************/
#include <iostream>
#include "BlackJackHand.h"
#include "PlayingCard.h"

using namespace std;

int main() {

  // Create a Blackjack hand object
  BlackJackHand myHand;

  // arrays of values and suits for normal cards
  char
    *values = "A23456789TJQK",
    *suits = "CHDS";

  const int DECK_SIZE = 52;
  const int SUIT_SIZE = 13;
  PlayingCard *deck[DECK_SIZE]; // array of pointers to class objects

  // Initialize and display a card deck
  int
    i,
    j;

  for(i = 0; i < 4; i++) {
    for(j = 0; j<SUIT_SIZE; j++) {
      deck[i * SUIT_SIZE + j] = new PlayingCard(values[j], suits[i]);
      cout << deck[i * SUIT_SIZE + j]->getCardCode();
      cout << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  // Add each from deck to hand, then remove card from hand
  // before adding next card. Check funcs.
  for(i = 0; i < DECK_SIZE; i++) {
    cout << deck[i]->getCardCode();
    myHand.addCard(deck[i]);
    deck[i] = NULL;  // Remove card from deck
    cout << " : ";
    cout << myHand.getAllCardCodes();
    cout << " : " << myHand.getLowScore()
      << " : " << myHand.getHighScore()
      << " : " << myHand.isBust()
      << " : " << myHand.isFull()
      << " : " << myHand.getCardCount()
      << " : " << myHand.canTakeCard()
      << endl;
    if(!myHand.canTakeCard()) {
        cout << "\nClearing hand\n";
        myHand.clearHand();
    }
  } // end for
  
  cout << "\nClearing hand\n";
  myHand.clearHand();

  PlayingCard
    *card1 = new PlayingCard('J', 'C'),
    *card2 = new PlayingCard('A', 'S'),
    *card3 = new PlayingCard('A', 'D');


  BlackJackHand hand2 = BlackJackHand(card1,card2);
  card1 = card2 = 0;
  cout << hand2.getAllCardCodes();
  cout << " : " << hand2.getLowScore()
    << " : " << hand2.getHighScore()
    << " : " << hand2.isBust()
    << " : " << hand2.isFull()
    << " : " << hand2.getCardCount()
    << " : " << hand2.canTakeCard()
    << endl;

  cout << "\nAdding a second ace:\n";

  hand2.addCard(card3);
  card3 = 0;
  cout <<hand2.getAllCardCodes();
  cout << " : " << hand2.getLowScore()
    << " : " << hand2.getHighScore()
    << " : " << hand2.isBust()
    << " : " << hand2.isFull()
    << " : " << hand2.getCardCount()
    << " : " << hand2.canTakeCard()
    << endl;

    for (int i = 0; i < DECK_SIZE; i++)
        if (deck[i] != NULL)
            delete deck[i];
	
  return 0;
} // end main
