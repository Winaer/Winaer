#include "codeqt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    codeqt w;
    w.show();

    return a.exec();
}
