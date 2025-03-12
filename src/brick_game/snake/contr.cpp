#include "snake.h"
namespace s21 {
void Snake::us() {
  int ch = getch();
  switch (ch) {
    case KEY_UP:
      if (direction_ != 40) direction_ = 38;
      break;
    case KEY_DOWN:
      if (direction_ != 38) direction_ = 40;
      break;
    case KEY_LEFT:
      if (direction_ != 39) direction_ = 37;
      break;
    case KEY_RIGHT:
      if (direction_ != 37) direction_ = 39;
      break;
    case 27:
      direction_ = 999;
      break;
    case KEY_ENTER:
      direction_ = 0;
      break;
  }
}
}  // namespace s21
