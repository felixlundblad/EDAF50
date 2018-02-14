#ifndef TAGREMOVER
#define TAGREMOVER

#include <sstream>

using namespace std;

class TagRemover{
public:
    TagRemover(stringstream &ss);
    void print(const stringstream &ss);
protected:
private:
};

#endif