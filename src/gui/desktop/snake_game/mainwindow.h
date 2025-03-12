#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include "snake_qt.h"
#include "tetris_qt.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
 private slots:
  void on_pushButtonSnake_clicked();
  void on_pushButtonTetris_clicked();
  void returnToMenu();

 private:
  Ui::MainWindow *ui;
  SnakeQt *snakeGame;
  TetrisQt *tetrisGame;  //Добавили указатель на игру тетрис
  QWidget *currentGameWidget;  //Указатель на текущий виджет игры
  void deleteGameWidget();
  void gameFinished();
  void clearGameWidget();
};

#endif  // MAINWINDOW_H
