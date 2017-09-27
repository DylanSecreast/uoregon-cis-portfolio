/*
Dylan Secreast
10/13/13 - CS 161 C+
Lab 4 - Selection Problem #4
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float salesPrice,
          commissionEarned;

    // Get information from user
    cout << "Enter sales price: $";
    cin >> salesPrice;

    // Calculate commission by selection
    if (salesPrice >= 300000)
    {
        commissionEarned = (25000 + ((salesPrice - 300000)*0.15));
        cout << endl << "Commission Earned: $" << fixed << setprecision(2) << commissionEarned;
    }
    else if (salesPrice >= 100000 && salesPrice < 300000)
    {
        commissionEarned = (5000 + ((salesPrice - 100000)*0.10));
        cout << endl << "Commission Earned: $" << fixed << setprecision(2) << commissionEarned;
    }
    else if (salesPrice < 100000)
    {
        commissionEarned = (salesPrice * 0.05);
        cout << endl << "Commission Earned: $" << fixed << setprecision(2) << commissionEarned;
    }



    return 0;
}
