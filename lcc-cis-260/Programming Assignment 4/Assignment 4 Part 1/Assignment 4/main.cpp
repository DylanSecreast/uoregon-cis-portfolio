#include "Power.h"
#include <iostream>
using namespace std;

int main(){
	Power x;
	int base, exponent;

	cout << "Raising a number to a exponent\n";
	cout << "via recursion using powers of two:\n";
	cout << "**********************************\n\n";
	cout << "Enter Base Number: ";
	cin >> base;
	cout << "Enter Exponent: ";
	cin >> exponent;
	cout << endl << base << "^" << exponent << " = " << x.raisingTo(base, exponent) << endl;

	return 0;
}