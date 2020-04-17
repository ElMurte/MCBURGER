//#include "mainwindow.h"
#include <iostream>
//#include <QApplication>
#include"./Model/Dlist.h"
using std::cout;using std::endl;
int main(int argc, char *argv[])
{
   /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    Dlist<int>diecivoltetre(10,3);
    for(auto it=diecivoltetre.begin();it!=diecivoltetre.end();it++)
        cout<<*it;
    cout<<endl;
    diecivoltetre.push_back(1);
    for(auto it=diecivoltetre.begin();it!=diecivoltetre.end();it++)
        cout<<*it;
    cout<<endl;
    diecivoltetre.pop_front();
    for(auto it=diecivoltetre.begin();it!=diecivoltetre.end();it++)
        cout<<*it;
    diecivoltetre.pop_back();
    cout<<endl;
    for(auto it=diecivoltetre.begin();it!=diecivoltetre.end();it++)
        cout<<*it;
    cout<<endl;
    diecivoltetre.push_front(2);
    for(auto it=diecivoltetre.begin();it!=diecivoltetre.end();++it)
        cout<<*it;
}
