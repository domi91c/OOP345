/*
 * OOP345 - Workshop 2
 * Author: Larissa Voigt
 * Student Number: 024769143
 * Date: September 28, 2015
 */

#include <string>
#include <fstream>
#include "Station.h"

namespace w2 {

  Station::Station() {
    stationName = "";
    stationPasses[STUDENT_PASS] = 0;
    stationPasses[ADULT_PASS] = 0;
  }

  Station::Station(std::fstream& fs) {
    std::string name;
    std::getline(fs, name, ';');
    int s, a;
    char c;
    fs >> s;
    fs >> a;
    fs.get(c);
    if (c != '\n') {
      std::cerr << "expected a ->>\\n<<- and found a ->>" << c << "<<-\n";
      exit(1);
    }
    set(name, s, a);
  }

  void Station::set(const std::string& name, unsigned student, unsigned adult) {
    stationName = name;
    stationPasses[STUDENT_PASS] = student;
    stationPasses[ADULT_PASS] = adult;
  }

  void Station::update(PassType pt, int number) {
    stationPasses[pt] += number;
  }

  unsigned Station::inStock(PassType pt) const {
    return stationPasses[pt];
  }

  const std::string& Station::getName() const {
    return stationName;
  }
}
