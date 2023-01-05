#ifndef CODEQT_H
#define CODEQT_H

#include <QMainWindow>

namespace Ui {
class codeqt;
}

class codeqt : public QMainWindow
{
    Q_OBJECT

public:
    explicit codeqt(QWidget *parent = 0);
    ~codeqt();

private:
    Ui::codeqt *ui;
};

#endif // CODEQT_H
