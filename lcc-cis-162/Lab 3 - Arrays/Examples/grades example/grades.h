#ifndef GRADES_H
#define GRADES_H

#include <string>

class Grades{
    public:
        static const int NUMSTUDENTS = 5;
        static const int NUMTESTS = 4;

    private:
        std::string studentNames[NUMSTUDENTS];
        int testGrades[NUMSTUDENTS][NUMTESTS];

    public:
        Grades();
        bool setStudentName(int student, std::string name);
        std::string getStudentName(int student);
        bool setGrade(int student, int test, int grade);
        int highGrade(int test);
        int studentAverage(int student);
};
#endif // GRADES_H
