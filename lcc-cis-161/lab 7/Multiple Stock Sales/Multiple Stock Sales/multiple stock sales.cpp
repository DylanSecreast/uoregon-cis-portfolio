/*
Dylan Secreast
11/26/13 - CS 161 C+
Multiple Stock Sales (#12, p. 402)
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
		totalProfit = 0,
		numberOfShares,
		salePrice,
		saleCommission,
		purchasePrice,
		purchaseComission;
	int numberOfSales;

	// Get # of sales from user
	cout << "Multiple Stock Profit Calculator\n--------------------------------\n\n";
	cout << "How many sales do you wish to enter?: ";
	cin >> numberOfSales;
	cout << endl;

	// Perform function in loop for number of sales
	for (int i = 1; i <= numberOfSales; i++)
	{
		system("cls");
		cout << "Multiple Stock Profit Calculator\n";
		cout << "(Currently entering stock sale #" << i << ")\n----------------------------------\n";

		// Get information from user
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
		totalProfit += profit;

		// Display "profit" or "loss" depending on positive or negative value returned by function
		if (profit >= 0)
		{
			cout << "\n-----------------------\n";
			cout << "Sale " << i << " earned a profit of: $" << profit << endl;
			cout << "(Press enter to input next sale)";
			cin.get();
			cin.get();
		}
		else
		{
			cout << "\n-----------------------\n";
			cout << "Sale " << i << " had a loss of: $" << profit << endl;
			cout << "(Press enter to input next sale)";
			cin.get();
			cin.get();
		}
	}

	// Display total profit/loss from all function calls depending on positive or negative value returned by totalProfit
	system("cls");
	cout << "Multiple Stock Profit Calculator\n--------------------------------\n\n";
	if (totalProfit >= 0)
	{
		cout << "Total profit of the " << numberOfSales << " sales entered is: $" << totalProfit << endl;
	}
	else
	{
		cout << "Total loss of the " << numberOfSales << " sales entered is: $" << totalProfit << endl;
	}


	return 0;
}


// Stock Profit Function, returns profit
double stockProfitFunction(double NS, double PP, double PC, double SP, double SC)
{
	return ((NS * SP) - SC) - ((NS * PP) + PC);
}