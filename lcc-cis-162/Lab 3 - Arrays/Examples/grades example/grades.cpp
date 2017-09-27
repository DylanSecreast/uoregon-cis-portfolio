#include "grades.h"

Grades::Grades()
{
        // initialize grades to zero
    for(int i = 0; i < NUMSTUDENTS; i++)
        for(int j = 0; j < NUMTESTS; j++)
        testGrades[i][j] = 0;

        // initialize names to empty strings
    for(int i = 0; i < NUMSTUDENTS; i++)
        studentNames[i] = "";
}

    // set student name, if valid code
bool Grades::setStudentName(int student, std::string name)
{
    if (student >= 0 && student < NUMSTUDENTS)
    {
        studentNames[student] = name;
        return true;
    }
    return false;
}

    // get student name, if valid code
std::string Grades::getStudentName(int student)
{
    if (student >= 0 && student < NUMSTUDENTS)
    {
        return studentNames[student];
    }
    return "Invalid Student Code";
}

    // set test grade, if valid student code and test number
bool Grades::setGrade(int student, int test, int grade)
{
    if (student >= 0 && student < NUMSTUDENTS && test >= 0 && test < NUMTESTS)
    {
        testGrades[student][test] = grade;
        return true;
    }
    return false;
}

    // return index of student with highest score on test
    // if valid test number, otherwise return -1
int Grades::highGrade(int test)
{
    if (test >= 0 && test < NUMTESTS)
    {
        int highScore = testGrades[0][test];
        int highStudent = 0;
        for(int i = 1; i < NUMSTUDENTS; i++)
        {
            if ( highScore < testGrades[i][test])
            {
                highScore = testGrades[i][test];
                highStudent = i;
            }
        }
        return highStudent;
    }
    return -1;
}

    // return average grade for student
    // if valid student code, otherwise return -1
int Grades::studentAverage(int student)
{
    if (student >= 0 && student < NUMSTUDENTS)
    {
        int sum = 0;
        for(int i = 1; i < NUMTESTS; i++)
        {
            sum += testGrades[student][i];
        }
        return sum/NUMTESTS;
    }
    return -1;
}
