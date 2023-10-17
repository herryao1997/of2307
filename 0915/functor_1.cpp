#include<iostream>
#include<iomanip>

struct Value{
  int m_result1{0};
  float m_result2{0.0f};

  int operator()(int value){
    m_result1 = value;
    return m_result1;
  }

  float operator()(float value){
    m_result2 = value;
    return m_result2;
  }
};

int main(){
  Value v;
  v(32);
  v(32.0f);
  std::cout << v.m_result1 << std::endl;
  std::cout << std::fixed << std::setprecision(6) <<  v.m_result2 << std::endl;
  std::cout << v.m_result1 << std::endl;
  return 0;
}
