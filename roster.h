//C867 project by Elizabeth Feliu 
//roster.h
#ifndef roster_h
#define roster_h
#pragma once
#include "degree.h"
#include "student.h"
#include <stdio.h>
#include <iostream>


const int DATA_COLS = 9;
static const unsigned int numStudents = 5;

class Roster {
//public roster class
public:
	//Array of pointers to hold the data provided in the student table
	Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	//Public member functions
	void Add(std::string studentID, std::string firstName, std::string lastName, std::string studentEmail, 
		int studentAge, int days1, int days2, int days3, DegreeProgram degree);
	void ClassRosterParse(std::string record);
	void Remove(std::string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(std::string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degree);

	//Public member function to convert DegreeProgram enum to a string for printing purposes.
	std::string DegreeToString(DegreeProgram degree) const {
		switch (degree) {
		case DegreeProgram::SECURITY: return "SECURITY";
		case DegreeProgram::NETWORK:  return "NETWORK";
		case DegreeProgram::SOFTWARE: return "SOFTWARE";
		default: return "UNKNOWN";
		}
	}

	//Destructor
	~Roster();

//private roster class
private:
	// Index to keep track of the current number of students in the Add function
	int index = -1;
};

#endif