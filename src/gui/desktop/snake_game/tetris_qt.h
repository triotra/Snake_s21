#ifndef TETRIS_H
#define TETRIS_H

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>
extern "C" {

#include "../../../brick_game/tetris/tetris.h"
};

class TetrisQt : public QWidget {
  Q_OBJECT

 public:
  explicit TetrisQt(QWidget *parent = nullptr);
  ~TetrisQt();
  void startGame();
  void stopGame();
  void paintEvent(QPaintEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;
 signals:
  void returnToMenu();

 private:
  GameInfo_t gameInfo;
  matrix currentFigure;
  QTimer *gameTimer;
  bool gameRunning;
  matrix A;
  int over = 0;

  int initGame(GameInfo_t *gameInfo);  //Запуск новой игры
  void updateGame();  //Обновление состояния игры
  void cleanUpGame(GameInfo_t *gameInfo);  //Очистка ресурсов игры
};

#endif  // TETRIS_H
