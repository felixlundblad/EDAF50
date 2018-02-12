#include <string>
#include <vector>
#include "word.h"

using std::string;
using std::vector;

Word::Word(const string &w, const vector<string> &t) : str(w), trigrams(t) {}

string Word::get_word() const
{
	return str;
}

unsigned int Word::get_matches(const vector<string> &t) const
{
	int matches = 0;
	auto it_t = t.begin();
	auto it_trigrams = trigrams.begin();
	while (it_t != t.end())
	{
		while (it_trigrams != trigrams.end())
		{
			if (*it_t < *it_trigrams)
				break;
			else if (*it_t == *it_trigrams)
			{
				++matches;
				++it_trigrams;
				break;
			}

			it_trigrams++;
		}
		it_t++;
	}
	return matches;
}
