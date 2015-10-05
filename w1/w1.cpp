/*
 * OOP345 - Workshop 1
 * Author: Larissa Voigt
 * Student Number: 024769143
 * Date: September 21, 2015
 */

#include <iostream>
#include <cstring>
#include "process.h"
#include "CString.h"
#define MAX 3

int main(int argc, char* argv[]){

  std::cout << "Command Line :";
  for (int arg = 0; arg < argc; arg++) {
    std::cout << " " << argv[arg];
  }
  std::cout << "\n";

  if (argc == 1){
    std::cout << "Insufficient number of arguments(min 1)" << std::endl;
    return 1;
  }

  std::cout << "Maximum number of characters stored : " << 3 << std::endl;

  for (int arg = 1; arg < argc; arg++)
    process(argv[arg]);
  return 0;
}


