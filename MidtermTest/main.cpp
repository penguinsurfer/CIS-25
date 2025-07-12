#include <iostream>
#include "gradebook.h"
using namespace std;

int main() {
	GradeBook book;
	book.loadFromFile("students.txt");

	cout << "Student List\n";
	book.printAll();
	book.sortByID(); // binary search
	
	string searchForID;
	cout << "\nEnter student ID to search for: ";
	cin >> searchForID;

	Student* result = book.binarySearchByID(searchForID);
	if (result) {
		cout << "\nStudent found:\n";
		result->printInfo();
	}
	else {
		cout << "\nStudent with ID " << searchForID << " not found.\n";
	}

	book.saveToFile("output.txt");
	cout << "\nGrades saved to output.txt\n";

	return 0;

}