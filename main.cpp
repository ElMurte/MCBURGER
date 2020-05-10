//#include "mainwindow.h"
#include <iostream>
//#include <QApplication>
#include"Model/restorant.h"
#include"View/clientwindow.h"
#include<QApplication>
using std::cout;using std::endl;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Restorant r;
    r.printproducts();
    ClientWindow m;
    m.show();
    return a.exec();
}
