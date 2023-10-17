#include <cstdlib>
#include<iostream>
#include<vector>

class Character{
public:
  Character(std::string name):m_name(name){}

  int m_x;
  int m_y;
  std::string m_name;
  void move(int _x, int _y){

  }
};

class Command{
public:
  virtual ~Command(){}
  virtual void execute(Character&) = 0;
  virtual void undo(Character&) = 0;
};

class Move: public Command{
public:
  void execute (Character& c) override{
    std::cout << c.m_name << "move" << std::endl;
    int random_x = rand()%4;
    int random_y = rand()%4;
    c.move(random_x, random_y);
    m_x = random_x;
    m_y = random_y;
    std::cout << c.m_name << " moved " << "x: " << m_x << " y: " << m_y << std::endl;
  }

  void undo(Character& c) override{
    std::cout << c.m_name << "undo" << std::endl;
    c.move(-m_x, -m_y);
    std::cout << c.m_name << " undo move " << "x: " << -m_x << " y: " << -m_y << std::endl;
  }

  ~Move() override=default; 
private:
  int m_x;
  int m_y;
};

int main(){
  Character ch{"dadou"};
  std::vector<Command*> vc;
  Command* m1 = new Move;
  Command* m2 = new Move;
  Command* m3 = new Move;
  Command* m4 = new Move;

  vc.push_back(m1);
  vc.push_back(m2);
  vc.push_back(m3);
  vc.push_back(m4);

  for(auto it = vc.begin(); it!=vc.end(); it++){
    (*it)->execute(ch);
  }
  std::cout << "\n-------------------------------------\n";
/*
  for(auto it = vc.end()-1; it!=vc.begin()-1; it--){
    (*it)->undo(ch);
  }
  */
  for(auto it = vc.rbegin(); it != vc.rend(); it++){
    (*it)->undo(ch);
  }

  return 0;
}
