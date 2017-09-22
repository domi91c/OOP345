//
// Created by Dominic Nunes on 2017-09-12.
//

#include <iostream>

#ifndef W1_CSTRING_H
#define W1_CSTRING_H
#define MAX 3

namespace w1
{
class CString
{
private:
    char m_string[MAX + 1];

public:
    explicit CString(const char *string);

    void display(std::ostream &ostream) const;

};

std::ostream &operator<<(std::ostream &ostream, const CString &cstring);
}

#endif //W1_CSTRING_H
