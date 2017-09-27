#include <iostream>
#include "grades.h"

using namespace std;

int main()
{
    Grades myClass;

        // set up names
    myClass.setStudentName(0, "Beth");
    myClass.setStudentName(1, "Joe");
    myClass.setStudentName(2, "Bill");
    myClass.setStudentName(3, "Mary");
    myClass.setStudentName(4, "Turtle");

        // enter grades for tests
    for (int i = 0; i < Grades::NUMTESTS; i++)
    {
        cout << "Enter grades for test number " << i << endl;
        for (int j = 0; j < Grades::NUMSTUDENTS; j++)
        {
            cout << " grade for " << myClass.getStudentName(j) << " is: ";
            int grade;
            cin >> grade;
            myClass.setGrade(j, i, grade);
        }
        cout << endl;
    }

        // find who did best on each test
    for (int i = 0; i < Grades::NUMTESTS; i++)
    {
        cout << "For test number " << i << " the highest student was " << myClass.getStudentName(myClass.highGrade(i))<< endl;
    }
    cout << endl;

        // find out average grade for each student
    for (int i = 0; i < Grades::NUMSTUDENTS; i++)
    {
        cout << myClass.getStudentName(i) << " had an average grade of " << myClass.studentAverage(i) << endl;
    }

    return 0;
}
