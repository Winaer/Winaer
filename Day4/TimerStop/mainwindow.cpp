#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mytimer.setInterval(5000);
    connect(&mytimer,SIGNAL(timeout()),this,SLOT(unlockInputLine()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInButton_clicked(bool checked)
{
    QString userName = ui->userNameInput->text();
    QString password = ui->passwordInput->text();


    if(userName == "winaer"  &&  password == "123456")
    {
        QMessageBox::information(this,"tips","get through");
    }
    else
    {
        ui->userNameInput->setEnabled(false);
        ui->passwordInput->setEnabled(false);
        mytimer.start();
        QMessageBox::information(this,"waring","inputline is locked!");
    }
}

void MainWindow::unlockInputLine()
{
    ui->userNameInput->setEnabled(true);
    ui->passwordInput->setEnabled(true);
    mytimer.stop();

}








