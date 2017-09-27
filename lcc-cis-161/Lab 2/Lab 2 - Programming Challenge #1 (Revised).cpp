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
    cout << "Input how many gallons your vehicle's fuel tank can hold: ";
    cin >> gallonsOfGas;

    // Input # of miles on full tank
    cout << "Input how many miles your vehicle can drive on a full tank: ";
    cin >> milesOnFullTank;

    // Calcuate & display MPG
    milesPerGallon = milesOnFullTank / gallonsOfGas;
    cout << endl;
    cout << "Your vehicle gets " << fixed << setprecision(2) << milesPerGallon << " miles per gallon.";

    return 0;
}
