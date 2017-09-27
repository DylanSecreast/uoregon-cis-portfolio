#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
	private:
		std::string name;
		int idNum;

	public:
		Student(std::string nm = "", int id = 0) {name = nm; idNum = id;}
		int getNum() {return idNum;}
		std::string getName() {return name;}

};
#endif // STUDENT_H
