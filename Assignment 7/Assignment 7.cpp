#include <iostream>
#include <string>
using namespace std;

class Item {
public:
	string name;
	int quantity;

	Item(string n, int q) {
		name = n;
		quantity = q;
	}

	virtual void display() = 0;
};

class Perishable : public Item {
public:
	Perishable(string n, int q) : Item(n, q) {}

	void display() override {
		cout << name << " (Perishable), Qty: " << quantity << endl;
	}
};

class NonPerishable : public Item {
public:
	NonPerishable(string n, int q) : Item(n, q) {}

	void display() override {
		cout << name << " (Non-Perishable), Qty: " << quantity << endl;
	}
};

int main() {
	Item* item1 = new Perishable("Milk", 10);
	Item* item2 = new NonPerishable("Cereal", 20);

	item1->display();
	item2->display();

	delete item1;
	delete item2;

	return 0;
}