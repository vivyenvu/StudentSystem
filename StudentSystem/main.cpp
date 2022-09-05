#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main()
{
	cout << "C867 - Scripting and Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 009777954" << endl;
	cout << "Name: Vivyen Vu" << endl;

	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Vivyen,Vu,vvu11@wgu.edu,24,15,14,26,SOFTWARE"
	};

	Roster classRoster;
	
	//Create an array of ponters, which point to the objects of classRosterArray
	Roster* classRosterArray[5];
	for (int i = 0; i < 5; i++) {
		string info = studentData[i];

		size_t r = info.find(",");
		string id = info.substr(0, r);

		size_t l = r + 1;
		r = info.find(",", l);
		string first = info.substr(l, r - l);

		l = r + 1;
		r = info.find(",", l);
		string last = info.substr(l, r - l);

		l = r + 1;
		r = info.find(",", l);
		string address = info.substr(l, r - l);

		l = r + 1;
		r = info.find(",", l);
		int a = stoi(info.substr(l, r - l));

		int num[3];

		l = r + 1;
		r = info.find(",", l);
		num[0] = stoi(info.substr(l, r - l));

		l = r + 1;
		r = info.find(",", l);
		num[1] = stoi(info.substr(l, r - l));

		l = r + 1;
		r = info.find(",", l);
		num[2] = stoi(info.substr(l, r - l));

		l = r + 1;
		r = info.find(",", l);
		string p = info.substr(l, r - l);

		DegreeProgram deg = DegreeProgram::SECURITY;
		if (p == "NETWORK") {
			deg = DegreeProgram::NETWORK;
		}
		else if (p == "SOFTWARE") {
			deg = DegreeProgram::SOFTWARE;
		}
		classRoster.add(id, first, last, address, a, num, deg);
	}
	cout << "\n";
	cout << "Displaying all students:" << endl;
	classRoster.printAll();

	cout << "\n";
	classRoster.printInvalidEmails();

	cout << "\n";
	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getNumID(i));
	}

	cout << "\n";
	cout << "Showing students in degree program: SOFTWARE" << endl <<"\n";
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << "\n";
	cout << "Removing A3: " << endl << "\n";
	classRoster.remove("A3");
	classRoster.printAll();

	cout << "\n";
	cout << "Removing A3 again" << endl << "\n";
	classRoster.remove("A3");

	classRoster.~Roster();
		
	cout << "DONE.";
}
	
	


