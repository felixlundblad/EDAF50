#include "TagRemover.h"
#include <sstream>
#include <iostream>

using namespace std;

TagRemover::TagRemover(std::stringstream &ss)
{
    string buffer;
    buffer = ss.str();
    for (uint i = 0; i < buffer.size(); i++)
    {
        if (buffer.at(i) == '<')
        {
            bool newLine = false;
            int tagLength(2);
            while(buffer.at(i + tagLength - 1) != '>'){
                ++tagLength;
                if(buffer.at(i + tagLength - 1) == '\n'){
                    newLine = true;
                }
            }
            buffer.erase(i, tagLength);
            if(buffer.at(i) == ' ') buffer.erase(i, 1);
            if(newLine) buffer.insert(i, 1, '\n');
        }
        
        if(buffer.at(i) == '&'){
            string temp;
            temp = buffer.at(i);
            int j = 1;
        
            while(buffer.at(i+j-1) != ';'){
                temp.push_back(buffer.at(i+j));
                ++j;
            }

            if(temp == "&lt;"){
                buffer.erase(i, 4);
                buffer.insert(i, "<");
            }else if(temp == "&gt;"){
                buffer.erase(i, 4);
                buffer.insert(i, ">");
            }else if(temp == "&nbsp;"){
                buffer.erase(i, 6);
                buffer.insert(i, " ");
            }else if(temp == "&amp;"){
                buffer.erase(i, 5);
                buffer.insert(i, "&");
            }
        }
    }
    ss.clear();
    ss.str(buffer);
}

void TagRemover::print(const std::stringstream &ss)
{
    cout << ss.str();
}