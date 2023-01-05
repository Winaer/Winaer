#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mytimer.setInterval(1000);
    connect(&mytimer,SIGNAL(timeout()),this,SLOT(printTime()));
    //connect(&mytimer,SIGNAL(timeout()),this,SLOT(fun()));
    mytimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: printTime()
{
    QDate mydate = QDate::currentDate();
    QTime mytime = QTime::currentTime();

    ui->years->display(mydate.toString("yyyy-MM-dd"));
    ui->times->display(mytime.toString("hh:mm:ss"));
}
