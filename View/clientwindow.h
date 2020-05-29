#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include <QWidget>
#include<Qt>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include<QObject>
#include "View/menubutton.h"
#include <Control/controller.h>
#include <QDialog>
#include <QLabel>
class ControllerR;
class ClientWindow : public QWidget {
    Q_OBJECT
private:
ControllerR*controller;
QScrollArea*menuproducts;
QScrollArea* productviews;
QLayout* UI;
void addClientWidgets();
void addMenuButtons();
void addViewButtons();
void setRestorantStyle();
void Update();

public:
    ClientWindow(ControllerR* c,QWidget *parent = nullptr);
    ~ClientWindow()=default;void ShowErrorMessage(const QString &message){
        QDialog* messaggio=new QDialog(this);
        QVBoxLayout* layoutmessaggio=new QVBoxLayout(messaggio);
        layoutmessaggio->addWidget(new QLabel(message,messaggio));
        messaggio->show();
    }
};
#endif // MAINWINDOW_H
