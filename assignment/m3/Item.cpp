// Item.cpp
// Larissa Voigt

#include "Item.h"
#include "Utilities.h"
#include <iomanip>

char Item::delimiter = '|';
size_t Item::field_width = 1;

// default constructor
Item::Item(const std::string& record) {
    size_t pos = 0;
    bool more = true;
    name = "";
    source = "";
    destination = "";
    details = "no detailed description";
    code = 1;

    Utilities u(field_width);
    name = u.nextToken(record, pos, more);
    if (!name.empty()) {
        if (more) {
            source = u.nextToken(record, pos, more);
        }
        field_width = u.getFieldWidth();

        if (more) destination = u.nextToken(record, pos, more);
        if (more) code = std::stoi(u.nextToken(record, pos, more));
        if (more) details = u.nextToken(record, pos, more);
        if (details.empty()) {
            details = "no detailed description";
        }
    }
}

// returns true if the current object is in a safe empty state
bool Item::empty() const {
    return name.empty();
}

// increments the code to be printed on the next insertion by 1
void Item::operator++(int i) {
    code++;
}

// returns a copy of the string that contains the name of the item
const std::string& Item::getName() const {
    return name;
}

// returns a copy of the string that contains the name of the task that inserts
// the item into a product
const std::string& Item::getSource() const {
    return source;
}

// returns a copy of the string that contains the name of the task that extracts
// the item from a product
const std::string& Item::getDestination() const {
    return destination;
}

// returns a copy of the code to be printed on the next insertion
unsigned int Item::getCode() const {
    return code;
}

// describe the item
void Item::display(std::ostream& os, bool full) const {
    // the name of the item left-justified in a field of field_width characters
    os << std::left << std::setw(field_width) << name;
    // the code right-justified and 0 filled in a field of CODE_WIDTH characters
    // and enclosed within brackets
    os << " [" << std::right << std::setw(CODE_WIDTH) << std::setfill('0') << code << "]";
    os << std::left << std::setfill(' ');

    // if the full flag is true, this function completes the description of the
    // item
    if (full) {
        // the name of the source task left-justified in a field of width
        // field_width and preceded by "From "
        os << " From " << std::setw(field_width) << source;
        // the name of the destination task left-justified in a field of width
        // field_width and preceded by "To "
        os << " To " << std::setw(field_width) << destination << std::endl;
        // the detailed description of the item left-justified and starting
        // directly below From and preceded by ": "
        os << std::right << std::setw(field_width + CODE_WIDTH + 4) << " : " << details;
    }
    os << std::left << std::endl;
}

// reset the delimiter for all Itemobjects to the character received
void Item::setDelimiter(const char c) {
    delimiter = c;
}

// returns the field_width for all Item objects processed
size_t Item::getFieldWidth() {
    return field_width;
}
