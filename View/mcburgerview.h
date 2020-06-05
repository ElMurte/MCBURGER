#ifndef MCBURGERVIEW_H
#define MCBURGERVIEW_H
#include<vector>
#include <QWidget>
class ControllerR;
class Product;
using std::vector;
class McBurgerView: public QWidget
{
    Q_OBJECT
protected:
    ControllerR*controller;
public:
    McBurgerView(ControllerR*c,QWidget*parent=nullptr);
protected slots:
    virtual void updateFromData(const vector<Product*>& products) = 0;
    virtual void updateFromData(const QString&) = 0;
};

#endif // MCBURGERVIEW_H
