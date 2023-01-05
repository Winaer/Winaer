#include "codeqt.h"
#include "ui_codeqt.h"
#include <QLineEdit>
codeqt::codeqt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::codeqt)  //主窗口的构造函数
{
    ui->setupUi(this);
    //创建输入框对象
    QLineEdit *usrle=new QLineEdit(this); //this表示当前主窗口，作为输入框的父窗口
    //设置输入框的位置，宽，高(默认在左上角显示，效果不好看)
    usrle->setGeometry(100,50,300,50);
    usrle->setPlaceholderText("请输入用户名");

}

codeqt::~codeqt()
{
    delete ui;
}
