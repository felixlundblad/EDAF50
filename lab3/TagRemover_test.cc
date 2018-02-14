#include <iostream>
#include <fstream>
#include <sstream>
#include "TagRemover.h"

using namespace std;

int main()
{
    string removedTags ("This is a line without a tag\nThis is <tag tag> a line with one tag\nAnd this <tag> line has two tags <...>\nA line with a starting tag < ..... continues\n... we're still in a tag ...\n... finishes> which finished on this line <last tag>\nSpecial chars: &lt;&gt;&nbsp;&amp;\n");
    ifstream inputFile("test.html");
    if (inputFile)
    {
        stringstream ss;
        ss << inputFile.rdbuf();
        inputFile.close();
        TagRemover tr(ss);
        if (ss.str() == removedTags){
            //tr.print(ss);
        }
        else{
            cout << "Tags were not removed correctly" << endl << "Correct text is: " << endl;
            cout << removedTags << endl;
            cout << "Automatically removed tags generated: " << endl;
            tr.print(ss);
        }

    }
}