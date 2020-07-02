#include "visibleorderitem.h"
#include <QDebug>
VisibleOrderItem::VisibleOrderItem(ControllerR *c, Order *ord, QWidget *parent)
    :GenericOrderItem(c,ord,parent),showord(new QPushButton("show")),showOrderUI(new QDialog(parent))
{
    showord->setObjectName("ordbtn");
    showOrderUI->setLayout(new QVBoxLayout);
    GenericOrderItem::layout()->addWidget(showord);
    connect(showord,SIGNAL(clicked()),this,SLOT(showOrder()));
}

void VisibleOrderItem::showOrder(){

    for(auto it=(pord->get_Products()).begin();it!=(pord->get_Products().end());it++){
        showOrderUI->layout()->addWidget(new QLabel(QString::number((*it)->get_Quantita())+"x "+(*it)->Get_Nome()));
    }
    showOrderUI->open();
}
