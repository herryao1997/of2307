#include <cstdint>
#include<iostream>
#include<string>

//base
class Shape{
public:
  Shape(std::string name):m_name(name){}

  //virtual ~Shape(){std::cout << "base destructor" << std::endl;}

  virtual int getArea() = 0;

private:
  std::string m_name;
};

//derived 1
class Ractangle:public Shape{
public:
  Ractangle(int height, int width):Shape("Ractangle"),m_height(height), m_width(width){}
  //~Ractangle()override{std::cout << "Ractangle destructor" << std::endl;}
  int getArea()override{
    return m_height * m_width;
  }
private:
  int m_height;
  int m_width;
};

//derived 2
class Triangle: public Shape{
public:
  Triangle(int height, int base): Shape("Triangle"), m_height(height), m_base(base){}
  //~Triangle()override{std::cout << "triangle destructor" << std::endl;}
  int getArea()override{
    return m_height * m_base / 2;
  }

private:
  int m_height;
  int m_base;
};


using FuncType = int(*)(); // the function pointer with function type same as getArea

FuncType getVirtualFunc(Shape* shape, uint64_t idx){
  uintptr_t** vptr = reinterpret_cast<uintptr_t**>(shape); // 1) get the vptr
  uintptr_t* vtbl = *vptr;// 2) vptr is pointing at vtbl, so vtbl = *vptr
  uintptr_t func = *vtbl;// 3) the first virtual function is stored in vtbl
  // return the virtual func of the given class

  return reinterpret_cast<FuncType>(func+idx);
}


int main(){
  Triangle tri(5, 10);
  Ractangle rec(5, 10);

  std::cout << getVirtualFunc(&tri, 16)() << std::endl;
  std::cout << getVirtualFunc(&rec, 16)() << std::endl;

  std::cout << tri.getArea() << std::endl;
  std::cout << rec.getArea() << std::endl;

  Shape* rec1 = new Ractangle(5, 10);

  std::cout << getVirtualFunc(rec1, 16)() << std::endl;
  //delete rec1;

  return 0;
}
