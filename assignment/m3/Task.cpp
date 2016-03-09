// Task.cpp
// Larissa Voigt

#include "Task.h"
#include "Utilities.h"
#include <iomanip>
#define MAX_WIDTH size_t(20)

char Task::delimiter = '|';
size_t Task::field_width = 1;

/* initializes the number of slots to a default value of 1 and the pointers
   to the next tasks to safe addresses */
Task::Task(const std::string& record) : name(""), slots("1") {

  size_t position = 0;
  bool more = true;

  nextTask[passed] = "";
  nextTask[redirect] = "";
  pNextTask[passed] = nullptr;
  pNextTask[redirect] = nullptr;

  // object uses a Utilities constructor to extract each token from the record
  Utilities u(field_width);
  name = u.nextToken(record, position, more);

  if (!name.empty()) {
    if (more) slots = u.nextToken(record, position, more);
    if (more) nextTask[passed] = u.nextToken(record, position, more);
    if (more) nextTask[redirect] = u.nextToken(record, position, more);
    if (u.getFieldWidth() < MAX_WIDTH) {
      // resets the class field width to the value retrieved
      field_width = u.getFieldWidth();
    }
  }
}

// return task name
const std::string& Task::getName() const {
  return name;
}

// return number of product slots in task - convert string to int
unsigned int Task::getSlots() const {
  return std::stoi(slots);
}

/* compares the Task referenced in its parameter to the next tasks stored upon
 * instantiation.  If one of these tasks has the same name as that referenced,
 * this function sets the corresponding pointer to the address of the referenced
 * task */
bool Task::validate(const Task& task) {
  if (!pNextTask[passed] && !nextTask[passed].compare(task.name)) {
    pNextTask[passed] = &task;
  }

  if (!pNextTask[redirect] && !nextTask[redirect].compare(task.name)) {
    pNextTask[redirect] = &task;
  }

  return (nextTask[passed].empty() || pNextTask[passed]) &&
    (nextTask[redirect].empty() || pNextTask[redirect]);
}

/* comparing the Task referenced in its parameter to the next tasks stored upon
 *  instantiation.  If one of these tasks has the same name as that referenced,
 *  this function sets the corresponding pointer to the address of the referenced
 *  task */
const Task* Task::getNextTask(Quality quality) const {
  if (!pNextTask[quality]) {
    throw std::string("*** Validate  [") + nextTask[quality] + std::string("] @ [") + name + std::string("] ***");
  }

  return pNextTask[quality];
}

// inserts into the referenced ostream object a full description of the task
void Task::display(std::ostream& os) const {
  size_t fws = field_width + 2;

  std::string tName("[");
  tName += getName();
  tName += "]";

  std::string p;
  std::string r;

  if(!nextTask[passed].empty()) {
    p =  "[";
    p += nextTask[passed];
    p += "]";
  }

  if(!nextTask[redirect].empty()) {
    r =  "[";
    r += nextTask[redirect];
    r += "]";
  }

  os << "Task Name    : " << std::setw(fws) << std::left << tName
    << " [" << getSlots() << "]";
  if(!nextTask[passed].empty()) {
    os << std::endl;
    os << " Continue to : " << std::setw(fws) << std::left << p;
    if(pNextTask[passed] == nullptr) {
      os << " *** to be validated ***";
    }
  }

  if(!nextTask[redirect].empty()) {
    os << std::endl << " Redirect to : " << std::setw(fws) <<
      std::left << r;
    if(pNextTask[redirect] == nullptr) {
      os << " *** to be validated ***" << std::endl;
    } else {
      os << std::endl;
    }
  } else {
    os << std::endl;
  }
}

// reset the delimiter for all objects in this class to the character received
void Task::setDelimiter(const char d) {
  delimiter = d;
}

// returns the field width for all objects in this class
size_t Task::getFieldWidth() {
  return field_width;
}

// returns true if the tasks referenced in its parameters have the same name
bool operator==(const Task& a, const Task& b ) {
  bool comp;

  if (a.getName() == b.getName()) {
    comp = true;
  } else {
    comp = false;
  }

  return comp;
}
