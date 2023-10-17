#include <iostream>
#include "picture.h"
#include <cmath>

int func_0(int x);

int main(int argc, char**argv){
  Picture pic(800, 800, 255, 255, 255);

  for (int x=0; x<=400; ++x) {
    int y{func_0(x)};
    pic.set(x, y, 0, 0, 0);
  }

  pic.save("assign_3_0.png");
  cout << "succeed in generagting the figure~" << endl;
}

int func_0(int x){
  return 0.00005*pow(x,3) - 0.03 * pow(x,2) + 4 * x + 200;
}
