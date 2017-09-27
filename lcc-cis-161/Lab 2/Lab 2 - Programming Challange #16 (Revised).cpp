/*
Dylan Secreast
10/21/13 - CS 161 C+
Lab 2 - Programming Challenge #16 (Page 152)
*/

#include <iostream> // Header file for input/output
#include <iomanip>  // Header file for setw
#include <cstdlib>  // Header file for srand and rand
#include <ctime>    // Header file for setting seed

using namespace std;

int main()
{
    int randNumOne,
        randNumTwo,
        usersAnswer;

    // Display instructions
    cout << "Solve and enter answer:" << endl;
    cout << endl;

    // Sets seed
    srand (time(NULL));

    // Declare & assign random numbers
    randNumOne = rand() % 9 + 1;
    randNumTwo = rand() % 9 + 1;

    // Display problem
    cout << setw(4) << randNumOne << endl;
    cout << "+" << setw(3) << randNumTwo << endl;    // setw(3) instead of setw(4) accounts for the character space of "+"
    cout << "-----" << endl;

    // Input answer
    cout << "   ";
    cin >> usersAnswer;

    // Check answer
    if (usersAnswer == (randNumOne + randNumTwo))
        {
            cout << endl;
            cout << "Correct! - Well done!" << endl;
        }
    else
        {
            cout << endl;
            cout << "Incorrect." << endl;
            cout << "The answer is: " << (randNumOne + randNumTwo) << endl;
        }

    return 0;
}
