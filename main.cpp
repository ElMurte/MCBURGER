//#include "mainwindow.h"
#include <iostream>
//#include <QApplication>
#include"Model/restorant.h"
#include"View/clientwindow.h"
#include"Control/controller.h"
#include<QApplication>
#include<QWindow>
using std::cout;using std::endl;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Restorant r;
    ControllerR c(&r);
    ClientWindow v(&c); //manca il costruttore
    c.set_View(&v);
    v.show();
    return a.exec();
}
