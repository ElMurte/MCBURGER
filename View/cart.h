#ifndef CART_H
#define CART_H
#include <QLabel>
#include <QDialog>
#include <vector>
#include <QTableWidget>
#include <QDialogButtonBox>
class Product;
class Menu;
class ControllerR;
class AddRemButtonsCart;
using std::vector;
class Cart : public QDialog{
    Q_OBJECT
public:
vector <Product*>vp;
vector <Menu*>vm;
ControllerR* controller;
QWidget*mainchild;
QTableWidget*tabprod;
QLabel*totale;
AddRemButtonsCart*plusminprodbtns;
QDialogButtonBox*boxpushorder;
QPushButton*confirmordbtn;
QPushButton*dontconfirmbtn;

Cart(ControllerR*c,QWidget* parent = nullptr);
void ShowCartWindow();
double Get_totale()const;

public slots:
void InsertRowProd(Product*p);
signals:

public:

};

#endif // CART_H
