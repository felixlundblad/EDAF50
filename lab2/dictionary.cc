#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using std::unordered_set;

using namespace std;

Dictionary::Dictionary() {
	Dictionary::loadWords(ifstream ("words.txt"));
}

void Dictionary::loadWords(ifstream inputFile){
	string word;
	string temp;
	while(inputFile >> word){
		vector<string> trigrams;
		int amountOfTrigrams;
		cin >> amountOfTrigrams;
		for (int i = 0; i <= amountOfTrigrams; ++i){
			cin >> temp;
			trigrams.push_back(temp);
		}
		Dictionary::set.insert(Word (word, trigrams));
	 	getline(inputFile, temp);
	}
}

bool Dictionary::contains(const string& word) const {
	return Dictionary::set.find(word) != Dictionary::set.end(); // Find returnerar en iterator
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;

	return suggestions;
}
