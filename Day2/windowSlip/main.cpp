#include "mainwindow.h"
#include <QApplication>
#include "loginwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    logWindow w;
    w.show();

    return a.exec();
}
