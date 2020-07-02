#ifndef GENERICORDERITEM_H
#define GENERICORDERITEM_H
#include <Control/controller.h>
#include <QWidget>
class UIGestioneOrdini;
class Order;
class GenericOrderItem:public QWidget{
    Q_OBJECT
protected:
    Order*pord;
    ControllerR*controller;
public:
    GenericOrderItem(ControllerR*controller,Order*ord,QWidget*parent=nullptr);
public slots:

signals:

};

#endif // GENERICORDERITEM_H

