#ifndef _GRADES_H_
#define _GRADES_H_
#include <iostream>
#include <string>
#include <stdint.h>
#include <fstream>

class Grades{
  private:
    std::string* studentNo;
    double* mark;
    int counter;
  public:
    Grades():studentNo(nullptr),mark(nullptr),counter(0){}
    Grades(char* fileName){
      try{
        std::ifstream f(fileName);
        if(!f)
          throw "File can not be opened ";
        if(f.is_open()){
          std::string temp_str;
          int temp_counter = 0;

          while(getline(f, temp_str))
            temp_counter++;
          f.clear();
          f.seekg(0);
          counter=temp_counter;
          studentNo = new std::string[counter];
          mark = new double[counter];
          for(int i=0;i<counter;i++){
            f >> studentNo[i] ;
            f >> mark[i];
          }
          f.close();
        }
      }
catch(std::ifstream::failure fa){
  std::cerr <<"File can not be opened";
}
}

template<typename Func>
void displayGrades(std::ostream& os,Func func) const{
  for(int i = 0 ; i<counter;i++){
    os <<studentNo[i]<<" "<<mark[i]<<" "<<func(mark[i])<<std::endl;
  }
}

};


#endif
