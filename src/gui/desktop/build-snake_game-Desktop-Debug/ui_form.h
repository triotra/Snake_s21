/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form {
 public:
  QPushButton *pushButton;

  void setupUi(QWidget *Form) {
    if (Form->objectName().isEmpty())
      Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(400, 300);
    pushButton = new QPushButton(Form);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(40, 40, 301, 121));

    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
  }  // setupUi

  void retranslateUi(QWidget *Form) {
    Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    pushButton->setText(
        QCoreApplication::translate("Form", "PushButton", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Form : public Ui_Form {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_FORM_H
