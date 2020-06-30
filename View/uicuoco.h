#ifndef UICUOCO_H
#define UICUOCO_H

#include <QWidget>
#include <QDialog>
class Order;
class Orditem;
class ControllerR;
class UICuoco:public QDialog{
    Q_OBJECT
private:
   ControllerR*controller;
   QWidget* inprep;
   QWidget* pronti;
public:
   void showGestOrd();
    UICuoco(ControllerR*c,QWidget*parent=nullptr);
public slots:
void addorder(Order*);
void aggiornalistaord(Order *i);
void orderready(Order*);
};

#endif // UICUOCO_H


