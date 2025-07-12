#include "student.h"
#include <iostream>
#include <iomanip>

Student::Student(string name, string id, int* grades, int numGrades) {
	this->name = name;
	this->id = id;
	this->numGrades = numGrades;
	this->grades = new int[numGrades];
	for (int i = 0; i < numGrades; i++) {
		this->grades[i] = grades[i];
	}
}

Student::~Student() {
	delete[] grades;
}

string Student::getID() const {
	return id;
}

double Student::getAverage() const {
	if (numGrades == 0) return 0.0;
	int sum = 0;
	for (int i = 0; i < numGrades; i++) {
		sum += grades[i];
	}
	return static_cast<double>(sum) / numGrades; // Calculate average and uses static_cast for double division
}

void Student::printInfo() const {
	cout << "Name: " << name << ", ID: " << id << ", Grades: ";
	for (int i = 0; i < numGrades; ++i) {
		cout << grades[i] << " ";
	}
	cout << "Avg: " << fixed << setprecision(2) << getAverage() << endl; // Print average with 2 decimal places
}

void Student::writeToFile(ofstream& out) const {
	out << name << " (ID: " << id << ") - Avg: " << fixed << setprecision(2) << getAverage() << endl;
}