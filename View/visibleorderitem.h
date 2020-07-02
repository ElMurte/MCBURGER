#ifndef VISIBLEORDERITEM_H
#define VISIBLEORDERITEM_H
#include "View/genericorderitem.h"
#include <QWidget>
#include <QPushButton>
class VisibleOrderItem: public GenericOrderItem{
    Q_OBJECT
protected:
QPushButton*showord;
QDialog*showOrderUI;
public:
    VisibleOrderItem(ControllerR*controller,Order*ord,QWidget*parent=nullptr);
protected slots:
void showOrder();
signals:

};

#endif // VISIBLEORDERITEM_H
