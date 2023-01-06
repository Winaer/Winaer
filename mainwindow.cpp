#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInButton_clicked()
{
    QString userName = ui->userNameLe->text();
    QString password = ui->passwordLe->text();


    if  (userName =="winaer" && password == "123456")
    {
        QMessageBox::information(this,"information","get through!");
    }
    else
    {
        QMessageBox::critical(this,"warning","wrong message!");
    }

}
