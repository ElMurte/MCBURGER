#include "visibleorderitem.h"
VisibleOrderItem::VisibleOrderItem(ControllerR *c, Order *ord, QWidget *parent)
    :GenericOrderItem(c,ord,parent),showord(new QPushButton("show")),showOrderUI(new QDialog(parent))
{
    showord->setObjectName("ordbtn");
    showOrderUI->setLayout(new QVBoxLayout);
    GenericOrderItem::layout()->addWidget(showord);
    connect(showord,SIGNAL(clicked()),this,SLOT(showOrder()));
}

void VisibleOrderItem::showOrder(){
    if ( showOrderUI->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = showOrderUI->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    for(auto it=(pord->get_Products()).begin();it!=(pord->get_Products().end());it++){
        showOrderUI->layout()->addWidget(new QLabel(QString::number((*it)->get_Quantita())+"x "+(*it)->Get_Nome()));
    }
    showOrderUI->open();
    showOrderUI->activateWindow();
}
