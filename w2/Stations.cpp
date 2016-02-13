/*
 * OOP345 - Workshop 2
 * Author: Larissa Voigt
 * Student Number: 024769143
 * Date: September 28, 2015
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include "Stations.h"

namespace w2 {

  Stations::Stations (char* name) {
    filename = name;
    std::cout << "Stations(" << name << ")" << std::endl;
    std::fstream fs(filename);
    if (fs.is_open()) {
      fs >> stationsCount;
      std::cout << "Total Stations " << stationsCount << std::endl;
      char c;
      fs.get(c);
      if (c != ';') {
        std::cerr << "expected a ->>;<<- and found a ->>" << c << "<<-\n";
        exit(1);
      }
      fs.get(c);
      if (c != '\n') {
        std::cerr << "expected a ->>\\n<<- and found a ->>" << c << "<<-\n";
        exit(1);
      }
      stationsTable = new Station[stationsCount];
      for (int i = 0; i < stationsCount; i++) {
        stationsTable[i] = Station(fs);
      }
      fs.close();
    }
  }

  Stations::~Stations() {
    std::ofstream fs(filename);
    if (fs.is_open()) {
      fs << stationsCount << ";" << std::endl;
      for (int i = 0; i < stationsCount; i++) {
        fs << stationsTable[i].getName() << ";"
           << stationsTable[i].inStock(STUDENT_PASS) << " "
           << stationsTable[i].inStock(ADULT_PASS) << std::endl;
      }
    }
    if (stationsTable) {
      delete []stationsTable;
      stationsTable = nullptr;
    }
  }

  void Stations::update() const {
    std::cout << "Passes in Sold :\n";
    std::cout << "---------------:\n";
    for (int i = 0; i < stationsCount; i++) {
      int student, adult;
      std::cout << stationsTable[i].getName() << "\n";
      std::cout << "Student Passes sold : ";
      std::cin >> student;
      std::cout << "Adult Passes sold : ";
      std::cin >> adult;
      stationsTable[i].update(STUDENT_PASS, -student);
      stationsTable[i].update(ADULT_PASS, -adult);
    }
  }

  void Stations::restock() const {
    std::cout << "Passes in Added :\n";
    std::cout << "---------------:\n";
    for (int i = 0; i < stationsCount; i++) {
      int student, adult;
      std::cout << stationsTable[i].getName() << "\n";
      std::cout << "Student Passes added : ";
      std::cin >> student;
      std::cout << "Adult Passes added : ";
      std::cin >> adult;
      stationsTable[i].update(STUDENT_PASS, student);
      stationsTable[i].update(ADULT_PASS, adult);
    }
  }

  void Stations::report() const {
    std::cout << "Passes in Stock : Student Adult\n";
    std::cout << "-------------------------------\n";
    for (int i = 0; i < stationsCount; i++) {
      std::cout << std::left << std::setw(19) << stationsTable[i].getName();
      std::cout << std::setw(6) << stationsTable[i].inStock(STUDENT_PASS);
      std::cout << std::setw(6) << stationsTable[i].inStock(ADULT_PASS);
      std::cout << "\n";
    }
  }
}

