#include <iostream>
#include <string>
using namespace std;


struct Student {
	string name;
	int id;
	double gpa;
};

int binarySearch(Student* arr, int size, int targetId) {
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (targetId == arr[mid].id) {
			return mid;
		}
		else if (targetId > arr[mid].id) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int main() {
	int size = 3;

	Student* students = new Student[size];

	students[0] = {"Michael", 102, 3.8};
	students[1] = {"Lakisha", 103, 3.5};
	students[2] = {"Charlie", 104, 3.9};

	int searchId;
	cout << "Enter ID to search for: ";
	cin >> searchId;

	// binary search
	int index = binarySearch(students, size, searchId);

	if (index != -1) {
		cout << students[index].name << " (ID: " << students[index].id << ", GPA: " << students[index].gpa << ")" << '\n';
	}
	else {
		cout << "ID not found" << '\n';
	}

	delete[] students;

	return 0;
}



