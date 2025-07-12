#include "gradebook.h"
#include <fstream>
#include <iostream>

GradeBook::GradeBook(int capacity) {
	this->capacity = capacity;
	count = 0;
	students = new Student * [capacity];
}

GradeBook::~GradeBook() {
	for (int i = 0; i < count; ++i) {
		delete students[i];
	}
	delete[] students;
}

void GradeBook::addStudent(Student* s) {
	if (count < capacity) {
		students[count++] = s;
	}
}

void GradeBook::loadFromFile(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cerr << "Error opening file: " << filename << endl;
		return;
	}

	string name, id;
	int g1, g2, g3;
	while (file >> name >> id >> g1 >> g2 >> g3) {
		int grades[3] = { g1,g2,g3 };
		addStudent(new Student(name, id, grades, 3));
	}

	file.close();
}

void GradeBook::printAll() const {
	for (int i = 0; i < count; ++i) {
		students[i]->printInfo();
	}
}

void GradeBook::saveToFile(const string& filename) const {
	ofstream file(filename);
	if (!file) {
		cerr << "Error writing to file: " << filename << endl;
		return;
	}

	file << "Students Grades Report:\n";
	for (int i = 0; i < count; ++i) {
		students[i]->writeToFile(file);
	}
	
	file.close();
}

Student* GradeBook::binarySearchByID(const string& targetID) const {
	int low = 0, high = count - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		string midID = students[mid]->getID();
		if (midID == targetID) {
			return students[mid];
		}
		else if (midID < targetID) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return nullptr;
}

void GradeBook::sortByID() {
	for (int i = 0; i < count - 1; ++i) {
		for (int j = i + 1; j < count; ++j) {
			if (students[i]->getID() > students[j]->getID()) {
				swap(students[i], students[j]);
			}
		}
	}
}

