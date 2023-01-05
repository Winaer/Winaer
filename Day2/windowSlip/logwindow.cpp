#include "logwindow.h"
#include "ui_logwindow.h"
#include "mainwindow.h"
#include <QDebug>

logWindow::logWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logWindow)
{
    ui->setupUi(this);
}

logWindow::~logWindow()
{
    delete ui;
}

void logWindow::on_loginButton_clicked()
{
    QString userName = ui->userNameInput->text();
    QString password = ui->passwordInput->text();

    if ((userName == "winaer")&&(password == "123456"))

    {
        QMainWindow *newWindow = new QMainWindow;
        newWindow->show();

        this->hide();
    }
    else
    {
        qDebug()<<"wrong password!";
    }

}
