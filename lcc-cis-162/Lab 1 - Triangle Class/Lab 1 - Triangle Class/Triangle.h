/*
Dylan Secreast
1/13/14
CS 162 C+ Winter 2014
Lab 1 - Triangle Class
*/

#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

// Triangle class declaration
class Triangle
{
private:
	int sideA, sideB, sideC;

public:
	// Default constructor values
	Triangle() { sideA = 3, sideB = 4, sideC = 5; }	
	// Overloaded constructor
	Triangle(int a, int b, int c){ sideA = a, sideB = b, sideC = c; }		

	// Accessor methods to retrieve side lengths
	int getA() { return sideA; }	
	int getB() { return sideB; }
	int getC() { return sideC; }

	// Mutator methods to change side lengths
	void setA(int a) { sideA = a; }		
	void setB(int b) { sideB = b; }
	void setC(int c) { sideC = c; }

	// Processing
	bool isEquilateral();		
	bool isScalene();
	bool isIsosceles();
	bool isRight();

};

#endif // TRIANGLE_H_INCLUDED