#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include<Qt>
#include <QMainWindow>
#include <QScrollArea>
#include <QStackedLayout>
#include "mcburgerview.h"
#include "View/windowaddproduct.h"
#include "View/cart.h"
class Cashier;
class MenuButton;
class UIGestioneOrdini;
class Order;
class ClientWindow : public McBurgerView {
    Q_OBJECT
private:
    void addClientWidgets();
    void addLeftMenuButtons();
    void setRestorantStyle();
    //void Update();
    void addButtonstoWidget(const QHBoxLayout&);
    void addinitialButtonstoUILayout();
    void createsubmenus();
    void addtopmenuwidgets();
    void buildsubmenusweets();
protected:
Cashier*cassiere;
QScrollArea*menuproducts;
QScrollArea* productviews;
QStackedLayout* UI;
QLayout *mainlayout;
QWidget*topmenuwidget;
WindowAddProduct* pointerproductwindow;
Cart* cart;
UIGestioneOrdini*UIgestord;

signals:
void buildbuttons(const vector<QString>&);
void insertrow(Product*);
void addordnum(Order*);

public:
    ClientWindow(ControllerR* c,Cashier*cass,QWidget *parent = nullptr);
    void UpdateRightArea(QVector<MenuButton*>v);
public slots:
        void aggiornalistaord(Order*);
        void showGestOrd();
        void orderready(Order*i);
        void orderComplete(Order*);
protected slots:
   // void setnullptrtoaddprodwin();

    void ShowCart();
    void AddProducttoCart(Product*);
    void addWindowAddProduct(Product*);
    void updateFromData(const vector<Product *>& products)override;
};
#endif // MAINWINDOW_H
