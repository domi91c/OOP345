/*
 * OOP345 - Workshop 1
 * Author: Larissa Voigt
 * Student Number: 024769143
 * Date: September 21, 2015
 */

#include "process.h"
#include "CString.h"
#include <iostream>

void process(char* parm) {
  w1::CString cs(parm);
  std::cout << cs;
  std::cout << "\n";
}
