#ifndef INTARRAY_H
#define INTARRAY_H

#include<string>

class IntArray{
public:
  //constructor
  IntArray(std::string);
  //distructor
  ~IntArray();
  //copy constructor
  IntArray(const IntArray&);
  //copy assign
  IntArray& operator = (const IntArray&);
  //move constructor
  IntArray (IntArray&&);
  //move assign
  IntArray& operator = (IntArray&&);

private:
  std::string m_name;
  int* m_data;
};
#endif
