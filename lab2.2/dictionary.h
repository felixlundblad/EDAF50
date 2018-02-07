#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

using std::string;
using std::vector;


class Dictionary {
public:
	Dictionary();
	bool contains(const string& word) const;
	vector<string> get_suggestions(const string& word) const;


private:
	vector<Word> dict[25];
	void add_trigram_suggestions(vector<string>& suggestions, const string& word) const;
	vector<string> create_trigrams(const string& line) const;
	void rank_suggestions(vector<string>& suggestions, const string& word) const;
	void trim_suggestions(vector<std::string>& suggestions) const;
};

#endif
