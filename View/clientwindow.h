#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include<Qt>
#include <QMainWindow>
#include <QScrollArea>
#include <QStackedLayout>
#include "mcburgerview.h"
class MenuButton;
class ClientWindow : public McBurgerView {
    Q_OBJECT
private:
QScrollArea*menuproducts;
QScrollArea* productviews;
QStackedLayout* UI;
QLayout *mainlayout;
void addClientWidgets();
void addMenuButtons();
void setRestorantStyle();
void Update();
void addButtonstoWidget(const QHBoxLayout&);
QScrollArea* addViewButtons();
signals:
void buildbuttons(const vector<QString>&);
public:
    ClientWindow(ControllerR* c,QWidget *parent = nullptr);
    void UpdateRightArea(QVector<MenuButton*>v);
protected slots:
    void updateFromData(const vector<Product *>& products)override;
    void updateFromData(const QString& qs)override;
};
#endif // MAINWINDOW_H
