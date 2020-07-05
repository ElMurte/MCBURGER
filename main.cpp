//#include "mainwindow.h"
#include <iostream>
//#include <QApplication>
#include"Model/restorant.h"
#include"View/clientwindow.h"
#include"Control/controller.h"
#include "View/uicuoco.h"
#include "View/loginui.h"
#include<QApplication>
#include<QWindow>
using std::cout;using std::endl;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);a.setWindowIcon(QIcon("Resources/images/Icons/mcburgericon.png"));
   Restorant r;
    ControllerR c(&r);
    LoginUI login(&c);
    return a.exec();
}
