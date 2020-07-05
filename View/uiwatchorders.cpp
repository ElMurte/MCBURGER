#include "uiwatchorders.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <Model/order.h>
#include <View/visibleorderitem.h>
UIwatchOrders::UIwatchOrders(ControllerR *c, QWidget *parent):QWidget(parent),controller(c),inprep(new QWidget(this)),pronti(new QWidget(this)){
    setLayout(new QHBoxLayout);
    inprep->setLayout(new QVBoxLayout);inprep->setObjectName("widgetord");
    pronti->setLayout(new QVBoxLayout);pronti->setObjectName("widgetord");
    QLabel *t1=new QLabel("IN PREPARAZIONE");QLabel *t2=new QLabel("PRONTI");t1->setAlignment(Qt::AlignTop);t2->setAlignment(Qt::AlignTop);
    inprep->layout()->addWidget(t1);
    pronti->layout()->addWidget(t2);
    layout()->addWidget(inprep);
    layout()->addWidget(pronti);
    QFile file("Resources/style/style.css");
    file.open(QFile::ReadOnly);
    QString filesheet=QLatin1String(file.readAll());
    setStyleSheet(filesheet);
    }
void UIwatchOrders::showGestOrd(){
    show();
}

void UIwatchOrders::addorder(Order* i){
    inprep->layout()->addWidget(new GenericOrderItem(controller,i,inprep));
    update();
}

void UIwatchOrders::orderready(Order *i){
    QString ordine=QString::number(i->Get_NumOrder());
    GenericOrderItem*order=inprep->findChild<GenericOrderItem*>(ordine);
    order->setParent(nullptr);
    inprep->layout()->removeWidget(order);
    //delete order;
    pronti->layout()->addWidget(new GenericOrderItem(controller,i));
    update();
}

void UIwatchOrders::orderComplete(Order *i){
    QString ordine=QString::number(i->Get_NumOrder());
    GenericOrderItem*order=pronti->findChild<GenericOrderItem*>(ordine);
    order->setParent(nullptr);
    pronti->layout()->removeWidget(order);
    //delete order;
    update();
}
