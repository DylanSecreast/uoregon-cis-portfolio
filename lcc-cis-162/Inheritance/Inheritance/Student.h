/*
Dylan Secreast
3/2/14
CS 162 C+ Winter 2014
Inheritance Programming Project
Student.h
*/

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "Person.h"


// Inherits from Person class
class Student : public Person
{
private:
	float gpa;

public:
	// Constructors
	Student() : Person() { gpa = 0; }
	Student(std::string fName, std::string lName, int age, std::string lNum, float userGPA) : Person(fName, lName, age, lNum){ gpa = userGPA; }

	// Setters
	void setGPA(int grade){ gpa = grade; }
	virtual std::string getJob() const { return "Student"; }

	// Getters
	float getGPA(){ return gpa; }
};

#endif // STUDENT_H_INCLUDED