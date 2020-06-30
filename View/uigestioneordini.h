#ifndef UIGESTIONEORDINI_H
#define UIGESTIONEORDINI_H

#include <QWidget>
#include <QDialog>
#include "View/orditem.h"
class UIGestioneOrdini : public QDialog{
    Q_OBJECT
public:
    ControllerR*controller;
    QWidget* inprep;
    QWidget* pronti;
    QVector<Orditem*> widgetinprep;
    QVector<Orditem*> widgetpronti;
    UIGestioneOrdini(ControllerR*c,QWidget* parent=nullptr);
    void showGestOrd();
public slots:
    void addorder(Order*);
};

#endif // UIGESTIONEORDINI_H
