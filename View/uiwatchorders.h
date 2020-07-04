#ifndef UIWATCHORDERS_H
#define UIWATCHORDERS_H

#include <QWidget>
#include "View/genericorderitem.h"
class UIwatchOrders:public QWidget{
    Q_OBJECT
public:
    ControllerR*controller;
    QWidget* inprep;
    QWidget* pronti;
    QVector<Orditem*> widgetinprep;
    QVector<Orditem*> widgetpronti;
    UIwatchOrders(ControllerR*c,QWidget* parent=nullptr);
    void showGestOrd();
public slots:
    void addorder(Order*);
    void orderready(Order*);
    void orderComplete(Order*);
};

#endif // UIWATCHORDERS_H
