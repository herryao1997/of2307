#include "picture.h"
#include <cmath>
#include <vector>
#include <algorithm>
using std::vector;

typedef struct{
  double x = 0;
  double y = 0;
}point;

void dePolarization(point & p_in);

int main(int argc, char**argv){
  const double PI = 3.1415926;
  Picture pic(800, 800);
  vector<point> plots;
  double theta{0.0};
  for(int num{0}; num<=1000; ++num){
    theta += (2*PI)/1000;
    plots.push_back(point{theta, cos(2*theta)});
  }


  std::for_each(plots.begin(), plots.end(), &dePolarization);  
  for(point item: plots){
    pic.set(item.x, item.y, 0, 0, 0);
  }

  pic.save("assign_3_1.png");
  return 0;
}

void dePolarization(point &p_in){
  int x = static_cast<int> (200 * p_in.y * cos(p_in.x) + 200); 
  int y = static_cast<int> (200 * p_in.y * sin(p_in.x) + 200); 
  p_in.x = x;
  p_in.y = y;
}
