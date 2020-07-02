#include "orditem.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <View/uigestioneordini.h>
#include <Model/order.h>
#include "Control/controller.h"
Orditem::Orditem(ControllerR*c,Order*ord,QWidget*parent):VisibleOrderItem(c,ord,parent),confirmord(new QPushButton("confirm"))
{
confirmord->setObjectName("ordbtn");
layout()->addWidget(confirmord);

connect(this,SIGNAL(confirmorder(Order*)),controller,SLOT(orderready(Order*)));
connect(confirmord,SIGNAL(clicked()),this,SLOT(confirmorder()));
}

void Orditem::confirmorder(){
    emit confirmorder(pord);
}
