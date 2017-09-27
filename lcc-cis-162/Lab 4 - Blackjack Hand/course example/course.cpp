#include "course.h"


	// constructer, start new course with no students
Course::Course()
{
	classSize = 0;
}

	// add a new student unless the course is full
bool Course::addStudent(Student * s)
{
	if ( classSize < MAX_STUDENTS )
	{
		studentsInClass[classSize] = s;
		classSize++;
		return true;
	}
	return false;
}

std::string Course::getStudents()
{
	std::string theStudents = "";

	for ( int i = 0; i < classSize; i++ )
	{
		theStudents += studentsInClass[i]->getName() + "\n";
	}
	return theStudents;
}

	// delete existing students
	// start over with new course
void Course::resetCourse()
{
	for ( int i = 0; i < MAX_STUDENTS; i++ )
	{
		delete studentsInClass[i];
	}
	classSize = 0;
}


