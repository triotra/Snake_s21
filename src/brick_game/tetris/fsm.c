#include "tetris.h"

UserAction_t userInput(UserAction_t action, bool hold) {
  action = Action;  // yi dont know to do
  noecho();
  int input = getch();
  hold = true;
  if (input == KEY_UP && hold == true)
    return Up;
  else if (input == KEY_DOWN)
    return Down;
  else if (input == KEY_LEFT)
    return Left;
  else if (input == KEY_RIGHT)
    return Right;
  else if (input == 27)
    return Terminate;
  else if (input == KEY_ENTER)
    return Start;

  else if (input == 32)
    return Pause;
  else
    return action;
}
