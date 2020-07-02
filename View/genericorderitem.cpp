#include "genericorderitem.h"
#include "orditem.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <View/uigestioneordini.h>
#include <Model/order.h>
#include "Control/controller.h"
GenericOrderItem::GenericOrderItem(ControllerR *c, Order *ord, QWidget *parent):QWidget(parent),pord(ord),controller(c)
{
    setLayout(new QHBoxLayout);setObjectName(QString::number(ord->Get_NumOrder()));
    layout()->addWidget(new QLabel(QString::number(ord->Get_NumOrder())));
}



