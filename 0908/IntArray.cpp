#include "IntArray.h"
#include<algorithm>
#include<iostream>

IntArray::IntArray(std::string name):m_name(name), m_data(new int[10]){
  /*
  for(int i=0; i<10; i++){
    m_data[i] = 5v ;
  }*/
  std::cout << m_name << " was constructed\n";
  std::fill(m_data, m_data+10, 5);
} 

IntArray::~IntArray(){
  std::cout << m_name << " was destructed\n";
  delete []m_data;
}
// This will result in vert high cost for the mem usages, in the past the copy constructor& assign are given as private
// Currently the method to ban the copy assign and constructor is 
// IntArray::IntArray(const IntArray&) = delete;
IntArray::IntArray(const IntArray& rhs){
  std::cout << m_name << " was copy constructed\n";
  m_name = rhs.m_name;
  m_data = new int[10];
  /*
  for(int i=0; i<10; i++){
    m_data[i] = rhs.m_data[i];
  }*/
  std::copy(rhs.m_data, rhs.m_data+10, m_data);
}

IntArray& IntArray::operator=(const IntArray& rhs){
  std::cout << m_name << " was copy assigned\n";
  if(this == &rhs){
    return *this;
  }
  m_name = rhs.m_name;
  delete []m_data;
  m_data = new int[10];
  std::copy(rhs.m_data, rhs.m_data+10, m_data);
  return *this;
}

//move assign and constructor is to capture the contents and assign the old object as empty.
//since the contents are captured and the initial object is destroyed so the const keyword is not proper here
IntArray::IntArray(IntArray&& other){
  std::cout << m_name << " was move constructed\n";
  m_name = other.m_name;
  other.m_name = "";
  m_data = other.m_data;
  other.m_data = nullptr;
}
IntArray& IntArray::operator=(IntArray&& rhs){
  std::cout << m_name << " was move assigned\n";
  if(this!=&rhs){
    m_name = rhs.m_name;
    rhs.m_name = "";
    m_data = rhs.m_data;
    rhs.m_data = nullptr;
  }
  return *this;
}
