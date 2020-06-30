//#include "mainwindow.h"
#include <iostream>
//#include <QApplication>
#include"Model/restorant.h"
#include"View/clientwindow.h"
#include"Control/controller.h"
#include "View/uicuoco.h"
#include<QApplication>
#include<QWindow>
using std::cout;using std::endl;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);a.setWindowIcon(QIcon("Resources/images/Icons/mcburgericon.png"));
    Restorant r;
    ControllerR c(&r);
    ClientWindow v(&c); //manca il costruttore
    c.set_View(&v);
    c.set_Cuoco(new UICuoco(&c));
    UIManager man(&c);
    c.set_Manager(&man);
    return a.exec();
}
