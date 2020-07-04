#include "uicuoco.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QDebug>
#include <Model/order.h>
#include <View/orditem.h>
#include "Model/cooker.h"
UICuoco::UICuoco(ControllerR *c,Cooker*cook, QWidget *parent):QWidget(parent),cuoco(cook),controller(c),inprep(new QWidget(this)){
    setLayout(new QHBoxLayout);
    inprep->setLayout(new QVBoxLayout);inprep->setObjectName("widgetord");
    inprep->layout()->addWidget(new QLabel("IN PREPARAZIONE"));
    layout()->addWidget(inprep);
    //itemtabella con bottoni
    QFile file("Resources/style/style.css");
    file.open(QFile::ReadOnly);
    QString filesheet=QLatin1String(file.readAll());
    setStyleSheet(filesheet);
}

void UICuoco::showGestOrd(){
    show();
}

void UICuoco::addorder(Order* i){
    inprep->layout()->addWidget(new Orditem(controller,i,inprep));
    update();
}
void UICuoco::orderready(Order*i){
cuoco->setstateready(i);
QString ordine=QString::number(i->Get_NumOrder());
Orditem*order=inprep->findChild<Orditem*>(ordine);
inprep->layout()->removeWidget(order);
delete order;
update();
}

void UICuoco::aggiornalistaord(Order *i){
    QString ordine=QString::number(i->Get_NumOrder());
    inprep->layout()->addWidget(new Orditem(controller,i,inprep));
    update();
}
