/*
Dylan Secreast
10/21/13 - CS 161 C+
Lab 2 - Programming Challenge #1 (Page 149)
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float gallonsOfGas,
          milesOnFullTank,
          milesPerGallon;

    // Input gallons of gas
    cout << "Input how many gallons your vehical's fuel tank can hold: ";
    cin >> gallonsOfGas;

    // Input # of miles on full tank
    cout << "Input how many miles your vehical can drive on a full tank: ";
    cin >> milesOnFullTank;

    // Calcuate & display MPG
    milesPerGallon = milesOnFullTank / gallonsOfGas;
    cout << endl;
    cout << "Your vehical gets " << fixed << milesPerGallon << setprecision(2) << " miles per gallon.";

    return 0;
}
