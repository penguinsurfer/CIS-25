#include "game.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// constructor to initialize lives
GameManager::GameManager() {
	lives = 4;
}

// load puzzle file and parse groups and words
bool GameManager::loadPuzzle(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cout << "Failed to open puzzle file.\n";
		return false;
	}

	string line;
	while (getline(file, line)) {
		if (line.rfind("GROUP:", 0) == 0) {
			string groupName = line.substr(6);
			getline(file, line);
			stringstream ss(line);
			string word;
			vector<string> words;

			// split comma-separated words
			while (getline(ss, word, ',')) {
				word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
				words.push_back(word);
				allWords.push_back(word);
			}
			groups[groupName] = words;
		}
	}

	// shuffle words for randomness
	random_shuffle(allWords.begin(), allWords.end());
	return true;
}

// display available words
void GameManager::printWords() {
	cout << "\nAvailable Words:\n";
	for (const string& word : allWords) {
		if (usedWords.find(word) == usedWords.end()) {
			cout << word << " ";
		}
	}
	cout << "\n\n";
}

// check if the attempted group is correct
bool GameManager::isCorrectGroup(const vector<string>& attempt) {
	for (const auto& pair : groups) {
		const string& groupName = pair.first;
		const vector<string>& words = pair.second;
		set<string> attemptSet(attempt.begin(), attempt.end());
		set<string> correctSet(words.begin(), words.end());
		if (attemptSet == correctSet && solvedGroups.find(groupName) == solvedGroups.end()) {
			solvedGroups.insert(groupName);
			usedWords.insert(attempt.begin(), attempt.end());
			cout << "Correct! You found the group: " << groupName << "\n\n";
			return true;
		}
	}
	return false;
}

// username setter
void GameManager::setUsername(const string& name) {
	username = name;
}

// log game result to file
void GameManager::logResult(bool won, const string& puzzleFile) {
	ofstream log("log.txt", ios::app);

	log << "Username: " << username << " | Puzzle: " << puzzleFile << " | Result: " << (won ? "Won" : "Lost") << "\n";

	log.close();
}

// main gameplay loop
void GameManager::run(const string& puzzleFile) {
	cout << "Welcome to the Connections Game!\n";

	while (solvedGroups.size() < 4 && lives > 0) {
		printWords();

		cout << "Enter 4 words separated by commas (or type 'exit' to quit): ";
		string input, word;
		getline(cin, input);
		stringstream ss(input);
		vector<string> guess;

		// tokenize input into words
		while (getline(ss, word, ',')) {
			word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
			if (!word.empty()) {
				guess.push_back(word);
			}
		}

		if (guess.size() != 4) {
			cout << "Please enter exactly 4 words.\n\n";
			continue;
		}

		// check for correct group
		if (!isCorrectGroup(guess)) {
			lives--;
			cout << "Incorrect group. Attempts left: " << lives << "\n\n";
		}

	}

	// final result messages
	if (solvedGroups.size() == 4) {
		cout << "Congratulations! You've solved all groups!\n";
		logResult(true, "puzzleFile");
	}
	else {
		cout << "Game Over! Better luck next time.\n";
		logResult(false, "puzzleFile");
	}
}