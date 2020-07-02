#ifndef ORDITEM_H
#define ORDITEM_H
#include <Control/controller.h>
#include "View/visibleorderitem.h"
#include <QWidget>
class UIGestioneOrdini;
class Order;
class Orditem:public VisibleOrderItem{
    Q_OBJECT
private:
    QPushButton*confirmord;
public:
    Orditem(ControllerR*controller,Order*ord,QWidget*parent=nullptr);
public slots:
    void confirmorder();
signals:
    void confirmorder(Order*);
};

#endif // ORDITEM_H
