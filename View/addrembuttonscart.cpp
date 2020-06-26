#include "addrembuttonscart.h"
#include "QHBoxLayout"
#include "Model/product.h"
#include "View/cart.h"
#include <QAbstractItemView>
AddRemButtonsCart::AddRemButtonsCart(Cart*c,Product *pp,unsigned int row, QWidget *parent):
 QWidget(parent),carel(c),p(pp),riga(row),addpbtn(new QPushButton("+")),rempbtn(new QPushButton("-"))
{
    setLayout(new QHBoxLayout);
    layout()->addWidget(addpbtn);layout()->addWidget(rempbtn);
    addpbtn->setObjectName("btncart");rempbtn->setObjectName("btncart");
    connect(rempbtn,SIGNAL(clicked()),this,SLOT(remquantita_tocart()));
    connect(addpbtn,SIGNAL(clicked()),this,SLOT(add_quantita_tocart()));
}

void AddRemButtonsCart::remquantita_tocart(){
    uint quant=(p->get_Quantita()-1);
    if(quant==0){
        for(auto it=carel->vp.begin();it!=carel->vp.end();it++){
            if(p->Get_Nome()==(*it)->Get_Nome()){
                it=carel->vp.erase(it);
                for(auto it=carel->widgetbotadd.begin();it!=carel->widgetbotadd.end();it++){
                    if( (*it)->riga>riga)
                        (*it)->riga--;//BUG SCOMPARSA BOTTONI DOPO RIMOZIONI QUANDO MI RIMANGONO SOLO 2 RIGHE
            }
                carel->tabprod->removeRow(riga);

               // riga=riga-1;
               if(carel->vp.empty()){
                    carel->totale->setText("TOTALE: 0");
                    carel->tabprod->reset();
                }
               else  carel->totale->setText("TOTALE: "+ QString::number(carel->Get_totale()));
               break;//stop you find it
            }
        }

    }
    else
    {
        carel->tabprod->item(riga,1)->setText("x "+QString::number(quant));
        p->set_Quantita(quant);
        carel->tabprod->item(riga,3)->setText(QString::number(quant)+"x "+QString::number(p->Get_Price())+" = "+QString::number(quant*p->Get_Price()));
        carel->totale->setText("TOTALE: "+ QString::number(carel->Get_totale()));

        //carel->tabprod->reset();
    }
    //emit rimossounariga();
    //rimuovi la riga e rimetti a 1 la quantita del puntatore se non clonato
        //p->set_Quantita(p->get_Quantita()-1);

}

void AddRemButtonsCart::add_quantita_tocart(){
    unsigned int quant=(p->get_Quantita()+1);
    carel->tabprod->item(riga,1)->setText("x "+QString::number(quant));
        p->set_Quantita(quant);
         carel->tabprod->item(riga,3)->setText(QString::number(quant)+"x "+QString::number(p->Get_Price())+" = "+QString::number(quant*p->Get_Price()));
    carel->totale->setText("TOTALE: "+ QString::number(carel->Get_totale()));
     //carel->tabprod->reset(); // QAbstractItemView::carel
}

