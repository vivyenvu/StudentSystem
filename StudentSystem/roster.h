#pragma once
#include "student.h"
#include <string>

	class Roster {
	public:
		Roster();
		~Roster();

		void add(std::string id, std::string first, std::string last, std::string address, int age, int numD[], DegreeProgram program);
		void remove(string id);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram p);
		string getNumID(int number);

	private:
		Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	};
