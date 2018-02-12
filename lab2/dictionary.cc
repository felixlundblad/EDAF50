#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using std::stringstream;

using namespace std;

Dictionary::Dictionary()
{
	cout << "Entry Dictionary: " <<  << endl;
	Dictionary::loadWords(ifstream("words.txt"));
	cout << "Exit Dictionary" << endl;
}
void Dictionary::loadWords(ifstream inputFile)
{
	string line;
	
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
			string t = "test";
			Word test = Word(t, vector<string> {"1","2"});
			Word w = Word(tokens.at(0), trigrams);
			//Word w2 = Word(tokens.at(0), trigrams);
			words[length].push_back(w);
		}
	}else {
		cout << "Unable to open file";
	}
}

void Dictionary::inefficientLoadWords(ifstream inputFile)
{
	string word;
	string temp;
	int amountOfTrigrams;
	while (inputFile >> word)
	{
		vector<string> trigrams;
		inputFile >> amountOfTrigrams;
		for (int i = 0; i <= amountOfTrigrams; ++i)
		{
			inputFile >> temp;
			trigrams.push_back(temp);
		}
		words[word.length()].push_back(Word(word, trigrams));
		getline(inputFile, temp);
	}
}


bool Dictionary::contains(const string &word) const
{
	cout << "Checking correctness" << endl;
	auto it = words[word.length()].begin();
	cout << it -> get_word() << endl;
	while (it != words[word.length()].end())
	{
		if (it -> get_word() == word)
			return true;
		++it;
	}
	return false;
	//return Dictionary::set.find(word) != Dictionary::set.end(); // Find returnerar en iterator
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	vector<string> suggestions;

	return suggestions;
}
