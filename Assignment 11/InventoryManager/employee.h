#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "user.h"

class Employee : public User {
public:
	void accessLevel() override {
		cout << "Employee Access\n";
	}
};

#endif