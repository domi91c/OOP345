// ItemManager.cpp
// Larissa Voigt

#include <vector>
#include "Item.h"
#include "ItemManager.h"

// moves item to the back of items
void ItemManager::push_back(Item&& item) {
  items.push_back(std::move(item));
}

// returns the iterator to the beginning of items
std::vector<Item>::iterator ItemManager::begin() {
  return items.begin();
}

// returns the iterator to the end of items
std::vector<Item>::iterator ItemManager::end() {
  return items.end();
}

// returns the iterator to the beginning of read-only items
const std::vector<Item>::const_iterator ItemManager::cbegin() const {
  return items.cbegin();
}

// returns the iterator to the end of read-only items
const std::vector<Item>::const_iterator ItemManager::cend() const {
  return items.cend();
}

// inserts into the referenced ostream object descriptions of the items stored
// in items
void ItemManager::display(std::ostream& os, bool full) const {
  for (size_t s = 0; s < items.size(); s++) {
    items[s].display(os, full);
  }
}
