#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>

namespace Ui {
class logWindow;
}

class logWindow : public QWidget
{
    Q_OBJECT

public:
    explicit logWindow(QWidget *parent = 0);
    ~logWindow();

private slots:
    void on_loginButton_clicked();

private:
    Ui::logWindow *ui;
};

#endif // LOGWINDOW_H
