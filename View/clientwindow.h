#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include<Qt>
#include <QMainWindow>
#include <QScrollArea>
#include <QStackedLayout>
#include "mcburgerview.h"
#include "View/windowaddproduct.h"
#include "View/cart.h"
class MenuButton;
class UIGestioneOrdini;
class ClientWindow : public McBurgerView {
    Q_OBJECT
private:
QScrollArea*menuproducts;
QScrollArea* productviews;
QStackedLayout* UI;
QLayout *mainlayout;
QWidget*topmenuwidget;
WindowAddProduct* pointerproductwindow;
Cart* cart;
UIGestioneOrdini*UIgestord;
void addClientWidgets();
void addLeftMenuButtons();
void setRestorantStyle();
void Update();
void addButtonstoWidget(const QHBoxLayout&);
void addinitialButtonstoUILayout();
void createsubmenus();
void addtopmenuwidgets();
signals:
void buildbuttons(const vector<QString>&);
void insertrow(Product*);
void addordnum(unsigned int);
public:
    ClientWindow(ControllerR* c,QWidget *parent = nullptr);
    void UpdateRightArea(QVector<MenuButton*>v);
public slots:
        void aggiornalistaord(unsigned int);
        void showGestOrd();
protected slots:
   // void setnullptrtoaddprodwin();

    void ShowCart();
    void AddProducttoCart(Product*);
    void addWindowAddProduct(Product*);
    void updateFromData(const vector<Product *>& products)override;
    void updateFromData(const QString& qs)override;
};
#endif // MAINWINDOW_H
