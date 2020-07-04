#ifndef WINDOWADDPRODUCT_H
#define WINDOWADDPRODUCT_H
#include <QDialog>


class ControllerR;
class Product;
class QLabel;
class QTextBrowser;
class WindowAddProduct : public QDialog{
    Q_OBJECT
private:
ControllerR*controller;
Product* p;
QPixmap img;//get immagine
QLabel* picture;
QLabel* name;
QTextBrowser* desc;
QLabel* price;
QLabel* quantita;
QWidget*psa;
QWidget*prodwithsize;
void setStyle();
protected:
public:
    WindowAddProduct(ControllerR* c,QWidget* parent = nullptr);
    void showWindow(Product*pp);
public slots:
void remquantita();
void addquantita();
void changesizesmall();
void changesizemedium();
void changesizebig();
void addProdtoCart();
signals:
void addthisprod(Product*);
};

#endif // WINDOWADDPRODUCT_H
