#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void unlockInputLine();

    void on_signInButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QTimer mytimer;
};

#endif // MAINWINDOW_H
