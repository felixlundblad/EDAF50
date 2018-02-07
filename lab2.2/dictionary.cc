#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include <sstream>
#include "dictionary.h"
#include <unordered_set>

using std::string;
using std::ifstream;
using std::vector;
using std::cout;
using std::endl;
using std::stringstream;
using std::min;
using std::pair;

Dictionary::Dictionary() {
	string line;
	ifstream inputFile("words.txt");
	
	if (inputFile.is_open()){
		while(getline(inputFile, line)){
			
    		string buf; // Have a buffer string
    		stringstream ss(line); // Insert the string into a stream

    		vector<string> tokens; // Create vector to hold our words

   			while (ss >> buf){
        		tokens.push_back(buf);
			}
			auto it = tokens.begin();
			vector<string> trigrams;
			int length = stoi(tokens.at(1));
			length+=2;
			if (length > 2){
				it++;
				it++;
				while(it != tokens.end()){
					trigrams.push_back(*it);
					it++;
				}
			}
			Word w = Word(tokens.at(0), trigrams);
			dict[length].push_back(w);
		}
	}else {
		cout << "Unable to open file";
	}
}


bool Dictionary::contains(const string& word) const {
	int length = static_cast<int>(word.size());
	auto it = dict[length].begin();
	while(it != dict[length].end()){
		if(it->get_word() == word){
			return true;
		}
		it++;
	}
	return false;

}


vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}
void Dictionary::trim_suggestions(vector<std::string>& suggestions) const {
	if (suggestions.size() > 5){
		suggestions = vector<string>(suggestions.begin(), suggestions.begin() + 5);
	}
}
void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const{
	int word_length = word.length();
	if (word_length < 3){
		return;
	}
	vector< pair<int, string> > distances;
	auto it = suggestions.begin();
	while(it != suggestions.end()){
		int suggestion_length = it->length();
		int d[26][26];
		d[0][0] = 0;
		for (int i = 1; i <= word_length; ++i){
			d[i][0] = i;
		}
		for (int j = 1; j <= suggestion_length; ++j){
			d[0][j] = j;
		}
		for (int i = 1; i <= word_length; ++i) {
			for (int j = 1; j <= suggestion_length; ++j) {
				d[i][j] = min({ d[i-1][j-1] + (word.at(i-1) == it->at(j-1) ? 0 : 1), d[i-1][j] + 1,	d[i][j-1] + 1 });
			}
		}
		distances.push_back(make_pair(d[word_length][suggestion_length], *it));
		it++;
	}
	sort(distances.begin(), distances.end());
	suggestions.clear();
	for (auto s: distances) {
		suggestions.push_back(s.second);
	}
}
void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const{
	int length = static_cast<int>(word.length());
	auto tr = create_trigrams(word);
	for (int i = length - 1; i <= length + 1; i++){
		auto it = dict[i].begin();
		while(it != dict[i].end()){
			if(it->get_matches(tr) >= tr.size()/2 - 1){
				suggestions.push_back(it -> get_word());
			}
			it++;
		}
	}

}
vector<string> Dictionary::create_trigrams(const string& line) const{
	vector<string> trigrams;
	int nbrTrigrams = 0;
	if(line.size() > 2){
		nbrTrigrams = line.size() - 2;
	}else{
		return trigrams;
	}
 	
	for(int i = 0; i < nbrTrigrams; i++) {
    	trigrams.push_back(line.substr(i, 3));
  	}
  	sort(trigrams.begin(), trigrams.end());
  	return trigrams;
}
