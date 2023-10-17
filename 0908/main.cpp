#include"IntArray.h"
#include <algorithm>
#include<iostream>
#include <string>
#include<vector>

void foo(const IntArray arr){}
IntArray bar(){
  IntArray array("bar");
  return array;
}

int main(){
  std::cout << "to check the differences among different constructors\n";
  IntArray arr1("Dadou");//constructor
  IntArray arr2 = arr1;//copy constructor
  IntArray arr3("Gigi");//constructor
  arr3 = arr1;//copy assign
  
  std::cout << "\n-----------------------------------------------\n";
  std::cout << "to check the move assign and constructors\n";
  std::vector<IntArray> myArray;
  for (int i=0; i<10; ++i){
    IntArray temp(std::to_string(i));
    //myArray.push_back(std::move(temp));
    myArray.push_back(temp);
  }
  
  std::cout << "\n-----------------------------------------------\n";
  std::cout << "to check the constructors usage in functions\n";
  IntArray arr0("Dadoudou");//1constructor
  foo(arr0);//1 copy constructor + 1 desctructor
  bar();//1constructor + 0(1) copy constructor + 1 destructor, this is optimized by the compiler
  

  return 0;
}
