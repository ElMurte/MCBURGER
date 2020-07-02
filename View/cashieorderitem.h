#ifndef CASHIEORDERITEM_H
#define CASHIEORDERITEM_H

#include <QWidget>
#include <View/visibleorderitem.h>
class ControllerR;
class Order;
class CashieOrderItem:public VisibleOrderItem
{
Q_OBJECT
protected:
QPushButton*complete;
public:
    CashieOrderItem(ControllerR*controller,Order*ord,QWidget*parent=nullptr);
public slots:
    void confirmorder();
signals:
    void confirmorder(Order*);
};

#endif // CASHIEORDERITEM_H
