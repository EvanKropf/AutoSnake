#include <bits/types/time_t.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
class Apple {
private:
  int x, y;

public:
  Apple() {
    srand(time(0));
    x = rand() % 10;
    y = rand() % 10;
  };
  int getX() { return this->x; };
  int getY() { return this->y; };

  void setX(int newX) { x = newX; }
  void setY(int newY) { y = newY; }
};