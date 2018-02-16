#include <iostream>
#include <sstream>
#include <stdexcept>
#include "date.h"
#include "FunctionTemplate.h"

using namespace std;

template <class T>
T string_cast(string s)
{
    istringstream ss(s);
    T obj;
    ss >> obj;
    if (ss.fail())
    {
        throw invalid_argument("Invalid argument");
    }
    return obj;
}

int main()
{
    try
    {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.34");
        Date date = string_cast<Date>("2015-01-10");
        cout << i << endl
             << d << endl
             << date << endl;
    }
    catch (std::invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}