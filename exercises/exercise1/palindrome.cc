#include <iostream>
#include <string>

#include "palindrome.h"

using namespace std;

std::string str;

Palindrome::Palindrome(string s)
{
    str = s;
}

bool Palindrome::isPalindrome()
{
    for(int i = 0; i < str.length(); ++i){
        if(str[i - 1] != str[str.length() - i]) return false;
    }
    return true;
}