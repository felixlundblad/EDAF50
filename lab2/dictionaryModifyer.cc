#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    string line;
    char c;
    ifstream inputFile("/home/felix/Skrivbord/words");
    ofstream outputFile("words.txt");
    //if(inputFile.is_open() && outputFile.is_open()){
    while (getline(inputFile, line))
    {
        //cout << line << line.length() << endl;
        if (line.length() < 3)
        {
            outputFile << line << " " << 0;
        }
        else
        {
            outputFile << line;
            outputFile << " "; 
            outputFile << line.length() - 2;
            outputFile << " ";
            for (int j = 0; j < line.length() - 2; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    outputFile << line.at(j + i);
                }
                outputFile << " ";
            }
        }
        outputFile << '\n';
    }
    /*}else{
        std::cout << "Unable to open at least one of the files" << std::endl;
        return -1;
    }*/
    return 0;
}