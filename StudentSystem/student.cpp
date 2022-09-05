#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student() {
	this->setID("");
	this->setFirstName("");
	this->setLastName("");
	this->setEmail("");
	this->setAge(0);
	for (int i = 0; i < 3; i++) {
		this->setNumDays(i,0);
	}
	this->setProgram(DegreeProgram::SOFTWARE);
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], enum DegreeProgram program) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) {
		this->numDays[i] = numDays[i];
	}
	this->program = program;
}

Student::~Student() {
	
}

void Student::setID(string id) {
	studentID = id;
}
void Student::setFirstName(string first) {
	firstName = first;
}
void Student::setLastName(string last) {
	lastName = last;
}
void Student::setEmail(string address) {
	email = address;
}
void Student::setAge(int a) {
	age = a;
}
void Student::setNumDays(int* numD) {
	for (int i = 0; i < 3; i++) {
		numDays[i] = numD[i];
	}
}
void Student::setNumDays(int i, int days) {
	numDays[i] = days;
}
void Student::setProgram(DegreeProgram p) { 
	program = p;
}

string Student::getID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return email;
}

int Student::getAge() {
	return age;
}
int* Student::getNumDays() {
	return numDays;
}
DegreeProgram Student::getProgram() {
	return program;
}
void Student::print() {
	string program_string;
	if (this->getProgram() == DegreeProgram::SECURITY) {
		program_string = "SECURITY";
	}
	if (this->getProgram() == DegreeProgram::NETWORK) {
		program_string = "NETWORK";
	}
	if (this->getProgram() == DegreeProgram::SOFTWARE) {
		program_string = "SOFTWARE";
	}
	cout << this->getID() << "\t" << this->getFirstName() << "\t" << this->getLastName() << "\t" << this->getAge() << "\t{" 
		<< this->numDays[0] << ", "
		<< this->numDays[1] << ", "
		<< this->numDays[2] << "}"
		<< "\t" << program_string << endl;
}
