#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string line;
    string trigram;
    ifstream inputFile("/Users/carltidelius/Downloads/EDAF50/lab2/words");
    ofstream outputFile("words.txt");
    while (getline(inputFile, line))
    {
        vector<string> trigramVect;
        if (line.length() < 3)
        {

            for(int i = 0; i < line.length(); i++)
                outputFile << static_cast<char>(tolower(line.at(i)));
            outputFile << " " << 0;
        }
        else
        {
            for(int i = 0; i < line.length(); i++)
                outputFile << static_cast<char>(tolower(line.at(i)));
            outputFile << " " << line.length() - 2 << " ";
            for (int j = 0; j < line.length() - 2; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    trigram.append(1, static_cast<char>(tolower(line.at(j + i))));
                }
                trigramVect.push_back(trigram);
                trigram.clear(); // Kan nog effektiviseras rejält så man slipper bygga om hela stringen
            }
        }
        sort(trigramVect.begin(), trigramVect.end());
        for(int i = 0; i < trigramVect.size(); i++){
            outputFile << trigramVect[i] << " ";
        }
        outputFile << '\n';
    }
    return 0;
}