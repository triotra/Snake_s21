#include "grafa.h"

void game_loop(matrix *A, GameInfo_t *game_info) {
  UserAction_t action;
  action = Action;
  start();

  while (A->game_over != 1) {
    refresh();
    timeout(game_info->speed);
    action = userInput(action, 1);
    clear();
    drow_al_f(game_info);
    sigact(action, A, game_info);
    clear();
    drow_al_f(game_info);
    if (game_info->speed < 700) {
      sigact(Down, A, game_info);
    }
  }
}

void cleanup_resources(GameInfo_t *game_info) {
  clear();
  timeout(3000);
  the_end(game_info);
  getch();
  endwin();
  free_field(game_info);
}
void tetris_game() {
  matrix A;
  A.x = 0;
  A.y = 0;

  A.col_line = 0;
  A.shag = 0;    // kolvo shagov ot verha do
  A.figura = 0;  // kolvo-figur v igre
  A.game_over = 0;
  srand(time(NULL));
  A.rez = rand() % 7;
  choose_figure(&A);
  GameInfo_t game_info = init_game(&A);
  A.rez = rand() % 7;
  choose_figure(&A);
  add_figure_at_screen(&A, &game_info);
  game_loop(&A, &game_info);
  cleanup_resources(&game_info);
}

void game_l() {
  int max_x = 22, max_y = 22;
  s21::Snake snake(max_x, max_y);

  while (!snake.IsGameOver()) {
    clear();
    drow_the_field();
    timeout(snake.GetSpeed());
    // еда
    mvprintw(snake.GetFoodY(), snake.GetFoodX(), "*");
    // змея
    for (int i = 0; i < snake.GetLength(); ++i) {
      mvprintw(snake.GetSnakeY()[i], snake.GetSnakeX()[i], "o");
    }
    print_stat_snake(snake);
    snake.game_game();
    snake.us();
    refresh();
  }
  endwin();
  std::cout << "Game Over! Score: " << snake.GetScore() << std::endl;
}

void choose_game() {
  mvprintw(6, 3, "WELCOM TO MY GAMES");
  mvprintw(8, 2, "please push KEY_UP to start SNAKE");
  mvprintw(10, 7, "please push KEY_DOWN to start TETRIS");

  mvprintw(18, 2, "handmade from GAITHERL");
  getch();
  int direction = 10;
  int ch = getch();
  switch (ch) {
    case KEY_UP:
      direction = 0;
      break;
    case KEY_DOWN:
      direction = 1;
      break;
  }
  switch (direction) {
    case 0:
      game_l();
      break;
    case 1:
      tetris_game();
      break;
  }
}

void print_stat_snake(const s21::Snake &snake) {
  mvprintw(2, 27 + 6, "%d", (600 - snake.GetSpeed()) / 40);
  mvprintw(5, 33, "%d", snake.GetScore());
  if (snake.GetSpeed() > 600) {
    mvprintw(8, 33, "pause");
    mvprintw(8, 2, "please push space");
    mvprintw(10, 7, "to continue");
  } else {
    mvprintw(8, 33, "%d", (600 - snake.GetSpeed()) / 40);
  }
  mvprintw(11, 33, "%d", saveBestScore(snake.GetScore()));
}
