#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QMainWindow>

namespace Ui{
class logWindow;

}

class logWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit logWindow(QWidget *parent = 0);
    ~ logWindow();

private slots:
    on_logBt_clicked();

private:
    Ui::logWindow *ui;
};


#endif // LOGINWINDOW_H
