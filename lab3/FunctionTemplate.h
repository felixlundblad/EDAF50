#ifndef FUNCTIONTEMPLATE_H
#define FUNCTIONTEMPLATE_H

#include <iostream>

class FunctionTemplate{
public:
    template <class T> T string_cast(std::string s);
};

#endif