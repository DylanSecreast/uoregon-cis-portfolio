/*
Dylan Secreast
11/18/13 - CS 161 C+
Lab 6 - Repetition
*/

#include <iostream>

using namespace std;

int main()
{
int largestNumber;
int smallestNumber;
int number;
int integer;
int amountOfNumbers;
char again = 'n';

do
{
cout << "How many numbers would you like to enter?: ";
cin >> amountOfNumbers;
cout << "Please enter any " << amountOfNumbers << " random numbers: \n";
cin >> number;
largestNumber = number;
smallestNumber = number;

integer = 0;
while (integer <(amountOfNumbers - 1))
{
   cin >> number;
   integer++;
   if (number > largestNumber)
   {
     largestNumber = number;
   }
   if (number < smallestNumber)
   {
     smallestNumber = number;
   }
}
cout << endl;
cout << "The largest number entered is: " << largestNumber << endl;
cout << "The smallest number entered is: " << smallestNumber;
cout << endl << endl;

cout << "Do you want to try another set of numbers? (y/n) ";
cin >> again;
cout << endl;

} while (again == 'y');


return 0;
}
