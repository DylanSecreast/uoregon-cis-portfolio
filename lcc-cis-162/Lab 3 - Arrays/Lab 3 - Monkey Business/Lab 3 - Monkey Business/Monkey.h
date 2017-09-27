/*
Dylan Secreast
1/29/14
CS 162 C+ Winter 2014
Lab 3 - Monkey Business
Monkey.h
*/

#ifndef MONKEY_H
#define MONKEY_H


class Monkey
{
public:
	static const int NUM_MONKEYS = 3;
	static const int NUM_DAYS = 7;

private:
	int monkeyFood[NUM_MONKEYS][NUM_DAYS];

public:
	Monkey();											// Initialize array
	bool setMonkeyFood(int mnky, int day, int food);	// Sets input data into monkeyFood array
	double getAveragePerDay(int day);	// Average amount of food eaten per day by the whole family of monkeys
	int getSkinnyMonkey();			// The least amount of food eaten during the week by any one monkey
	int getFatMonkey();				// The greatest amount of food eaten during the week by any one monkey
};
















#endif // MONKEY_H