#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "student.h"

class GradeBook {
private:
	Student** students;
	int capacity;
	int count;

public:
	GradeBook(int capacity = 100);
	~GradeBook(); // Free dynamically allocated memory

	void addStudent(Student* s);
	void loadFromFile(const string& filename);
	void printAll() const;
	void saveToFile(const string& filename) const;
	Student* binarySearchByID(const string& targetID) const;
	void sortByID();
};

#endif