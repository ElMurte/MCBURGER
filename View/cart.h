#ifndef CART_H
#define CART_H
#include <QLabel>
#include <QDialog>
#include <vector>
#include <QTableWidget>
#include <QDialogButtonBox>
class Order;
class Product;
class Menu;
class ControllerR;
class AddRemButtonsCart;
class Cashier;
using std::vector;
class Cart : public QDialog{
    Q_OBJECT
public:
Cashier*cassiere;
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
vector <AddRemButtonsCart*>widgetbotadd;
Cart(Cashier*cas,ControllerR*c,QWidget* parent = nullptr);
void ShowCartWindow();
double Get_totale()const;

public slots:
void InsertRowProd(Product*p);
void createneworder();
void resetcarrello();
signals:
void createneworder(Order*);
public:

};

#endif // CART_H
