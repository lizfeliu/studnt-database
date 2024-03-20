//C867 project by Elizabeth Feliu 
//main.cpp
#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"

int main() {
	//Header information
	std::cout << "WGU's C867: Scripting and Programming - Applications"
			  << "\nProgramming Language Used: C++"
			  << "\nName: Elizabeth Feliu"
			  << "\nStudent ID: 010116157\n\n";

	//Student data table information
	const std::string studentData[] =
	{
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"010116157,Elizabeth,Feliu,efeliu@wgu.edu,27,18,20,27,SOFTWARE"
	};

	//Initializing the roster from studentData[]
	Roster classRoster;
	for (int i = 0; i < numStudents; ++i) {
		classRoster.ClassRosterParse(studentData[i]);
	}

	//Displaying all students in the roster
	classRoster.PrintAll();

	std::cout << '\n';

	//Retreiving and printing out all of the invalid emails in the roster
	std::cout << "Printing invalid emails... \n";
	classRoster.PrintInvalidEmails();

	//Retreiving and printing the average days in courses per student 
	std::cout << "\nPrinting average days in courses per student... \n";
	for (int i = 0; i < numStudents; ++i) {
		classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
	}

	//Printing list of students by the Software degree program
	classRoster.PrintByDegreeProgram(DegreeProgram::SOFTWARE);

	//Attempting to remove student with the ID of A3
	classRoster.Remove("A3");
	std::cout << '\n';

	//Printing updated roster
	classRoster.PrintAll();
	std::cout << '\n';

	//Second attempt to remove student with the ID of A3 to show functionality and error
	classRoster.Remove("A3");
	std::cout << '\n';

	classRoster.~Roster();

	return 0;
}