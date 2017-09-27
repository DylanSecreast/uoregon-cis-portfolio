/*
Dylan Secreast
3/2/14
CS 162 C+ Winter 2014
Inheritance Programming Project
Instructor.h
*/

#ifndef INSTRUCTOR _H_INCLUDED
#define INSTRUCTOR _H_INCLUDED

#include "Person.h"

// Inherits from Person class
class Instructor : public Person
{
private:
	std::string officeHours;

public:
	// Constructors
	Instructor() : Person() { officeHours = ""; }
	Instructor(std::string fName, std::string lName, int age, std::string lNum, std::string officeHrs) : Person (fName, lName, age, lNum) { officeHours = officeHrs; }
	
	// Setters
	void setOfficeHours(int hours){ officeHours = hours; }
	virtual std::string getJob() const { return "Instructor"; }

	// Getters
	std::string getOfficeHours() { return officeHours; }
};

#endif // INSTRUCTOR _H_INCLUDED