// TaskManager.cpp
// Larissa Voigt

#include <algorithm>
#include "Task.h"
#include "Item.h"
#include "ItemManager.h"
#include "TaskManager.h"

// moves task to the back of tasks
void TaskManager::push_back(Task&& task) {
    tasks.push_back(std::move(task));
}

// returns the iterator to the beginning of tasks
std::vector<Task>::iterator TaskManager::begin() {
    return tasks.begin();
}

// returns the iterator to the end of tasks
std::vector<Task>::iterator TaskManager::end() {
    return tasks.end();
}

// returns the iterator to the end of tasks
const std::vector<Task>::const_iterator TaskManager::cbegin() const {
    return tasks.cbegin();
}

// returns the iterator to the end of read-only tasks
const std::vector<Task>::const_iterator TaskManager::cend() const {
    return tasks.cend();
}

// validates all of the follow on tasks against the tasks stored in tasks
void TaskManager::validate(std::ostream& os) {
    bool valid = true;
    for (auto i = 0u; i < tasks.size() && valid; i++) {
        bool invalid = true;
        for (auto j = 0u; j < tasks.size() && invalid; j++) {
            if (tasks[i].validate(tasks[j])) {
                invalid = false;
            }
        }
        valid = !invalid;
    }
    if (!valid) {
        os << "*** Not all Tasks have been validated ***\n";
    }
}

// inserts into the referenced ostream object descriptions of the tasks stored
// in tasks
void TaskManager::display(std::ostream& os) const {
  for (size_t s = 0; s < tasks.size(); s++) {
    tasks[s].display(os);
  }
}

//  checks that the tasks attached to each item are available, reporting any
//  requested tasks that are unavailable on the ostream object.
void validate(const TaskManager& taskManager, const ItemManager& itemManager, std::ostream& os) {
    for (auto itm = itemManager.cbegin(); itm != itemManager.cend(); itm++) {
        const auto& item = *itm;

        auto available = [&] (const Task& task) {
            return !task.getName().compare(item.getDestination());
        };

        if (std::find_if (taskManager.cbegin(), taskManager.cend(), available) == taskManager.cend()) {
            os << item.getDestination() << " is unavailable\n";
        }
    }
}
