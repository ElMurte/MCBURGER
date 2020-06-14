#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include<Qt>
#include <QMainWindow>
#include <QScrollArea>
#include <QStackedLayout>
#include "mcburgerview.h"
#include "View/windowaddproduct.h"
class MenuButton;
class ClientWindow : public McBurgerView {
    Q_OBJECT
private:
QScrollArea*menuproducts;
QScrollArea* productviews;
QStackedLayout* UI;
QLayout *mainlayout;
QWidget* pointerproductwindow;
QWidget*tmp;
void addClientWidgets();
void addMenuButtons();
void setRestorantStyle();
void Update();
void addButtonstoWidget(const QHBoxLayout&);
void addViewButtons();
signals:
void buildbuttons(const vector<QString>&);
public:
    ClientWindow(ControllerR* c,QWidget *parent = nullptr);
    void UpdateRightArea(QVector<MenuButton*>v);
public slots:
    void addWindowAddProduct(const QString&,const QString&,const QString&,const double&);
protected slots:
    void updateFromData(const vector<Product *>& products)override;
    void updateFromData(const QString& qs)override;
};
#endif // MAINWINDOW_H
