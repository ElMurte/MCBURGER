#include "uigestioneordini.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QDebug>
#include <Model/order.h>
UIGestioneOrdini::UIGestioneOrdini(ControllerR*c,QWidget*parent):QDialog(parent),controller(c),inprep(new QWidget(this)),pronti(new QWidget(this)){
setLayout(new QHBoxLayout);
inprep->setLayout(new QVBoxLayout);inprep->setObjectName("widgetord");
pronti->setLayout(new QVBoxLayout);pronti->setObjectName("widgetord");
inprep->layout()->addWidget(new QLabel("IN PREPARAZIONE"));
pronti->layout()->addWidget(new QLabel("PRONTI"));
layout()->addWidget(inprep);
layout()->addWidget(pronti);
//itemtabella con bottoni
QFile file("Resources/style/style.css");
file.open(QFile::ReadOnly);
QString filesheet=QLatin1String(file.readAll());
setStyleSheet(filesheet);
}
void UIGestioneOrdini::showGestOrd(){
    open();
}

void UIGestioneOrdini::addorder(Order* i){
    inprep->layout()->addWidget(new Orditem(controller,i,inprep));
}

/*void UIGestioneOrdini::confirmorder(Order*i){
    i->setState(State::ready);
    QString ordine=QString::number(i->Get_NumOrder());
    Orditem*order=inprep->findChild<Orditem*>(ordine);
    if(order) qDebug()<<"esiste";
    else  qDebug()<<"NONNONNON esiste";
    pronti->layout()->addWidget(order);
    update();
}*/


