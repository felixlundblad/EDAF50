#include <ifstream>
//#include <iostream>
#include <sstream>
#include "TagRemover.h"

using namespace std;

int main()
{
    stringstream ss();
    iostream inputFile("test.html");
    while (!inputFile.eof())
        ss(inputFile.getline());
    TagRemover tr(ss);    // read from cin
    tr.print(ss); // print on cout
}