#include <iostream>
#include "course.h"

using namespace std;

int main()
{
    Course dataStructures;

    Student * mary = new Student("Mary Smith", 99);

    Student * bob = new Student("Bob Jones", 66);

    Student * sam = new Student ("Samwise Gamgee", 42);

	cout << "Before starting, course size is " << dataStructures.getClassSize() << endl;
	cout << "and the class list is:" << endl << dataStructures.getStudents() << endl;

	dataStructures.addStudent(mary);
	dataStructures.addStudent(bob);
	dataStructures.addStudent(sam);

	cout << "After adding, course size is " << dataStructures.getClassSize() << endl;
	cout << "and the class list is:" << endl << dataStructures.getStudents() << endl;

	dataStructures.resetCourse();

	cout << "After reset, course size is "<< dataStructures.getClassSize() << endl;
	cout << "and the class list is:" << endl << dataStructures.getStudents() << endl;


    return 0;
}
