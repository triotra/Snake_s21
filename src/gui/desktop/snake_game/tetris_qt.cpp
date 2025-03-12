#include "tetris_qt.h"

TetrisQt::TetrisQt(QWidget *parent)
    : QWidget(parent), gameInfo{}, gameRunning(false), A{} {
  qDebug() << "Food pixel coordinates: X=";
  gameTimer = new QTimer(this);
  connect(gameTimer, &QTimer::timeout, this, &TetrisQt::updateGame);
  // matrix A;
  qDebug() << "Food pixel coordinates: X=";
  A = {0};
  A.rez = random() % 7;
  choose_figure(&A);
  // GameInfo_t gameInfo;
  gameInfo = init_game(&A);
  qDebug() << gameInfo.field[0][0];
  gameRunning = true;
  gameTimer->start(gameInfo.speed);
  // add_figure_at_screen(&A, &gameInfo);

  qDebug() << gameInfo.field[0][0];

  setFocusPolicy(Qt::StrongFocus);
  // sigact(6, &A, &gameInfo);
}

TetrisQt::~TetrisQt() {
  cleanUpGame(&gameInfo);
  delete gameTimer;
}

void TetrisQt::startGame() {
  if (!gameRunning) {
    gameRunning = true;
    gameTimer->start(500);
  }
}

void TetrisQt::stopGame() {
  gameRunning = false;
  gameTimer->stop();
}

void TetrisQt::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setClipRect(event->rect());

  qDebug() << A.game_over;

  if (A.game_over) {
    painter.fillRect(QRect(0, 0, 440, 500), Qt::black);
    painter.setPen(Qt::red);
    gameTimer->start(500);
    painter.drawText(rect(), Qt::AlignCenter, "Game Over!");
    update();
    stopGame();
    emit returnToMenu();
  }

  else {
    QString levelText = QString("Уровень: %1").arg(gameInfo.level);
    QString speedText = QString("Скорость: %1").arg(gameInfo.speed);
    QString bestText = QString("Счет: %1").arg(gameInfo.score);
    painter.drawText(220, 40, levelText);
    painter.drawText(220, 60, speedText);
    painter.drawText(220, 80, bestText);

    for (int i = 0; i < 22; i++) {
      for (int j = 0; j < 10; j++) {
        if (gameInfo.field[i][j] == 1) {
          painter.fillRect(QRect(j * 20, i * 20, 20, 20), Qt::blue);
        } else
          painter.fillRect(QRect(j * 20, i * 20, 20, 20), Qt::black);
      }
    }
    for (int k = 0; k < 4; k++) {
      for (int m = 0; m < 4; m++) {
        // if (next_block->block_matrix[k][m]==1){
        if (gameInfo.next[k][m] == 1) {
          // print_blocks(k + 18, m + 13);
          painter.fillRect(QRect((k + 13) * 20, (m + 13) * 20, 20, 20),
                           Qt::blue);
        }
      }
    }
  }
}

void TetrisQt::keyPressEvent(QKeyEvent *event) {
  int key = 0;
  switch (event->key()) {
    case Qt::Key_Left:
      key = 3;
      sigact(key, &A, &gameInfo);
      break;
    case Qt::Key_Right:
      key = 4;
      sigact(key, &A, &gameInfo);
      break;
    case Qt::Key_Down:
      key = 6;
      sigact(key, &A, &gameInfo);
      break;
    case Qt::Key_Up:
      key = 5;
      sigact(key, &A, &gameInfo);
      break;  // Поворот фигуры
    case Qt::Key_Space:
      key = 1;
      sigact(key, &A, &gameInfo);
      break;
    default:
      break;
  }

  update();
}

void TetrisQt::updateGame() {
  if (gameRunning) {
    sigact(6, &A, &gameInfo);
    qDebug() << A.game_over;  // Автоматическое движение вниз
    update();
  }
}
void TetrisQt::cleanUpGame(GameInfo_t *gameInfo) { free_field(gameInfo); }
