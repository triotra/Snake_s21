/********************************************************************************
** Form generated from reading UI file 'tetris.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRIS_H
#define UI_TETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tetris {
 public:
  QWidget *centralwidget;
  QPushButton *pushButton_3;
  QMenuBar *menubar;
  QStatusBar *statusbar;
  QToolBar *toolBar;

  void setupUi(QMainWindow *tetris) {
    if (tetris->objectName().isEmpty())
      tetris->setObjectName(QString::fromUtf8("tetris"));
    tetris->resize(800, 600);
    tetris->setBaseSize(QSize(100, 100));
    centralwidget = new QWidget(tetris);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    pushButton_3 = new QPushButton(centralwidget);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setGeometry(QRect(80, 170, 341, 91));
    tetris->setCentralWidget(centralwidget);
    menubar = new QMenuBar(tetris);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 22));
    tetris->setMenuBar(menubar);
    statusbar = new QStatusBar(tetris);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    tetris->setStatusBar(statusbar);
    toolBar = new QToolBar(tetris);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    tetris->addToolBar(Qt::TopToolBarArea, toolBar);

    retranslateUi(tetris);

    QMetaObject::connectSlotsByName(tetris);
  }  // setupUi

  void retranslateUi(QMainWindow *tetris) {
    tetris->setWindowTitle(
        QCoreApplication::translate("tetris", "MainWindow", nullptr));
    pushButton_3->setText(
        QCoreApplication::translate("tetris", "Exit", nullptr));
    toolBar->setWindowTitle(
        QCoreApplication::translate("tetris", "toolBar", nullptr));
  }  // retranslateUi
};

namespace Ui {
class tetris : public Ui_tetris {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_TETRIS_H
