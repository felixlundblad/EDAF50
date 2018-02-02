#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    char c;
    ifstream inputFile("/home/felix/Skrivbord/words");
    ofstream outputFile("words.txt");
    while (getline(inputFile, line))
    {
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
            outputFile << " ";
            outputFile << line.length() - 2;
            outputFile << " ";
            for (int j = 0; j < line.length() - 2; j++)
            {
                for (int i = 0; i < 3; i++)
                {

                    outputFile << static_cast<char>(tolower(line.at(j + i)));
                }
                outputFile << " ";
            }
        }
        outputFile << '\n';
    }
    return 0;
}