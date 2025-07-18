#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
public:
	virtual void accessLevel() {
		cout << "General Access\n";
	}
};

#endif