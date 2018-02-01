#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    cout << "What file would you like to decrypt? \n";
    string encryptedFile;
    cin >> encryptedFile;

    cout << "What would you like to name the decrypted file? \n";
    string decryptedFile;
    cin >> decryptedFile;

    string line;
    char letter;
    ifstream inputFile (encryptedFile);
    ofstream outputFile (decryptedFile);
    if(inputFile.is_open() && outputFile.is_open()){
        for(int i = 0; !inputFile.eof(); i++){
            inputFile.get(letter);
            char temp = letter - '!';
            outputFile.put(temp);
            cout << temp;
        }
    }else{
        std::cout << "Unable to open at least one of the files" << std::endl;
        return -1;
    }
    return 0;
}