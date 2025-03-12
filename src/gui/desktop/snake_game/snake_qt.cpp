#include "snake_qt.h"

#include <QDebug>
SnakeQt::SnakeQt(QWidget *parent) : QWidget(parent) {
  qDebug() << "Food pixel coordinates: X=";
  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &SnakeQt::updateGame);
  // timer->start(800); // Скорость игры
  gameOver = false;
  setFocusPolicy(Qt::StrongFocus);  // Для обработки клавиш
  gridSize = 20;
  snake = new s21::Snake(12, 22);
  timer->start(snake->GetSpeed());
  qDebug() << snake->GetSpeed();
}

void SnakeQt::showEvent(QShowEvent *event) { QWidget::showEvent(event); }

SnakeQt::~SnakeQt() {
  delete timer;
  delete snake;
}

void SnakeQt::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  qDebug() << "tet" << snake->direction_;
  painter.fillRect(20, 20, 200, 400, Qt::black);  // Фон

  painter.setClipRect(event->rect());

  // едa

  qDebug() << snake->GetSnakeX()[1];
  qDebug() << snake->GetSnakeY()[1];
  qDebug() << snake->GetLength();
  painter.fillRect(snake->GetFoodX() * gridSize, snake->GetFoodY() * gridSize,
                   gridSize, gridSize, Qt::green);

  // змейкa
  for (int i = 0; i < snake->GetLength(); ++i) {
    painter.fillRect(
        snake->GetSnakeX()[i] * gridSize, snake->GetSnakeY()[i] * gridSize,
        gridSize, gridSize,
        Qt::yellow);  // Исправлено: использовался snake->GetSnakeY()[i] дважды
  }

  if (snake->IsGameOver()) {
    painter.fillRect(QRect(0, 0, 440, 500), Qt::black);
    painter.setPen(Qt::red);
    painter.drawText(rect(), Qt::AlignCenter, "Game Over!");
    update();
    emit returnToMenu();
  } else {
    // Отображение статистики
    QFont font;
    font.setPixelSize(20);
    painter.setFont(font);
    painter.setPen(Qt::black);
    int level = snake->GetScore() / 5;
    if (level > 10) {
      level = 10;
    }
    QString levelText = QString("Уровень: %1").arg(level);
    QString speedText = QString("Скорость: %1").arg(snake->GetSpeed());
    QString bestText =
        QString("Лучший: %1").arg(saveBestScore(snake->GetScore()));
    painter.drawText(220, 40, levelText);
    painter.drawText(220, 60, speedText);
    painter.drawText(220, 80, bestText);
  }
}

void SnakeQt::updateGame() {
  if (gameOver) return;
  qDebug() << "tet" << snake->direction_;
  snake->game_game();
  if (snake->IsGameOver()) {
    gameOver = true;
  }

  update();
}
void SnakeQt::timerEvent(QTimerEvent *event) { Q_UNUSED(event); }
void SnakeQt::keyPressEvent(QKeyEvent *event)

{
  qDebug() << snake->direction_;

  switch (event->key()) {
    case Qt::Key_Up:
      if (snake->direction_ != 40) snake->direction_ = 38;
      break;
    case Qt::Key_Down:
      if (snake->direction_ != 38) snake->direction_ = 40;
      break;
    case Qt::Key_Left:
      if (snake->direction_ != 39) snake->direction_ = 37;
      break;
    case Qt::Key_Right:
      if (snake->direction_ != 37) snake->direction_ = 39;
      break;
  }
  snake->game_game();
  update();
}
