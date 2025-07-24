#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

class GameManager {
private:
	std::map<std::string, std::vector<std::string>> groups;
	std::vector<std::string> allWords;
	std::set<std::string> solvedGroups;
	std::set<std::string> usedWords;
	int lives;

public:
	GameManager();

	bool loadPuzzle(const std::string& filename);
	void run();
	void printWords();
	bool isCorrectGroup(const std::vector<std::string>& attempt);
};

#endif