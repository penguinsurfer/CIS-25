#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
	double balance;

	void saveTransaction(const string& type, const string& item, double amount) {
		ofstream file("transactions.txt", ios::app);
		if (file.is_open()) {
			if (type == "Deposit") {
				file << type << ": $" << amount << endl;
			}
			else {
				file << type << " - " << item << ": $" << amount << endl;
			}
			file.close();
		}
		else {
			cout << "Error: Unable to open file." << endl;
		}
	}

public:
	BankAccount() {
		balance = 0.0;
	}

	void deposit(double amount) {
		if (amount <= 0) {
			cout << "Deposit must be a positive amount." << endl;
			return;
		}
		balance += amount;
		saveTransaction("Deposit", "", amount);
	}

	void makePurchase(const string& item, double cost) {
		if (cost <= 0) {
			cout << "Purchase amount must be positive." << endl;
			return;
		}

		if (cost > balance) {
			cout << "Insufficient funds for " << item << endl;
		}
		else {
			balance -= cost;
			saveTransaction("Purchase", item, cost);
		}
	}

	void displayBalance() const {
		cout << "Current Balance: $" << balance << endl;
	}
};

int main() {
	BankAccount myAccount;

	myAccount.deposit(100.0);
	myAccount.makePurchase("Sandwich", 10.00);
	myAccount.makePurchase("Uber", 25.00);
	myAccount.displayBalance();

	return 0;
}