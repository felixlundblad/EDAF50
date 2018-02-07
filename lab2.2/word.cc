#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t): str(w), trigrams(t) {}

string Word::get_word() const {
	return str;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int matches = 0;
	auto it_t = t.begin();
	while (it_t != t.end()){
		auto it_trigrams = trigrams.begin();
		while(it_trigrams != trigrams.end()){
			if (*it_t == *it_trigrams){
				++matches;
				break;
			}else if (*it_t < *it_trigrams){
				break;
			}
			it_trigrams++;
		}
		it_t++;
	}
	return matches;
}
