/*
Dylan Secreast
11/26/13 - CS 161 C+
Stock Profit (#11, p. 402)
*/

/*
Algorithm (pseudocode):

Get numberOfShares
Get salePrice
Get saleCommission
Get purchasePrice
Get purchaseCommission
Send all input values to stockProfitFunction
	return ((NS * SP) - SC) - ((NS * PP) + PC)
If function return >= 0
	Display profit of function return value
Else
	Display loss of function return value
End
*/


#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double stockProfitFunction(double NS, double PP, double PC, double SP, double SC);


// Main Function
int main()
{
	// Format output
	cout << fixed << setprecision(2);

	// Initialize variables
	double profit,
		numberOfShares,
		salePrice,
		saleCommission,
		purchasePrice,
		purchaseComission;

	// Get information from user
	cout << "Stock Profit Calculator\n-----------------------\n\n";
	cout << "Enter number of shares: ";
	cin >> numberOfShares;
	cout << "Enter sale price: ";
	cin >> salePrice;
	cout << "Enter sales commission: ";
	cin >> saleCommission;
	cout << "Enter purchase price: ";
	cin >> purchasePrice;
	cout << "Enter purchase commission: ";
	cin >> purchaseComission;

	//Calcualtes profit with function
	profit = stockProfitFunction(numberOfShares, purchasePrice, purchaseComission, salePrice, saleCommission);
	
	// Display "profit" or "loss" depending on positive or negative value returned by function
	if (profit >= 0)
	{
		cout << "\n-----------------------\n";
		cout << "You earned a profit of: $" << profit << endl;
	}
	else
	{
		cout << "\n-----------------------\n";
		cout << "You had a loss of: $" << profit << endl;
	}

	return 0;
}

// Stock Profit Function, returns profit
double stockProfitFunction(double NS, double PP, double PC, double SP, double SC)
{
	return ((NS * SP) - SC) - ((NS * PP) + PC);
}