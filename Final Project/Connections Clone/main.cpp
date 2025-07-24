#include "game.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	int choice;
	string puzzleFile;
	string username;

	cout << "Enter your username: ";
	getline(cin, username);

	cout << "Hello "<<username<<"! Choose a puzzle to load : \n";
	cout << "1. Puzzle 1\n";
	cout << "2. Puzzle 2\n";
	cout << "Enter choice (1 or 2): ";
	cin >> choice;
	cin.ignore(); // ignore newline character after integer input

	if (choice == 1) {
		puzzleFile = "puzzle1.txt";
	}
	else if (choice == 2) {
		puzzleFile = "puzzle2.txt";
	}
	else {
		cout << "Invalid choice. Exiting.\n";
		return 0;
	}

	// initialize and run game
	GameManager game;
	game.setUsername(username);

	if (game.loadPuzzle(puzzleFile)) {
		game.run(puzzleFile);
	}
	
	return 0;
}