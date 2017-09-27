/*
Dylan Secreast
10/31/13 - CS 161 C+
Lab 4 - Selection Problem #3 (Revised)
*/

#include <iostream>
using namespace std;

int main()
{
    double decNum = 0;
    double tempNum;
    int modulusResult;
    string hexNumber;




    {
        cout << "Enter a decimal (whole) number 0-15: ";
        cin >> decNum;



        tempNum = decNum;
        while (tempNum > 0.5)
        {
            modulusResult = static_cast<int>(tempNum) % 16;
            switch (modulusResult)
            {
                case 0:
                    hexNumber = "0" + hexNumber;
                    break;
                case 1:
                    hexNumber = "1" + hexNumber;
                    break;
                case 2:
                    hexNumber = "2" + hexNumber;
                    break;
                case 3:
                    hexNumber = "3" + hexNumber;
                    break;
                case 4:
                    hexNumber = "4" + hexNumber;
                    break;
                case 5:
                    hexNumber = "5" + hexNumber;
                    break;
                case 6:
                    hexNumber = "6" + hexNumber;
                    break;
                case 7:
                    hexNumber = "7" + hexNumber;
                    break;
                case 8:
                    hexNumber = "8" + hexNumber;
                    break;
                case 9:
                    hexNumber = "9" + hexNumber;
                    break;
                case 10:
                    hexNumber = "a" + hexNumber;
                    break;
                case 11:
                    hexNumber = "b" + hexNumber;
                    break;
                case 12:
                    hexNumber = "c" + hexNumber;
                    break;
                case 13:
                    hexNumber = "d" + hexNumber;
                    break;
                case 14:
                    hexNumber = "e" + hexNumber;
                    break;
                case 15:
                    hexNumber = "f" + hexNumber;
                    break;
            }
            tempNum /= 16;
        }
        cout << endl;
        cout << "The hexadecimal equivalent of " << decNum << " is: " << hexNumber << endl;

    }
    return 0;
}



