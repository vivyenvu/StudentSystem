#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

	Roster::Roster() {
	}

	Roster::~Roster() {
		for (int i = 0; i < 5; i++) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}

	void Roster::add(string studentID, string firstName, string lastName, string email, int age, int numD[], DegreeProgram program) {
		for (int i = 0; i < 5; i++) {
			if (classRosterArray[i] == nullptr) {
				classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, numD, program);
				break;
			}
		}
	}
	void Roster::remove(string id) {
		int found = 0; //0 = not found, 1 = found
		for (int i = 0; i < 5; i++) {
			if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getID() == id)) {
				//delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				found = 1;
			}
			/* else if (classRosterArray[i] == nullptr)
			{
				cout << "Student with ID: " << id << " was not found." << endl;
			*/
		}
		if (found == 0) {
			cout << "Student with ID: " << id << " was not found." << endl;
		}
	};
	void Roster::printAll() { 
		for (int i = 0; i < 5; i++) {
			if (classRosterArray[i] != nullptr) {
				classRosterArray[i]->print();
			}
		}
};
	void Roster::printAverageDaysInCourse(string studentID) { 
		int sum = 0;
		for (int i = 0; i < 5; i++){
			if (classRosterArray[i]->getID() == studentID) {
				int* arr = classRosterArray[i]->getNumDays();
				sum = arr[0];
				sum += arr[1];
				sum += arr[2];
			}
		}

		int average = sum / 3;
		cout << "StudentID: " << studentID << ", average days in course is: " << average << endl;
	};
	// A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	void Roster::printInvalidEmails() {
		cout << "Displaying invalid emails:" << endl << "\n";
		for (int i = 0; i < 5; i++) {
			string email = classRosterArray[i]->getEmail();
			if (email.find('@') == string::npos) {
				cout << email << " - is invalid." << endl;
			}
			else if (email.find('.') == string::npos) {
				cout << email << " - is invalid." << endl;
			}
			else if (email.find(' ') != string::npos) {
				cout << email << " - is invalid." << endl;
			}
		}
	};

	void Roster::printByDegreeProgram(DegreeProgram p) {
		
		for (int i = 0; i < 5; i++) {
			if (classRosterArray[i]->getProgram() == p) {
				classRosterArray[i]->print();
			}
		}
	};

	string Roster::getNumID(int number) {
		return classRosterArray[number]->getID();
	};
