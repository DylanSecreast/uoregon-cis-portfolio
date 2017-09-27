#include <iostream>
#include "Player.h"
#include "Dealer.h"
#include "PlayingCard.h"

using namespace std;

int main() {

  // Create a Blackjack hand object
  Player myHand;

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

  myHand.setStake(100);
  cout << "my stake is " << myHand.getStake() << endl;
  if ( myHand.makeBet(200) )
  {
	cout << " error in checking bet limit\n";
  }
  else
  {
  	cout << "invalid bet detected\n";
  }
  if (myHand.makeBet(50) )
  {
  	cout << " good bet for 50 \n";
  }
  else
  {
    cout << "proper bet rejected in error\n";
  }

  myHand.won();
  cout << "after winning stake is " << myHand.getStake() << "should be 150"<< endl;
  myHand.makeBet(20);
  myHand.lost();
  cout << "after losing stake is " << myHand.getStake() << "should be 130"<< endl;
  
  return 0;
}

