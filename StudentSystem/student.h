#pragma once
#include "degree.h"
#include <string>
using namespace std;

class Student {
	public:
		Student();
		Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram program);
		~Student();

		void setID(string id);
		void setFirstName(string first);
		void setLastName(string last);
		void setEmail(string address);
		void setAge(int a);
		void setNumDays(int* numDays);
		void setNumDays(int i, int days);
		void setProgram(DegreeProgram p);

		string getID();		
		string getFirstName();		
		string getLastName();		
		string getEmail();		
		int getAge();
		int* getNumDays(); 
		enum DegreeProgram getProgram();
		void print();

	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int numDays[3];
		DegreeProgram program;
};
