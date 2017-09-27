/*
Dylan Secreast
10/31/13 - CS 161 C+
Selection Problem #5
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string userGender;
    int userAge;
    float baseRate;
    float totalRate;

    // Get information from user
    cout << "Enter user gender (male/female): ";
    cin >> userGender;
    cout << "Enter user age: ";
    cin >> userAge;
    cout << "Enter base rate for car insurance: $";
    cin >> baseRate;

    // Calculate insurance rate with nested selection
    if (userGender == "male")
    {
        if (userAge > 25)
        {
            totalRate = (baseRate + (baseRate * 0.07));
            cout << endl << "Total insurance rate is: $" << fixed << setprecision(2) << totalRate;
        }
        else
        {
            totalRate = (baseRate + (baseRate * 0.10));
            cout << endl << "Total insurance rate is: $" << fixed << setprecision(2) << totalRate;
        }
    }

    else if (userGender == "female")
    {
        if (userAge > 25)
        {
            totalRate = baseRate;
            cout << endl << "Total insurance rate is: $" << fixed << setprecision(2) << totalRate;
        }
        else
        {
            totalRate = (baseRate + (baseRate * 0.05));
            cout << endl << "Total insurance rate is: $" << fixed << setprecision(2) << totalRate;
        }
    }


    return 0;
}
