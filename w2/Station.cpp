/*
 * OOP345 - Workshop 2
 * Author: Larissa Voigt
 * Student Number: 024769143
 * Date: September 28, 2015
 */

#include <string>
#include <iostream>

namespace w2 {

  Station::Station() {
    std::string name;
    getline(fs, name, ';');
    int s, a;
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
    stationPasses[ADULT_PASS] = adult;
    stationPAsses[STUDENT_PASS] = student;
  }

  void Station::update(PassType, int) {
    stationPasses[pt] += number;
  }

  unsigned Station::inStock(PassType) const {
    return stationPasses[pt];
  }

  const Station::std::string& getName() const {
    return stationName;
  }
}
