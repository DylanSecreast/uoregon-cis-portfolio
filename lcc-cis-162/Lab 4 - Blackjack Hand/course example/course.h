#ifndef COURSE_H
#define COURSE_H

#include "student.h"

class Course {
	public:
		const static int MAX_STUDENTS = 25;

	private:
		Student * studentsInClass[MAX_STUDENTS];
		int classSize;

	public:
		Course();
		bool addStudent(Student * s);
		int getClassSize() {return classSize;}
		std::string getStudents();
		void resetCourse();
};
#endif // COURSE_H
