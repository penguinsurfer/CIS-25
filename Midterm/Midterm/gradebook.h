#ifndef GRADEBOOK_H // Header guard to prevent multiple inclusions
#define GRADEBOOK_H

#include "student.h" // Include Student class

class GradeBook {
private:
	Student** students; // Array of pointers to Student objects
	int capacity;
	int count; 

public:
	GradeBook(int capacity = 100); // Constructor
	~GradeBook(); // Destructor

	void addStudent(Student* s);
	void loadFromFile(const string& filename);
	void printAll() const;
	void saveToFile(const string& filename) const;
	Student* binarySearchByID(const string& targetID) const;
	void sortByID();
};

#endif // Header guard end