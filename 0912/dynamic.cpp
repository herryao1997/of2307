#include<iostream>
#include <ostream>
#include<string>

class Shape{
public:
  Shape(std::string name): m_name(name){
  std::cout << "constructor of base" << std::endl;
  };
  virtual int getArea() = 0;
  //virtual int getArea(){std::cout << "no shape defined!" << std::endl; return 0;}
  virtual ~Shape(){
  std::cout << "destructor of base" << std::endl;
  }

private:
  std::string m_name;
};

class Rectangle :public Shape{
public:
  Rectangle(int width, int height): Shape("Rectangle"), m_width(width), m_height(height){
    std::cout << "constructor of Rectangle" << std::endl;
  }

  int getArea() override{
    return m_width * m_height;
  }
  ~Rectangle() override {
  std::cout << "destructor of Rectangle" << std::endl;
  }

private:
  int m_width;
  int m_height;
};

class Triangle: public Shape{
public:
  Triangle(int base, int height):Shape("Triangle"), m_base(base), m_height(height){
    std::cout << "constructor of Triangle" << std::endl;
  }
  int getArea() override{
    return m_base * m_height / 2;
  }
  
  ~Triangle() override{
  std::cout << "destructor of Triangle" << std::endl;
  }


private:
  int m_base;
  int m_height;
};

void getArea(Shape* ptr){
  std::cout << ptr->getArea() << std::endl;
}


int main(){
  
  Shape* rec = new Rectangle(5, 10);
  std::cout << rec->getArea() << std::endl;
  std::cout << "-------------rec--------------" << std::endl;
  Shape* tri = new Triangle(5, 10);
  std::cout << tri->getArea() << std::endl;
  std::cout << "-------------tri--------------" << std::endl;

  Rectangle rec_(5, 10);
  Triangle tri_(5, 10);

  std::cout << rec_.getArea() << std::endl;
  std::cout << tri_.getArea() << std::endl;
  
  getArea(&rec_);
  getArea(tri);

  Shape &rrec = *rec;
  std::cout << rrec.getArea() << std::endl;
  
  delete rec;
  delete tri;
  return 0;
}
