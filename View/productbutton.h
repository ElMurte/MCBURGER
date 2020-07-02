#ifndef PRODUCTBUTTON_H
#define PRODUCTBUTTON_H
#include <QAbstractButton>
#include <QToolButton>
#include <QMouseEvent>
class Product;
class ProductButton : public QToolButton{
Q_OBJECT
signals:
void clickedCell(Product*);    void rightClicked();
private:
    Product*prodp;
protected:

private slots:
void fakehandleclick();
void mouseReleaseEvent(QMouseEvent *e);
void onrightClick();
public:
    ProductButton(Product*p, QWidget *parent=nullptr);
};

#endif // PRODUCTBUTTON_H


