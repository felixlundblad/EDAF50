#include "palindrome.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a word to check if it is a palindrome: " << endl;
    string str;
    cin >> str;
    cout << "Word entered: " << str << endl << "Is is a palindrome?" << endl;

    Palindrome pal(str);
    if (pal.isPalindrome())
        cout << "Yepp" << endl;
    else
        cout << "Nope" << endl;
    return 0;
}