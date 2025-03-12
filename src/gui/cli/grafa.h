#ifndef grafa_h
#define grafa_h
//#include <ncurses/ncurses.h>
//#include <stdio.h>
//#include <string.h>
//#include <time.h>
//#include <unistd.h>

//#include "../../brick_game/tetris/tetris.h"
#include <fstream>
#include <iostream>

#include "../../brick_game/snake/snake.h"
void tetris_game();
// int saveBestScore(int score) ;
void print_stat_snake(const s21::Snake &snake);
void choose_game();
void game_l();
void drow_the_field();
void begin_the_game();
void print_blocks(int x, int y);
void start();
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_stats(GameInfo_t *game_info);
void the_end(GameInfo_t *game_info);
void drow_al_f(GameInfo_t *game_info);
void game_loop(matrix *A, GameInfo_t *game_info);
void cleanup_resources(GameInfo_t *game_info);

#endif
