// OrderManager.cpp
// Larissa Voigt

#include <algorithm> // std::find_if
#include "Item.h"
#include "CustomerOrder.h"
#include "ItemManager.h"
#include "OrderManager.h"

// moves customerOrder to the back of customerOrders
void OrderManager::push_back(CustomerOrder&& customerOrder) {
    customerOrders.push_back(std::move(customerOrder));
}

// moves a customerOrder from the back of customerOrders
CustomerOrder&& OrderManager::extract() {
  return std::move(*customerOrders.end());
}

//  pops a customerOrder from the back of customerOrders
void OrderManager::pop() {
  customerOrders.pop_back();
}

// returns true if customerOrders is empty; false otherwise
bool OrderManager::empty() const {
  return customerOrders.empty();
}

// returns the iterator to the beginning of customerOrders
std::vector<CustomerOrder>::iterator OrderManager::begin() {
    return customerOrders.begin();
}

// returns the iterator to the end of customerOrders
std::vector<CustomerOrder>::iterator OrderManager::end() {
    return customerOrders.end();
}

// returns the iterator to the beginning of read-only customerOrders
const std::vector<CustomerOrder>::const_iterator OrderManager::cbegin() const {
    return customerOrders.cbegin();
}

// returns the iterator to the end of read-only customerOrders
const std::vector<CustomerOrder>::const_iterator OrderManager::cend() const {
    return customerOrders.cend();
}

// inserts into the referenced ostream object descriptions of the customer
// orders stored in customerOrders
void OrderManager::display(std::ostream& os) const {
  for (size_t s = 0; s < customerOrders.size(); s++) {
    customerOrders[s].display(os);
  }
}

// checks that the items in the customer orders are available, reporting any
// requested items that are not available on the ostream object.
void validate(const OrderManager& orderManager, const ItemManager& itemManager,
    std::ostream& os) {
    for (auto itm = orderManager.cbegin(); itm != orderManager.cend(); itm++) {
        const auto& customerOrder = *itm;
        for (int i = 0; i < customerOrder.noOrders(); i++) {
            auto available = [&] (const Item& item) {
                return !item.getName().compare(customerOrder[i]);
            };

            // find_if returns an iterator to the first element in the range
            // [first,last) for which pred returns true. if no such element is
            // found, the function returns last
            if (std::find_if (itemManager.cbegin(), itemManager.cend(),
                  available) == itemManager.cend()) {
                os << customerOrder[i] << " is unavailable" << std::endl;
            }
        }
    }
}
