#ifndef SNAKE_QT_H
#define SNAKE_QT_H

#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>

#include "../../../brick_game/snake/snake.h"
// class s21::Snake;
class SnakeQt : public QWidget {
  Q_OBJECT

 public:
  explicit SnakeQt(QWidget *parent = nullptr);
  ~SnakeQt();
 signals:
  void returnToMenu();

 protected:
  void paintEvent(QPaintEvent *event) override;
  void timerEvent(QTimerEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;
  void showEvent(QShowEvent *event) override;
 private slots:
  void updateGame();

 private:
  s21::Snake *snake;  // Экземпляр вашей змейки
  QTimer *timer;
  int gridSize;
  bool gameOver;
  // void updateGame();
};
#endif  // SNAKE_QT_H
