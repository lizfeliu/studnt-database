//C867 project by Elizabeth Feliu 
//student.h
#ifndef student_h
#define student_h
#pragma once
#include "degree.h"
#include <iostream>
#include <stdio.h>

class Student {
//public student class
public:
	//Constructors
	Student(); //Default constructor
	Student(const std::string studentID, const std::string firstName, const std::string lastName, 
		const std::string studentEmail, const int studentAge, int days[], DegreeProgram degree);

	//Mutators (setters)
	void setStudentId(const std::string studentID);
	void setFirstName(const std::string firstName);
	void setLastName(const std::string lastName);
	void setStudentEmail(const std::string studentEmail);
	void setStudentAge(int studentAge);
	void setDays(int days[]);
	void setDegree(DegreeProgram degree);

	//Accessors (getters)
	std::string getStudentId() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getStudentEmail() const;
	int getStudentAge() const;
	int* getDays() const;
	DegreeProgram getDegree();

	//Punlic member function
	virtual void Print();
	//Public member function to convert DegreeProgram enum to a string for printing purposes.
	std::string DegreeToString(DegreeProgram degree) const {
		switch (degree) {
		case DegreeProgram::SECURITY: return "SECURITY";
		case DegreeProgram::NETWORK:  return "NETWORK";
		case DegreeProgram::SOFTWARE: return "SOFTWARE";
		default: return "UNKNOWN";
		}
	}

	static const int DAYS_SIZE = 3;

	//Destructor
	~Student();

//private student class
private:
	//Data Members
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string studentEmail;
	int studentAge;
	int* days;
	DegreeProgram degree;

};

#endif