#ifndef snake_h
#define snake_h
//#include "../../gui/cli/grafa.h"
#include "../tetris/tetris.h"
#define DELAY 100000

#define MAX_SNAKE_LENGTH 200
#include <fstream>
#include <vector>

int saveBestScore(int score);
namespace s21 {

class Snake {
 public:
  // Constructor
  Snake(int max_x, int max_y);

  // Resets the game to its initial state
  void Reset();

  // Game logic update based on user input
  void game_game();
  void us();
  // Generates food at a new random location
  void GenerateFood();

  // Adjusts the game speed based on the score
  void AdjustSpeed();

  // Getter methods for game state
  int GetScore() const;
  int IsGameOver() const;
  std::vector<int> GetSnakeX() const;
  std::vector<int> GetSnakeY() const;
  int GetFoodX() const;
  int GetFoodY() const;
  void SetFoodX(int x);
  void SetFoodY(int x);
  int GetLength() const;
  int GetSpeed() const;
  int direction_;

 private:
  int max_x_;      // Maximum x-coordinate of the game field
  int max_y_;      // Maximum y-coordinate of the game field
  int food_x_;     // x-coordinate of the food
  int food_y_;     // y-coordinate of the food
  int score_;      // Player's score
  int game_over_;  // Game over flag
  // int direction_;      // Current direction of the snake (KEY_UP, KEY_DOWN,
  // etc.)
  std::vector<int> snake_x_;  // x-coordinates of snake segments
  std::vector<int> snake_y_;  // y-coordinates of snake segments
  int snake_length_;          // Length of the snake
  int speed_;                 // Game speed (delay in milliseconds)
};

}  // namespace s21

#endif
