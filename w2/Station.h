/*
 * OOP345 - Workshop 2
 * Author: Larissa Voigt
 * Student Number: 024769143
 * Date: September 28, 2015
 */

#include <string>
#include <iostream>

namespace w2 {
  enum PassType {ADULT_PASS, STUDENT_PASS, PASS_COUNT};
  class Station {
    private:
      std:::string stationName;
      int stationPasses[PASS_COUNT];
    public:
      Station(); //default constructor
      void set(const std::string&, unsigned, unsigned); //sets the instance variables to the values received in its parameters
      void update(PassType, int); //updates the number of passes - sold if negative, added if positive
      unsigned inStock(PassType) const; //returns the number of passes of the requested type
      const std::string& getName() const; //returns a reference to a string object holding the name of the station
  };
}
