#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Player.h"
#include "Dealer.h"

using namespace std;

int getStake();
int getBet();
void showTable(Dealer & dealer, Player & player);
void showFullTable(Dealer & dealer, Player & player);
bool getResponse(string question);



int main() {

	const int MINDECK = 45;
	int bet;
	bool hit;

		// initialize random number generator
	srand( static_cast<unsigned int>( time(NULL) ) );

		// create player and dealer
		// start with shuffled deck
	Dealer dealer(3);
	Player player;

	player.setStake(getStake());

	bool donePlaying = false;
	do {
			// make sure deck is good
			if ( dealer.cardsLeft() < MINDECK )
			{
				cout << endl << "Reshuffling deck\n";
				dealer.shuffle();
			}

				// get bet
			do {
				bet = getBet();
			} while ( bet > player.getStake() );
			player.makeBet(bet);

				// deal starting cards;
			player.takeCard(dealer.dealCard());
			dealer.takeCard(dealer.dealCard());
			player.takeCard(dealer.dealCard());
			dealer.takeCard(dealer.dealCard());

				// show starting position
			showTable(dealer, player);

				// get player hits
			do{
				 hit = getResponse("Do you want a hit(y/n)?");
				 if ( hit )
				 {
				 	player.takeCard(dealer.dealCard());
				 	showTable(dealer, player);
				 }
			} while ( hit );

				// now show dealer down card
			showFullTable(dealer, player);

				// now get dealer careds if nneded
			if ( !player.busted() )
			{
				while ( dealer.wantCard() )
				{
					cout << endl << "Dealer takes a card" << endl;
					dealer.takeCard(dealer.dealCard());
					showFullTable(dealer, player);
				}
			}

				// decide who won
			if ( player.busted() )
			{
				cout << "You busted, you lost" << endl;
				player.lost();
			}
			else if ( dealer.busted() )
			{
				cout << "Dealer busted, you won" << endl;
				player.won();
			}
			else if ( player.getScore() > dealer.getScore() )
			{
				cout << "You beat the dealers hand" << endl;
				player.won();
			}
			else if ( player.getScore() < dealer.getScore() )
			{
				cout << "Dealers hand beat yours" << endl;
				player.lost();
			}
			else
			{
				cout << "Push, neither won" << endl;
			}

			cout << "Your stake is now " << player.getStake() << endl;
			player.clearHand();
			dealer.clearHand();

			// see if done
		donePlaying = getResponse("Are you done playing (y/n)?");
	} while ( !donePlaying );


	return 0;
}

void showTable(Dealer & dealer, Player & player){
	cout << endl << "The current table is " << endl;
	cout << "  dealer: ";
	cout << dealer.showHand() << endl;
	cout << "  player: ";
	cout << player.showHand() << endl;

}

void showFullTable(Dealer & dealer, Player & player){
	cout << endl << "The full table is " << endl;
	cout << "  dealer: ";
	cout << dealer.fullHand() << endl;
	cout << "  player: ";
	cout << player.showHand() << endl;

}

int getBet(){
	int bet;
	do {
		cout << "Enter your bet (must bet between 1 and your stake): ";
		cin >> bet;
	} while ( bet <= 0);
	return bet;
}

int getStake(){
	int stake;
	do {
		cout << "Enter your starting positive int gambling stake: ";
		cin >> stake;
	} while ( stake <= 0);
	return stake;
}

bool getResponse(string question){
	char response;
	bool done = false;
	bool invalidResponse = true;
	do {
		cout << question << " ";
		cin >> response;
		switch (response){
			case 'y':
			case 'Y':
				done = true;
				invalidResponse = false;
				break;
			case 'n':
			case 'N':
				done = false;
				invalidResponse = false;
				break;
			default:
				invalidResponse = true;
		}
	} while ( invalidResponse );
	return done;
}
