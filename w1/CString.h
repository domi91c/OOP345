/*
 * OOP345 - Workshop 1
 * Author: Larissa Voigt
 * Student Number: 024769143
 * Date: September 21, 2015
 */

#pragma once
#include <iostream>

namespace w1 {

  const int MAX = 3;

  class CString {
    private:
      char str[MAX + 1];
    public:
      CString(char* parm);
      void display(std::ostream& os);
  };

  std::ostream& operator<<(std::ostream& os, CString cs);

}

