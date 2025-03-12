#include "mainwindow.h"

#include <QLayout>
#include <QVBoxLayout>

#include "snake_qt.h"
#include "tetris_qt.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentGameWidget(nullptr) {
  ui->setupUi(this);
  ui->centralWidget->setLayout(new QVBoxLayout(ui->centralWidget));

  connect(ui->pushButton_2, &QPushButton::clicked, this,
          &MainWindow::on_pushButtonSnake_clicked);
  connect(ui->pushButton, &QPushButton::clicked, this,
          &MainWindow::on_pushButtonTetris_clicked);
  connect(this, &MainWindow::gameFinished, this, &MainWindow::returnToMenu);

  ui->pushButton->show();
  ui->pushButton_2->show();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButtonSnake_clicked() {
  clearGameWidget();
  snakeGame = new SnakeQt(this);
  connect(snakeGame, &SnakeQt::returnToMenu, this, &MainWindow::returnToMenu);
  ui->centralWidget->layout()->addWidget(snakeGame);
  currentGameWidget = snakeGame;
  // Скрываем кнопки меню
  ui->pushButton->hide();
  ui->pushButton_2->hide();
}

void MainWindow::on_pushButtonTetris_clicked() {
  clearGameWidget();
  tetrisGame = new TetrisQt(this);
  connect(tetrisGame, &TetrisQt::returnToMenu, this, &MainWindow::returnToMenu);
  ui->centralWidget->layout()->addWidget(tetrisGame);
  currentGameWidget = tetrisGame;
  // Скрываем кнопки меню
  ui->pushButton->hide();
  ui->pushButton_2->hide();
}

void MainWindow::clearGameWidget() {
  if (currentGameWidget) {
    delete currentGameWidget;
    currentGameWidget = nullptr;
  }
  QLayoutItem *child;
  while ((child = ui->centralWidget->layout()->takeAt(0)) != nullptr) {
    delete child;
  }
}

void MainWindow::returnToMenu() {
  clearGameWidget();
  ui->pushButton->show();
  ui->pushButton_2->show();
}

void MainWindow::gameFinished() { emit returnToMenu(); }
