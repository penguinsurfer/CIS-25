#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

// class for game logic
class GameManager {
private:
	std::map<std::string, std::vector<std::string>> groups; 
	std::vector<std::string> allWords;
	std::set<std::string> solvedGroups;
	std::set<std::string> usedWords; 
	std::string username;
	int lives;

public:
	GameManager();

	bool loadPuzzle(const std::string& filename);
	void run(const std::string& puzzleFile);
	void printWords();
	bool isCorrectGroup(const std::vector<std::string>& attempt);
	void setUsername(const std::string& name);
	void logResult(bool won, const std::string& puzzleFile);
};

#endif