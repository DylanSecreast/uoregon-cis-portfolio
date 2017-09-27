/*
Dylan Secreast
10/31/13 - CS 161 C+
Lab 4 - Selection Problem #3
*/

#include <iostream>
using namespace std;

int main()
{
    int decNumber;

    // Get decimal #
    cout << "Enter a decimal (whole) number between 0 and 15: ";
    cin >> decNumber;

    // Protect against numbers that are not within 0-15
    if (decNumber > 15 or decNumber < 0)
    {
        cout << endl << "****** INVALID NUMBER ******\n";
        return 0;
    }

    // Decimal to hexadecimal
    cout << endl << decNumber << " has a hexadecimal value of: " << hex << decNumber << endl;



    return 0;
}
