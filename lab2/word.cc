#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

string word;
vector<string> trigrams;

Word::Word(const string& w, const vector<string>& t) {
	word = w;
	trigrams = t;
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int matches = 0;
	vector<string> temp(t);
	auto thisIt = trigrams.begin();
	while(thisIt != trigrams.end()){
		auto localIt = temp.begin();
		while(localIt != temp.end()){
			if(*localIt > *thisIt) break; // "Effektiv kod"
			if(*localIt == *thisIt){
				matches++;
				temp.erase(localIt);
				break;
			}
			++localIt;
		}
	}
	return matches;
}
