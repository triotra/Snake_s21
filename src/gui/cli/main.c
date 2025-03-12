#include "grafa.h"

int main() {
  initscr();
  keypad(stdscr, 1);
  noecho();
  curs_set(0);
  timeout(10000);
  choose_game();
  return 0;
}
