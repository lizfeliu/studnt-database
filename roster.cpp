//C867 project by Elizabeth Feliu 
//roster.cpp
#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

//Parses each student record from the student data table and sends parsed student record to Roster:Add
void Roster::ClassRosterParse(std::string record) {
	std::vector<std::string> tokens; 
	std::stringstream ss(record); 

	std::string subStr;
	while (std::getline(ss, subStr, ',')) {
		tokens.push_back(subStr);
	}

	//Determines the degree
	//Using special enum data type for the degree program
	DegreeProgram degreeProgram;
	if (tokens[8] == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (tokens[8] == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (tokens[8] == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	//Adds the new student record to the roster
	Add(tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), std::stoi(tokens.at(4)),
		std::stoi(tokens.at(5)), std::stoi(tokens.at(6)), std::stoi(tokens.at(7)), degreeProgram);
}

//Adds a new student object to the roster based on the details from studentData[]
//New student object then added to classRosterArray
void Roster::Add(const std::string studentID, const std::string firstName, const std::string lastName, const std::string studentEmail,
	const int studentAge, const int days1, const int days2, const int days3, DegreeProgram degree) {
	//Initiliaze an array with the number of days for the threee courses
	int days[] = { days1, days2, days3 };

	classRosterArray[++index] = new Student(studentID, firstName, lastName, studentEmail, studentAge, days, degree);
}

//Uses a student's ID to remove a student record
void Roster::Remove(const std::string studentID) {
	std::cout << "Attempting to remove student record with student ID: " << studentID << "...\n";
	//If ID is not in classRosterArray then an error is returned.
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
			std::cout << "Error: Record not found. No student removed.\n";
			break;
		}
		//If ID is found then the record with the student ID is removed from the array.
		else if (studentID == classRosterArray[i]->getStudentId()) {
			classRosterArray[i] = nullptr;
			std::cout << "Student record removed successfully.\n";
		}
	}
}

//Prints the complete classRosterArray in a table format.
void Roster::PrintAll() {
	//Iterates through each student record in classRosterArray
	for (int i = 0; i < numStudents; ++i) {
		//Checks if the current student record is not null.
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
}

//Prints average number of days for a students 3 courses from their student ID
void Roster::PrintAverageDaysInCourse(std::string studentID) {
	//Using a loop to iterate through each student
	for (int i = 0; i < numStudents; ++i) {
		//Using student ID in class roster array for output
		if (studentID == classRosterArray[i]->getStudentId()) {
			//Retreiving total number of days for each student
			int* days = classRosterArray[i]->getDays();
			//Calculating number of days and then displaying the integer in the output
			int avgDays = (days[0] + days[1] + days[2]) / 3;
			//Outputs a list of each student's avg days in courses
			std::cout << studentID << " has " << avgDays << " average days to complete their courses.\n";
		}
	}
}
//Prints invalid emails and displays the student ID for reference
void Roster::PrintInvalidEmails() {
	for (int i = 0; i < numStudents; ++i) {
		//Retreiving email from the classRosterArray
		std::string studentEmail = classRosterArray[i]->getStudentEmail();
		//Searching for invalid characters in each student email from classRosterArray
		if ((studentEmail.find(' ') != std::string::npos) || (studentEmail.find('.') == std::string::npos) || (studentEmail.find('@') == std::string::npos)) {
			//Outputs a list of invalid emails
			std::cout << studentEmail << " is an invalid email address. Please contact " << classRosterArray[i]->getStudentId() << '\n';
		}
	}
	std::cout << '\n';
	return;
}

//Prints all students from a specified degree program
void Roster::PrintByDegreeProgram(DegreeProgram degree) {
	//Using DegreeToString to convert enum data to string for printing purposes
	std::cout << "\nPrinting students enrolled in the " << DegreeToString(degree) << " program... \n";
	//Iterating through each student record 
	for (int i = 0; i < numStudents; ++i) {
		//Checking that the student record is not null
		if (classRosterArray[i] != nullptr) {
			//If specified degree matches record in classRosterArray then the record will print
			if (degree == classRosterArray[i]->getDegree()) {
				classRosterArray[i]->Print();
			}
			//Error output in case of invalid program entered.
			else {
				std::cout << "Error. Not a valid program.";
			}
		}
	}
	std::cout << std::endl;
}

// destructor
Roster::~Roster() {}