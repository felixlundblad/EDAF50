#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	std::unordered_set<Word> set;
	void loadWords(std::ifstream inputFile);
};

#endif
