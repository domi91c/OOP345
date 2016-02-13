/*
 * OOP345 - Workshop 2
 * Author: Larissa Voigt
 * Student Number: 024769143
 * Date: September 28, 2015
 */

#include "Station.h"

namespace w2 {
  class Stations {
    private:
      int stationsCount;
      Station *stationsTable;
      char* filename;
    public:
      Stations ();
      Stations (char* filename);
      ~Stations();
      void update() const;
      void restock() const;
      void report() const;
  };
}
