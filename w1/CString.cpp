#include <iostream>
#include "CString.h"

static int c = 0;

w1::CString::CString(const char *string)
{
    int i = 0;
    while (i < MAX && string[i] != '\0') {
        m_string[i] = string[i];
        i++;
    }
    m_string[i] = '\0';
}

void w1::CString::display(std::ostream &ostream) const
{
    int i = 0;
    while (m_string[i] != '\0') {
        ostream << m_string[i++];
    }
}

std::ostream &w1::operator<<(std::ostream &ostream, const CString &cstring)
{
    ostream << c++ << ": ";
    cstring.display(ostream);
    return ostream;
}