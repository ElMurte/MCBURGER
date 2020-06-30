#ifndef ORDITEM_H
#define ORDITEM_H
#include <Control/controller.h>
#include <QWidget>
class UIGestioneOrdini;
class Order;
class Orditem:public QWidget{
    Q_OBJECT
private:
    Order*pord;
    ControllerR*controller;
public:
    Orditem(ControllerR*controller,Order*ord,QWidget*parent=nullptr);
public slots:
    void confirmorder();
signals:
    void confirmorder(Order*);
};

#endif // ORDITEM_H
