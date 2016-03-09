// Utilities.cpp
// Larissa Voigt

#include "Utilities.h"
#include <iostream>

char Utilities::delimiter = '|';

// default constructor
Utilities::Utilities(size_t minimum_field_width) {
  field_width = minimum_field_width;
  }

// resets the field width to fw
void Utilities::setFieldWidth(size_t fw) {
    field_width = fw;
}

// returns the field width
size_t Utilities::getFieldWidth() const {
    return field_width;
}

// receives a reference to string str, a reference to the position (next_pos)
// in this string at which to start extracting the next token, and a reference
// to a boolean flag (more).  This function returns the next token found and
// sets more to true if the function has found more tokens after the extracted
// token; false otherwise.  This function update the field_width data member if
// its current value is less than the size of the token extracted
const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) {
    std::string token = "";
    while (str.size() != next_pos && str[next_pos] != delimiter) {
        token += str[next_pos];
        next_pos++;
    }
    if (str.size() == next_pos) {
        more = false;
    } else {
        more = true;
        next_pos++;
    }
    size_t p = token.find_first_not_of(" \t\r\n");
    token.erase(0, p);

    p = token.find_last_not_of(" \t\r\n");
    if (std::string::npos != p) {
        token.erase(p+1);
    }

    if (field_width < token.size()) {
        field_width = token.size();
    }

    return token;
}

// resets the delimiter for this class to the character received
void Utilities::setDelimiter(const char c) {
    delimiter = c;
}

// returns the delimiter for this class
const char Utilities::getDelimiter() {
    return delimiter;
}
