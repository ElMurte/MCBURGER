#include "cashieorderitem.h"

CashieOrderItem::CashieOrderItem(ControllerR *c, Order *ord, QWidget *parent)
    :VisibleOrderItem(c,ord,parent),complete(new QPushButton("complete"))
{
    complete->setObjectName("ordbtn");
    VisibleOrderItem::GenericOrderItem::layout()->addWidget(complete);
    connect(this,SIGNAL(confirmorder(Order*)),controller,SLOT(orderComplete(Order*)));
    connect(complete,SIGNAL(clicked()),this,SLOT(confirmorder()));
}
void CashieOrderItem::confirmorder(){
    pord->setState(State::complete);
    emit confirmorder(pord);
}
