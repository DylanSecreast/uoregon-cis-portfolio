#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <time.h>

#include "instructor.h"
#include "student.h"

using namespace std;

void makePersonInfo(string & fName, string & lName, int & age, string & lNum);
string makeHours();
float makeGPA();

int main()
{
    srand(time(NULL));
    string fName;
    string lName;
    int age;
    string lNum;
    string officeHrs;
    float gpa;

    const int MAXPERSONS = 3;
    Person ** thePersons = new Person*[MAXPERSONS];

    const int MAXINSTRUCTORS = 4;
    Instructor ** theInstructors = new Instructor*[MAXINSTRUCTORS];

    const int MAXSTUDENTS = 8;
    Student ** theStudents = new Student*[MAXSTUDENTS];

    // create instructors
    for (int i = 0; i < MAXINSTRUCTORS; i++)
    {
        makePersonInfo(fName, lName, age, lNum);
        officeHrs = makeHours();
        theInstructors[i] = new Instructor(fName, lName, age, lNum, officeHrs);
    }

    cout << "Faculty " << endl;
    cout << " shoud show 4 instructors with names, ages, Lnumbers, and office hours\n";
    cout << "     Name      " << " Age " << " LNumber " << "   Office Hours " << endl;
    for ( int i = 0; i < MAXINSTRUCTORS; i++ )
    {
        fName = theInstructors[i]->getFirstName();
        lName = theInstructors[i]->getLastName();
        age = theInstructors[i]->getAge();
        lNum = theInstructors[i]->getLNumber();
        officeHrs = theInstructors[i]->getOfficeHours();
        cout << setw(7) << fName << setw(8) << lName << setw(4) << age <<
            setw(10) << lNum << " " << officeHrs << endl;
    }

    //create students
    for (int i = 0; i < MAXSTUDENTS; i++)
    {
        makePersonInfo(fName, lName, age, lNum);
        gpa = makeGPA();
        theStudents[i] = new Student(fName, lName, age, lNum, gpa);
    }

    cout << "\n\nStudents " << endl;
    cout << " should show 8 students with names, ages, Lnumbers, and GPAS\n";
    cout << "     Name      " << " Age " << " LNumber " << " GPA " << endl;
    for ( int i = 0; i < MAXSTUDENTS; i++ )
    {
        fName = theStudents[i]->getFirstName();
        lName = theStudents[i]->getLastName();
        age = theStudents[i]->getAge();
        lNum = theStudents[i]->getLNumber();
        gpa = theStudents[i]->getGPA();
        cout << setw(7) << fName << setw(8) << lName << setw(4) << age <<
            setw(10) << lNum << setw(6) << setprecision(2) << fixed << gpa << endl;
    }

    cout << "\n\nShowing jobs " << endl;
    cout << "should output Test One Undefined, Test Two Instructor, Test Three Student\n";

    thePersons[0] = new Person();
    thePersons[0]->setFirstName("Test");
    thePersons[0]->setLastName("One");

    thePersons[1] = new Instructor();
    thePersons[1]->setFirstName("Test");
    thePersons[1]->setLastName("Two");

    thePersons[2] = new Student();
    thePersons[2]->setFirstName("Test");
    thePersons[2]->setLastName("Three");

    for (int i = 0; i < MAXPERSONS; i++)
    {
        cout << thePersons[i]->getFirstName() <<" "<< thePersons[i]->getLastName()
            <<" "<< thePersons[i]->getJob() << endl;
    }


		//cleaning up
	for (int i=0; i < MAXPERSONS; i++)
	{
		delete thePersons[i];
	}
	delete []thePersons;

	for (int i=0; i < MAXINSTRUCTORS; i++)
    {
        delete theInstructors[i];
    }
    delete []theInstructors;

    for (int i=0; i < MAXSTUDENTS; i++)
    {
        delete theStudents[i];
    }
    delete []theStudents;


    return 0;
}

void makePersonInfo(string & fName, string & lName, int & age, string & lNum)
{
    const int FIRSTS = 8;
    const int LASTS = 7;
    string firstNames[FIRSTS] = {"Bill", "Mary", "John", "Nancy", "Paul", "George", "Frodo", "Linda"};
    string lastNames[LASTS] = {"Jones", "Smith", "Green", "White", "Baggins", "Dunhill", "Bourne"};

    const int MINAGE = 18;
    const int AGERANGE = 40;

    const int LRANGE = 1000000;

    stringstream ss;

    fName = firstNames[rand()%FIRSTS];
    lName = lastNames[rand()%LASTS];
    age = rand()%AGERANGE + MINAGE;
    ss << "L00" << setw(6) << setfill('0') << rand()%LRANGE;
    lNum = ss.str();
}

string makeHours()
{
    const int NUMHRS = 9;
    string someHours[NUMHRS] = {"8-9", "9-10", "10-11", "11-12", "12-1", "1-2", "2-3", "3-4", "4-5"};

    stringstream ss;

    return "Mon:" + someHours[rand()%NUMHRS] + " Tue:" + someHours[rand()%NUMHRS]
        + " Wed:" + someHours[rand()%NUMHRS] + " Thu:" + someHours[rand()%NUMHRS];
}

float makeGPA()
{
    return rand()%3+2 + static_cast<float>(rand()%100)/100.0;
}
