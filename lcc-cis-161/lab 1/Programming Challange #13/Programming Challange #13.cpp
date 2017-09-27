/*
Dylan Secreast
10/4/13 - CS 161 C+
Programming Challange #13 (Page 75)
*/

#include <iostream>
using namespace std;

int main()
{
    double salary = 32500,
            twiceMonthly,
            biWeekly;

    // Calculate twice montly salary
    twiceMonthly = salary / 24;

    // Calculate bi-weekly salary
    biWeekly = salary / 26;

    // Display calculations
    cout << "With a yearly salary of $" << salary << ":\n";
    cout << "Gross pay is $" << twiceMonthly << " if paid twice a month.\n";
    cout << "Gross pay is $" << biWeekly << " if paid bi-weekly.\n";

    return 0;
}
