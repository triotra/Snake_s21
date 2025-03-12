#include "snake.h"
namespace s21 {

Snake::Snake(int max_x, int max_y) : max_x_(max_x), max_y_(max_y) {
  srand(time(0));
  Reset();
}

void Snake::Reset() {
  food_x_ = 1 + rand() % (max_x_ - 2);
  food_y_ = 1 + rand() % (max_y_ - 2);
  score_ = 0;
  game_over_ = 0;
  direction_ = 40;
  snake_x_.clear();
  snake_y_.clear();
  snake_x_ = {max_x_ / 2, max_x_ / 2 - 1, max_x_ / 2 - 2, max_x_ / 2 - 3};
  snake_y_ = {max_y_ / 2, max_y_ / 2, max_y_ / 2, max_y_ / 2};
  snake_length_ = 4;
  speed_ = 600;
}

void Snake::game_game() {
  // us();
  int prev_x = snake_x_[0];
  int prev_y = snake_y_[0];
  switch (direction_) {
    case 38:
      snake_y_[0]--;
      break;
    case 40:
      snake_y_[0]++;
      break;
    case 37:
      snake_x_[0]--;
      break;
    case 39:
      snake_x_[0]++;
      break;
    case 0:
      break;
    case 999:
      game_over_ = 1;
      break;
  }
  // Check for collisions
  if (snake_x_[0] < 1 || snake_x_[0] >= max_x_ - 1 || snake_y_[0] < 1 ||
      snake_y_[0] >= max_y_ - 1) {
    game_over_ = 1;
  }

  for (int i = 1; i < snake_length_; ++i) {
    if (snake_x_[0] == snake_x_[i] && snake_y_[0] == snake_y_[i]) {
      game_over_ = 1;
    }
  }

  if (snake_x_[0] == food_x_ && snake_y_[0] == food_y_) {
    score_++;
    snake_length_++;
    GenerateFood();
    AdjustSpeed();

    snake_x_.push_back(snake_x_.back());
    snake_y_.push_back(snake_y_.back());
    for (size_t i = snake_length_ - 2; i > 1; --i) {
      snake_x_[i] = snake_x_[i - 1];
      snake_y_[i] = snake_y_[i - 1];
    }
    snake_x_[1] = prev_x;
    snake_y_[1] = prev_y;
    // Adjust speed based on score
  } else {
    for (size_t i = snake_length_ - 1; i > 1; --i) {
      snake_x_[i] = snake_x_[i - 1];
      snake_y_[i] = snake_y_[i - 1];
    }
    snake_x_[1] = prev_x;
    snake_y_[1] = prev_y;
  }

  if (snake_length_ >= 200) {
    game_over_ = 1;  // Win condition
  }
  if (game_over_ == 1) {
    saveBestScore(score_);
  }
}

void Snake::GenerateFood() {
  food_x_ = 1 + rand() % (max_x_ - 2);
  food_y_ = 1 + rand() % (max_y_ - 2);

  for (int i = 0; i < snake_length_ - 1; ++i) {
    if (snake_x_[i] == food_x_ && snake_y_[i] == food_y_) {
      GenerateFood();
      return;
    }
  }
}

void Snake::AdjustSpeed() {
  // Example: Decrease speed by 10ms every 10 points
  if (score_ % 5 == 0 && speed_ > 100 && score_ > 0) {
    speed_ -= 40;
  }
}

int Snake::GetScore() const { return score_; }
int Snake::IsGameOver() const { return game_over_; }
std::vector<int> Snake::GetSnakeX() const { return snake_x_; }
std::vector<int> Snake::GetSnakeY() const { return snake_y_; }
int Snake::GetFoodX() const { return food_x_; }
int Snake::GetFoodY() const { return food_y_; }
int Snake::GetLength() const { return snake_length_; }
int Snake::GetSpeed() const { return speed_; }
void Snake::SetFoodX(int x) { food_x_ = x; }
void Snake::SetFoodY(int x) { food_y_ = x; }
}  // namespace s21
int saveBestScore(int score) {
  std::ifstream inputFile("highscore.txt");
  int highscore = 0;

  if (inputFile.is_open()) {
    inputFile >> highscore;
    inputFile.close();
  }

  if (score > highscore) {
    std::ofstream outputFile("highscore.txt");
    if (outputFile.is_open()) {
      outputFile << score;
      outputFile.close();
    }
  }
  return highscore;
}
