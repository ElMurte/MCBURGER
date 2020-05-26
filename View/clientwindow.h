#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include <QWidget>
#include<Qt>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include "View/menubutton.h"
class ControllerR;
class ClientWindow : public QWidget {
    Q_OBJECT
private:
ControllerR*controller;
QScrollArea*menuproducts;
QHBoxLayout* productviews;
void addMenu();
void addButtons();
void setRestorantStyle();
public:
    ClientWindow(ControllerR* c,QWidget *parent = nullptr);
    ~ClientWindow()=default;
};
#endif // MAINWINDOW_H
