#include <QApplication>

#include "mainwindow.h"
#include "snake_qt.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Menu");
  w.setFixedSize(440, 500);
  w.show();

  return a.exec();
}
