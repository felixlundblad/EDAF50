#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	static const int MAX_WORD_LENGTH {25};
private:
	//std::unordered_set<Word> set;
	std::vector<Word> words[MAX_WORD_LENGTH + 1];
	void loadWords(std::ifstream inputFile);
	void inefficientLoadWords(std::ifstream inputFile);
};

#endif
