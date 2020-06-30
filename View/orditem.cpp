#include "orditem.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <View/uigestioneordini.h>
#include <Model/order.h>
#include "Control/controller.h"
Orditem::Orditem(ControllerR*c,Order*ord,QWidget*parent):QWidget(parent),pord(ord),controller(c){
setLayout(new QHBoxLayout);setObjectName(QString::number(ord->Get_NumOrder()));
layout()->addWidget(new QLabel(QString::number(ord->Get_NumOrder())));
QPushButton*showord=new QPushButton("show");showord->setObjectName("ordbtn");
QPushButton*confirmord=new QPushButton("confirm");confirmord->setObjectName("ordbtn");
QPushButton*cancelord=new QPushButton("cancel");cancelord->setObjectName("ordbtn");
layout()->addWidget(showord);
layout()->addWidget(confirmord);
layout()->addWidget(cancelord);

connect(this,SIGNAL(confirmorder(Order*)),controller,SLOT(orderready(Order*)));
connect(confirmord,SIGNAL(clicked()),this,SLOT(confirmorder()));
}

void Orditem::confirmorder(){
    pord->setState(ready);
    emit confirmorder(pord);
}
