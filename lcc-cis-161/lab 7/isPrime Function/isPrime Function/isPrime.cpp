/*
Dylan Secreast
12/3/13 - CS 161 C+
isPrime Function (Revised) (#9, p.401)
*/

/*
Algorithm (pseudocode):

Display instructions
Get num
Send num to isPrimeFunction
	if num <= 1
		return false
	isPrime(For Version)
		for counter = 2; i <= num1 / 2; i++
			if (num % counter == 0)
				return false;
		return true;
	End for
If isPrimeFunction returns true
	Display "number is prime" message
Else
	Display "number is not prime" message
End
*/

#include <iostream>
using namespace std;


//Function prototype
bool isPrimeFunction(int num1);

//Main function
int main()
{
	
	
	int inputNum;
	char repeat = 'y';

	do
	{
		cout << "Enter a number to test if it's prime: ";
		cin >> inputNum;

		// Display prime or not with function call
		if (isPrimeFunction(inputNum))
		{
			cout << endl << inputNum << " is prime.\n\n";
		}
		else
		{
			cout << endl << inputNum << " is NOT prime.\n\n";
		}

		// Repeat program?
		cout << "Try again? (y/n): ";
		cin >> repeat;

		system("cls");
	}
	while (repeat == 'y' || repeat == 'Y');

	return 0;
}

//Prime Function - true = prime, false = not prime
bool isPrimeFunction(int num1)
{
	if (num1 < 2) return false;
	if (num1 == 2) return true;
	if (num1 % 2 == 0) return false;
	for (int i = 3; (i*i) <= num1; i += 2){
		if (num1 % i == 0) return false;
	}
	return true;
	}
