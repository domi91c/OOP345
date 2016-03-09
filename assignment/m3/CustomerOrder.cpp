// CustomerOrder.cpp
// Larissa Voigt

#include "CustomerOrder.h"
#include "Item.h"
#include "ItemOrder.h"
#include "Utilities.h"
#include <iomanip>
#include <vector>

char CustomerOrder::delimiter = '|';
size_t CustomerOrder::field_width = 1;

// default constructor
CustomerOrder::CustomerOrder(const std::string& record) {
  size_t pos = 0;
  bool more = true;
  name = "";
  product = "";
  order = nullptr;
  nOrders = 0;

  Utilities u(field_width);
  name = u.nextToken(record, pos, more);
  if (!name.empty()) {
    if (more) {
      product = u.nextToken(record, pos, more);
    }
    std::vector<std::string> v;
    while(more) {
      std::string t = u.nextToken(record, pos, more);
      if (t.size() > 0) {
        v.push_back(t);
      }
    }
    nOrders = v.size();
    order = new ItemOrder[nOrders];
    for (int i = 0; i < nOrders; i++) {
      order[i] = ItemOrder(v[i]);
    }
    field_width = u.getFieldWidth();
  }
}

// copy ctor
CustomerOrder::CustomerOrder(const CustomerOrder& src) {
  throw std::string("Copy Constructor");
  name = src.name;
  product = src.product;
  nOrders = src.nOrders;

  if (src.order) {
    order = new ItemOrder[nOrders];
    for (int i = 0; i < nOrders; i++) {
      order[i] = src.order[i];
    }
  } else {
    order = nullptr;
  }
}

// move ctor
CustomerOrder::CustomerOrder(CustomerOrder&& src) {
  order = nullptr;
  *this = std::move(src);
}

// move assignment operator
CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& src) {
  if (this != &src) {
    if (order) {
      delete [] order;
    }
    name = src.name;
    product = src.product;
    nOrders = src.nOrders;
    order = src.order;

    src.name.clear();
    src.product.clear();
    src.nOrders = 0;
    src.order = nullptr;
  }

  return std::move(*this);
}

// deconstructor
CustomerOrder::~CustomerOrder() {
  if (order) {
    delete [] order;
  }
}

// returns the number of item orders in the current object
unsigned int CustomerOrder::noOrders() const {
  return nOrders;
}

// returns a reference to the name of item order i
const std::string& CustomerOrder::operator[](unsigned int i) const {
  if (i >= nOrders) {
    throw std::string("Index is out of bounds");
  }

  return order[i].getName();
}

// searches through the ordered items and fills those orders identified by the
// name of the Item received if any have not been filled
void CustomerOrder::fill(Item& item) {
  for (int i = 0; i < nOrders; i++) {
    if (!order[i].getName().compare(item.getName())) {
      order[i].fill(item.getCode());
      // increments the Item object's code for each order filled
      item++;
    }
  }
}

// searches through the items ordered and removes those items identified by the
// name of the Item received if the corresponding order has been filled
void CustomerOrder::remove(Item& item) {
  for (int i = 0; i < nOrders; i++) {
    if (!order[i].getName().compare(item.getName())) {
      order[i].clear();
    }
  }
}

// returns true if the current object is in a safe empty state
bool CustomerOrder::empty() const {
  return name.empty();
}

// description of customer order
void CustomerOrder::display(std::ostream& os) const {
  os << std::left;
  // the name of the customer left-justified in a field of width field_width
  os << std::setw(field_width) << name << " : ";
  // the name of the product left-justified in a field of width field_width
  os << std::setw(field_width) << product;
  // each item ordered on a separate line
  os << std::endl;

  for (unsigned int i = 0; i < nOrders; i++) {
    order[i].display(os);
  }
}

// resets the delimiter for extracting tokens to the character received
void CustomerOrder::setDelimiter(const char c) {
  delimiter = c;
}
