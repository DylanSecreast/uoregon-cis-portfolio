/*
Dylan Secreast
11/25/13 - CS 161 C+
Celsius Temperature Table (#2, p.399)
*/

/*
Algorithm (pseudocode):

fahrenheitTemp(For Version)
	For counter = 0 to 20
		Display counter (as fahrenheit value)
		Send counter value to celsius function to calculate each conversion
		Display celsius equivalent from function
	End For
End
*/

#include <iostream>
#include <iomanip>
using namespace std;


//Function prototype
double celsiusFunction(double fahrenheit);

//Main function
int main()
{
	//Sets numeric output formatting
	cout << fixed << setprecision(2);

	double fahrenheitTemp;  //Holds the returned temp
	int f;  //For displaying fahrenheit temps 0-20 in loop

	//Table header
	cout << "Fahrenheit Temp:" << setw(30) << "Celsius Equivalent:\n";

	//Loop to display fahrenheit 0-20 and celsius equivalents
	for (f = 0; f <= 20; f++)
	{
		fahrenheitTemp = celsiusFunction(f);
		cout << f << setw(30) << fahrenheitTemp << endl;
	}

	return 0;
}

//Celsius function: accepts fahrenheit temp as an argument, returns temp converted to celsius
double celsiusFunction(double fahrenheit)
{
	return ((5.0 / 9.0)*(fahrenheit - 32));
}
