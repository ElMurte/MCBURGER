#include "uigestioneordini.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <Model/order.h>
#include <View/visibleorderitem.h>
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
    activateWindow();
    open();
}

void UIGestioneOrdini::addorder(Order* i){
    inprep->layout()->addWidget(new VisibleOrderItem(controller,i,inprep));
    update();
}


