/********************************************************************************
** Form generated from reading UI file 'logwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logWindow
{
public:
    QPushButton *loginButton;
    QPushButton *registButton;
    QLineEdit *userNameInput;
    QLineEdit *passwordInput;
    QLabel *userNmaeText;
    QLabel *passwordText;

    void setupUi(QWidget *logWindow)
    {
        if (logWindow->objectName().isEmpty())
            logWindow->setObjectName(QStringLiteral("logWindow"));
        logWindow->resize(464, 365);
        loginButton = new QPushButton(logWindow);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(230, 220, 80, 20));
        registButton = new QPushButton(logWindow);
        registButton->setObjectName(QStringLiteral("registButton"));
        registButton->setGeometry(QRect(120, 220, 80, 20));
        userNameInput = new QLineEdit(logWindow);
        userNameInput->setObjectName(QStringLiteral("userNameInput"));
        userNameInput->setGeometry(QRect(230, 70, 161, 31));
        passwordInput = new QLineEdit(logWindow);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));
        passwordInput->setGeometry(QRect(230, 110, 161, 31));
        userNmaeText = new QLabel(logWindow);
        userNmaeText->setObjectName(QStringLiteral("userNmaeText"));
        userNmaeText->setGeometry(QRect(120, 80, 54, 12));
        passwordText = new QLabel(logWindow);
        passwordText->setObjectName(QStringLiteral("passwordText"));
        passwordText->setGeometry(QRect(120, 120, 54, 12));

        retranslateUi(logWindow);

        QMetaObject::connectSlotsByName(logWindow);
    } // setupUi

    void retranslateUi(QWidget *logWindow)
    {
        logWindow->setWindowTitle(QApplication::translate("logWindow", "Form", Q_NULLPTR));
        loginButton->setText(QApplication::translate("logWindow", "login", Q_NULLPTR));
        registButton->setText(QApplication::translate("logWindow", "regist", Q_NULLPTR));
        userNmaeText->setText(QApplication::translate("logWindow", "UserNmae", Q_NULLPTR));
        passwordText->setText(QApplication::translate("logWindow", "Passwords", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class logWindow: public Ui_logWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
