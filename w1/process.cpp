//
// Created by Dominic Nunes on 2017-09-22.
//

#include <iostream>
#include "process.h"
#include "CString.h"

using namespace w1;

void process(const char *string)
{
    CString cString(string);
    std::cout << cString << std::endl;
}
