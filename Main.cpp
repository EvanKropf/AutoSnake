#include "Apple.h"
#include "Snake.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <unistd.h>
#include <vector>
// TODO
// ADD APPLE CONDITIONALS TO CHECK IF SPAWNING ON SNAKE
// ALSO TRY AND FIND WHY SNAKE BE GOIN TOFAR RIGHT
int main() {
  // SETUP
  while (true) {

    Snake snake;
    // Snake snakeTail;
    Apple apple;
    int size = 0;
    const int ROW = 10;
    const int COL = 10;
    char board[ROW][COL];

    bool GameOver = false;
    snake.setY(4);
    snake.setX(4);
    Snake *snake1 = new Snake();
    // RESETTING BOARD
    for (int i = 0; i <= ROW; i++) {
      for (int j = 0; j < COL; j++) {
        board[i][j] = ' ';
      }
    }
    std::vector<int> xPoints;
    std::vector<int> yPoints;
    int turns = 0;

    // ACTUAL THINGY
    while (true) {

      board[apple.getY()][apple.getX()] = '@';
      board[snake.getY()][snake.getX()] = '*';
      yPoints.push_back(snake.getY());
      xPoints.push_back(snake.getX());
      // board[snakeTail.getX()][snakeTail.getY()] = '*';
      // print out board
      for (int i = 0; i <= ROW; i++) {
        for (int j = 0; j < COL; j++) {
          if (j == 0) {
            std::cout << "|";
          }
          std::cout << board[i][j];
          if (j == COL - 1) {
            std::cout << "| \n";
          }
        }
      }

      // move SNAKE towards apple
      if (snake.getX() < apple.getX()) {
        if (board[snake.getY()][snake.getX() + 1] != '*' &&
            snake.getX() + 1 != ROW) {
          snake.moveXPositive();
        } else if (board[snake.getY() + 1][snake.getX()] != '*' &&
                   snake.getY() + 1 != ROW) {
          snake.moveYPositive();
        } else if (board[snake.getY() - 1][snake.getX()] != '*' &&
                   snake.getY() != 0) {
          snake.moveYNegative();
        } else if (board[snake.getY()][snake.getX() - 1] != '*') {
          snake.moveXNegative();
        } else {
          break;
        }
      } else if (snake.getX() > apple.getX()) {
        if (board[snake.getY()][snake.getX() - 1] != '*') {
          snake.moveXNegative();
        } else if (board[snake.getY() + 1][snake.getX()] != '*' &&
                   snake.getY() + 1 != ROW) {
          snake.moveYPositive();
        } else if (board[snake.getY() - 1][snake.getX()] != '*' &&
                   snake.getY() != 0) {
          snake.moveYNegative();
        } else if (board[snake.getY()][snake.getX() + 1] != '*' &&
                   snake.getX() + 1 != COL) {
          snake.moveXPositive();
        } else {
          break;
        }

      } else if (snake.getY() < apple.getY()) {
        if (board[snake.getY() + 1][snake.getX()] != '*' &&
            snake.getY() + 1 != ROW) {
          snake.moveYPositive();
        } else if (board[snake.getY()][snake.getX() + 1] != '*' &&
                   snake.getX() + 1 != ROW) {
          snake.moveXPositive();
        } else if (board[snake.getY()][snake.getX() - 1] != '*' &&
                   snake.getX() != 0) {
          snake.moveXNegative();
        } else if (board[snake.getY() - 1][snake.getX()] != '*' &&
                   snake.getY() != 0) {
          snake.moveYNegative();
        } else {
          break;
        }

      } else if (snake.getY() > apple.getY()) {

        if (board[snake.getY() - 1][snake.getX()] != '*' && snake.getY() != 0) {
          snake.moveYNegative();
        } else if (board[snake.getY()][snake.getX() + 1] != '*' &&
                   snake.getX() + 1 != ROW) {
          snake.moveXPositive();
        } else if (board[snake.getY()][snake.getX() - 1] != '*') {
          snake.moveXNegative();
        } else if (board[snake.getY() + 1][snake.getX()] != '*' &&
                   snake.getY() != COL) {
          snake.moveYPositive();
        } else {
          break;
        }
      }

      // moves tail

      board[yPoints[turns - size]][xPoints[turns - size]] = ' ';
      // make function in apple
      if (apple.getX() == snake.getX() && apple.getY() == snake.getY()) {
        apple.setX(rand() % (COL));
        apple.setY(rand() % (ROW));
        // snake.incrementSize();
        size++;
      }
      std::cout << snake.getX() << ", " << snake.getY();
      turns++;
      // int timer = 0;
      //   while (timer != 429496729) {
      //     timer++;
      //   }
      
      usleep(1000000/turns); // measured in micro seconds

      std::cout << std::endl;
      std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
  }
}
