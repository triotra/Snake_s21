#include <gtest/gtest.h>

#include "../brick_game/snake/snake.h"

namespace s21 {

TEST(SnakeTest, Reset) {
  Snake snake(20, 20);
  snake.Reset();
  EXPECT_GE(snake.GetFoodX(), 1);
  EXPECT_LT(snake.GetFoodX(), 19);
  EXPECT_GE(snake.GetFoodY(), 1);
  EXPECT_LT(snake.GetFoodY(), 19);
  EXPECT_EQ(snake.GetScore(), 0);
  EXPECT_EQ(snake.IsGameOver(), 0);
  EXPECT_EQ(snake.GetLength(), 4);
  EXPECT_EQ(snake.GetSpeed(), 600);
}

TEST(SnakeTest, GameGame_CollisionWall) {
  Snake snake(20, 20);
  snake.Reset();
  snake.game_game();  // Move snake to the next position

  // Simulate collision with a wall
  snake.direction_ = 38;  // Up
  for (int i = 0; i < 10; ++i) {
    snake.game_game();
  }
  EXPECT_EQ(snake.IsGameOver(), 1);
}

TEST(SnakeTest, GameGame_CollisionSelf) {
  Snake snake(20, 20);
  snake.Reset();

  // Simulate self-collision

  snake.direction_ = 40;  // right
  snake.game_game();
  snake.direction_ = 37;  // down
  snake.game_game();
  snake.direction_ = 38;  // left
  snake.game_game();

  EXPECT_EQ(snake.IsGameOver(), 1);
}

TEST(SnakeTest, GameGame_EatFood) {
  Snake snake(20, 20);
  snake.Reset();
  snake.SetFoodX(snake.GetSnakeX()[0]);
  snake.SetFoodY(snake.GetSnakeY()[0] + 1);
  snake.direction_ = 40;
  int initialLength = snake.GetLength();
  int initialScore = snake.GetScore();
  snake.game_game();

  EXPECT_EQ(snake.GetLength(), initialLength + 1);
  EXPECT_EQ(snake.GetScore(), initialScore + 1);
  EXPECT_NE(snake.GetFoodX(), snake.GetSnakeX()[0]);
}

TEST(SnakeTest, GameGame_NoEatFood) {
  Snake snake(20, 20);
  snake.Reset();
  int initialLength = snake.GetLength();
  int initialScore = snake.GetScore();
  snake.game_game();

  EXPECT_EQ(snake.GetLength(), initialLength);
  EXPECT_EQ(snake.GetScore(), initialScore);
}

TEST(SnakeTest, GenerateFood) {
  Snake snake(20, 20);
  snake.Reset();
  snake.GenerateFood();
  for (int i = 0; i < snake.GetLength(); ++i) {
    EXPECT_NE(snake.GetFoodX(), snake.GetSnakeX()[i]);
    EXPECT_NE(snake.GetFoodY(), snake.GetSnakeY()[i]);
  }
}

TEST(SnakeTest, Getters) {
  Snake snake(20, 20);
  snake.Reset();
  EXPECT_EQ(snake.GetScore(), 0);
  EXPECT_EQ(snake.IsGameOver(), 0);
  EXPECT_EQ(snake.GetLength(), 4);
  EXPECT_EQ(snake.GetSpeed(), 600);
}

}  // namespace s21
int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}  // namespace s21
