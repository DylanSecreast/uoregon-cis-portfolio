/*
Dylan Secreast
11/18/13 - CS 161 C+
Lab 6 - Nim Game
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	const int total = 11;
	int n, mtotal;

	mtotal = total;

// Display instructions
cout << "Welcome to Nim! (By: Dylan Secreast)\n";
cout << "Players will take turns removing 1, 2, or 3 sticks from the initial 11.\n";
cout << "First player to 0 sticks wins!\n";
cout << "--------------------------------------------------------------------------------\n";

while (mtotal > 0)
{
    // Player 1's moves
    if(mtotal > 0)
        cout << "The game currently looks like this:\n";
        cout << string (mtotal, '|') << endl;
        cout << "There are " << mtotal << " sticks.\n"<< endl;
        cout << "Player 1, how many sticks would you like to remove? (1, 2, or 3): ";
        cin >> n;
    if ( n >=1 && n <=3)
    {
        cout << "You have removed " << n << " stick(s).\n" << endl;
        mtotal -= n;
    }
    else
    {
        cout << endl << "*** Invalid play, Player 2's turn ***\n" << endl;
    }
    if ((mtotal - n)<0)                                     // Guards against
    {                                                                   // bad input data
        //if (n < 1 || n >2)                                              // when there are
        //{                                                               // less than
            cout << "*** Invalid play, Player 2's turn ***\n" << endl;  // 3 markers left
        //}
    }
    if (mtotal == 0)
    {
        cout << "**************\n";
        cout << "Player 1 wins!\n";
        cout << "**************\n";
        return 0;
    }

    // Player 2's moves
    if(mtotal > 0)
        cout << "The game currently looks like this:\n";
        cout << string (mtotal, '|') << endl;
        cout << "There are " << mtotal << " sticks.\n" << endl;
        cout << "Player 2, how many sticks would you like to remove? (1, 2, or 3): ";
        cin >> n;
    if ( n >=1 && n <=3)
    {
        cout << "You have removed " << n << " stick(s).\n" << endl;
        mtotal -= n;
    }
    else
    {
        cout << endl << "*** Invalid play, Player 1's turn ***\n" << endl;
    }
    if (mtotal == 0)
    {
        cout << "**************\n";
        cout << "Player 2 wins!\n";
        cout << "**************\n";
        return 0;
    }
}

return 0;
}
