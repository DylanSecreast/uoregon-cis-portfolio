/*
Dylan Secreast
1/13/14 (Revised 3/14/14)
CS 162 C+ Winter 2014
Lab 1 - Triangle Class
*/

#include "Triangle.h"

// Equilateral triangle = All side lengths equal
bool Triangle::isEquilateral()		
{
	if (sideA == sideB && sideB == sideC)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Scalene triangle = All side lengths different
bool Triangle::isScalene()		
{
	if (sideA != sideB && sideB != sideC && sideA != sideC)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Isosceles triangle = Two side lengths equal
bool Triangle::isIsosceles()		
{
	if (sideA == sideB || sideB == sideC || sideA == sideC)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Right triangle = Tested with pythagorean theorm (a^2 + b^2 = c^2)
bool Triangle::isRight()		
{
	if ((sideC * sideC) + (sideB * sideB) == (sideA * sideA))
		return true;
	else if ((sideA * sideA) + (sideC * sideC) == (sideB * sideB))
		return true;
	else if ((sideA * sideA) + (sideB * sideB) == (sideC * sideC))
		return true;
	else
		return false;
}