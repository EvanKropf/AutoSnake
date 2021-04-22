class Snake {
private:
  int x, y, size;
  // make a function for moving snake up down left right
public:
  Snake() {
  
    size = 1;
  };
  int getX() { return this->x; };
  int getY() { return this->y; };
  int getSize() { return size; };
  void setX(int newX) { this->x = newX; }
  void setY(int newY) { this->y = newY; }
  void incrementSize() { this->size++; }
  void moveYPositive() { this->y++; }
  void moveYNegative() { this->y--; }
  void moveXPositive() { this->x++; }
  void moveXNegative() { this->x--; }
};