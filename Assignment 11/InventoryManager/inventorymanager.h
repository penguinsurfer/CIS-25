#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "employee.h"

class InventoryManager : public Employee {
public:
	void accessLevel() override {
		cout << "Full Inventory Management Access\n";
	}
};

#endif