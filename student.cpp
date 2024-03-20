//C867 project by Elizabeth Feliu 
//student.cpp
#include "student.h"
#include "degree.h"
#include <iostream>

//Student class constructor
Student::Student() :
	//Initializing member variables with blank values
	studentID(""),
	firstName(""),
	lastName(""),
	studentEmail(""),
	studentAge(-1),
	//Allocating memory for the days array
	days(new int[DAYS_SIZE])
	{
	//Initializing the numDays array elements to 0 in a loop
	for (int i = 0; i < DAYS_SIZE; ++i) {
			this->days[i] = 0;
	}
}

// Student class constructor initializes a student object using setter functions for 
// each member variable. Receives the argument from Roster:add in roster.cpp.
Student::Student(
	std::string studentID, 
	std::string firstName, 
	std::string lastName, 
	std::string studentEmail, 
	int studentAge, 
	int days[], 
	DegreeProgram degree //student degree program using special enum data type / degree.h for creation
)
{
	setStudentId(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setStudentEmail(studentEmail);
	setStudentAge(studentAge);
	setDays(days);
	setDegree(degree);
}

// Setters (mutators) for the Student class
//Sets student's id.
void Student::setStudentId(const std::string studentID) {
	this->studentID = studentID; //Asigning the incoming value into the studentID member value.
	return;
}
//Sets student's first name.
void Student::setFirstName(const std::string firstName) {
	this->firstName = firstName; //Asigning the incoming value into the firstName member value.
	return;
}
//Sets student's last name.
void Student::setLastName(const std::string lastName) {
	this->lastName = lastName; //Asigning the incoming value into the lastName member value.
	return;
}
//Sets student's student email.
void Student::setStudentEmail(const std::string studentEmail) {
	this->studentEmail = studentEmail; //Asigning the incoming value into the studentEmail member value.
	return;
}
//Sets student's age.
void Student::setStudentAge(const int studentAge) {
	this->studentAge = studentAge; //Asigning the incoming value into the studentAge member value.
	return;
}
//Sets student's number of days to complete each course. 
void Student::setDays(int days[]) {
	this->days = new int[DAYS_SIZE]; //Allocating memeory for the days array.
	for (int i = 0; i < DAYS_SIZE; ++i) {
		this->days[i] = days[i]; //Copying each incoming integer value into the member variable. 
	}
}
//Sets student's degree program. 
void Student::setDegree(DegreeProgram degree) {
	this->degree = degree; //Asigning the incoming value into the degree member value.
	return;
}

//Accessor(getter) functions to retrieve the attributes of the student object
// Retrieves student's ID.
std::string Student::getStudentId() const {
	return studentID;
}
// Retrieves student's first name.
std::string Student::getFirstName() const {
	return firstName;
}
// Retrieves student's last name
std::string Student::getLastName() const {
	return lastName;
}
// Retrieves student's email address.
std::string Student::getStudentEmail() const {
	return studentEmail;
}
// Retrieves student's age.
int Student::getStudentAge() const {
	return studentAge;
}
// Retrieves the number of days the student needs to complete each course
int* Student::getDays() const {
	return days;
}
// Retrieves student's degree program.
DegreeProgram Student::getDegree() {
	return degree;
}

// Printing out the student's complete record in a table format
void Student::Print() {
	//Outputing basic student details
	std::cout << getStudentId()
			  << "\tFirst name: " << getFirstName()
			  << "\tLast name: " << getLastName()
			  << "\tAge: " << getStudentAge();
	//Outputing student's days to complete each course
	int* days = getDays();
	std::cout << "\tDays in courses: ";
	for (int i = 0; i < DAYS_SIZE; ++i) {
	std::cout << days[i] << (i < DAYS_SIZE - 1 ? " " : "");
	}
	//Converting degree program to a string.
	std::string degreeString = DegreeToString(getDegree());
	//Outputs student's degree program.
	std::cout << "\tDegree: " << degreeString << std::endl;
}

// deconstructor
Student::~Student() {}