#ifndef PRODUCTBUTTON_H
#define PRODUCTBUTTON_H
#include <QAbstractButton>
#include <QToolButton>
class Product;
class ProductButton : public QToolButton{
Q_OBJECT
signals:
void clickedCell(Product*);
private:
    Product*prodp;
private slots:
void fakehandleclick();
public:
    ProductButton(Product*p, QWidget *parent=nullptr);
};

#endif // PRODUCTBUTTON_H
