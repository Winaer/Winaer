#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QPushButton *Pb1 = new QPushButton;
    QPushButton *Pb2 = new QPushButton("another button",this);

    Pb1->setParent(this);
    Pb1->setText("this is a button");
    Pb1->move(300,0);

    Pb2->move(100,100);
    setFixedSize(600,400);
    setWindowTitle("first day windows");
    connect(Pb2,&QPushButton::clicked,this,QMainWindow::close);

}

MainWindow::~MainWindow()
{

}
