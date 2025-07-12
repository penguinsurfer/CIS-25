#ifndef STUDENT_H // Header guard to prevent multiple inclusions
#define STUDENT_H

#include <string>
#include <fstream>
using namespace std;

class Student {
private: 
	string name;
	string id;
	int* grades;
	int numGrades;

public:
	Student(string name, string id, int* grades, int numGrades); // Constructor
	~Student(); // Destructor

	string getID() const; 
	double getAverage() const; 
	void printInfo() const; 
	void writeToFile(ofstream& out) const;

};

#endif // Header guard end