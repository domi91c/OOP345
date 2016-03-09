// ItemOrder.cpp
// Larissa Voigt

#include "ItemOrder.h"
#include "Utilities.h"
#include <iomanip>

// default constructor
ItemOrder::ItemOrder(const std::string& n) {
  name = n;
  filled = false;
  code = 0;
}

// returns true if the current order asks for item; false otherwise
bool ItemOrder::asksFor(const Item& item) const {
    return false;
}

// returns true if the current order has been filled
bool ItemOrder::isFilled() const {
    return filled;
}

// sets the item code for the current object to the value received and switches
// the status of the current object to filled
void ItemOrder::fill(const unsigned int c) {
    filled = true;
    code = c;
}

// resets the item code for the current object to 0 and resets the status of
// the current object to not filled
void ItemOrder::clear() {
    filled = false;
    code = 0;
}

// returns ordered item name
const std::string& ItemOrder::getName() const {
    return name;
}

// describe item order
void ItemOrder::display(std::ostream& os) const {
    if (name.size() > 0) {
        // symbol + or - identifying the status of the item order
        os << " " << (filled ? "+" : "-");
        // he code printed on the item if filled or 0 if not filled in a field
        // width of CODE_WIDTH padded with 0s and enclosed within brackets
        os << " [" << std::right << std::setw(CODE_WIDTH) << std::setfill('0')
          << code << std::setfill(' ') << "] ";
        // the name of the ordered item
        os << name << std::endl;
    }
}
