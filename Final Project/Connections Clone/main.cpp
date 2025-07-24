#include "game.h"

int main() {
	int choice;
	std::string puzzleFile;

	std::cout << "Choose a puzzle to load:\n";
	std::cout << "1. Puzzle 1\n";
	std::cout << "2. Puzzle 2\n";
	std::cout << "Enter choice (1 or 2): ";
	std::cin >> choice;
	std::cin.ignore();

	if (choice == 1) {
		puzzleFile = "puzzle1.txt";
	}
	else if (choice == 2) {
		puzzleFile = "puzzle2.txt";
	}
	else {
		std::cout << "Invalid choice. Exiting.\n";
		return 0;
	}

	GameManager game;
	if (game.loadPuzzle(puzzleFile)) {
		game.run();
	}
	
	return 0;
}