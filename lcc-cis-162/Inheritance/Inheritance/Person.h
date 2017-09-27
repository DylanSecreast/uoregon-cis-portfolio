/*
Dylan Secreast
3/2/14
CS 162 C+ Winter 2014
Inheritance Programming Project
Person.h
*/

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>
#include <iostream>


// Parent class
class Person
{
protected:
	std::string firstName;
	std::string lastName;
	int age;
	std::string lNumber;

public:
	// Constructors
	Person();
	Person(std::string fName, std::string lName, int userAge, std::string lNum){ firstName = fName, lastName = lName, age = userAge, lNumber = lNum; }

	// Setters
	void setFirstName(std::string fName){ firstName = fName; }
	void setLastName(std::string lName){ lastName = lName; }
	void setAge(int userAge){ age = userAge; }
	void setLNumber(std::string lNum){ lNumber = lNum; }

	// Getters
	std::string getFirstName(){ return firstName; }
	std::string getLastName(){ return lastName; }
	int getAge(){ return age; }
	std::string getLNumber(){ return lNumber; }

	// Virtual function
	virtual std::string getJob() const { return "Undefined"; }
}; 

#endif // PERSON_H_INCLUDED