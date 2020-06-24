#include "cart.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPixmap>
#include <QPushButton>
#include <QFile>
#include <Model/product.h>
Cart::Cart(ControllerR*c,QWidget* parent)
    :QDialog(parent),controller(&*c),mainchild(new QWidget(this)),tabprod(new QTableWidget(mainchild))
{
    setLayout(new QVBoxLayout(this));
    QLabel*ql=new QLabel("Carello");
    layout()->addWidget(ql);ql->setAlignment(Qt::AlignCenter);
    QString a("prodotto");QString b("quantita");QString cc("+ / -");QString d("prezzo");
    QStringList ll(QStringList()<<a<<b<<cc<<d);
    tabprod->setColumnCount(4);
    tabprod->setHorizontalHeaderLabels(ll);
    layout()->addWidget(tabprod);
    boxpushorder=new QDialogButtonBox(this);
    confirmordbtn=new QPushButton("Conferma");confirmordbtn->setObjectName("btnaddprodtocart");
    dontconfirmbtn=new QPushButton("Anulla");dontconfirmbtn->setObjectName("btnannprodtocart");
    boxpushorder->addButton(confirmordbtn,QDialogButtonBox::ButtonRole::AcceptRole);
    boxpushorder->addButton(dontconfirmbtn,QDialogButtonBox::ButtonRole::RejectRole);
    layout()->addWidget(boxpushorder);
}
void Cart::InsertRowProd(Product*it){
        bool sent=true;
        for(auto pp=vp.begin();pp!=vp.end();pp++)
            if((*pp)->Get_Nome()==it->Get_Nome()){
             sent=false;
             unsigned int q=(*pp)->get_Quantita();
             q=q+it->get_Quantita();
             (*pp)->set_Quantita(q);
             unsigned int riga=tabprod->findItems((*pp)->Get_Nome(),Qt::MatchFlag::MatchExactly).first()->row();
             //tabprod->removeCellWidget(riga,1);
             tabprod->setItem(riga,1,new QTableWidgetItem("x "+QString::number(q)));
             tabprod->setItem(riga,3,new QTableWidgetItem(QString::number(q)+"x"+QString::number(it->Get_Price())+"="+QString::number(q*it->Get_Price())));
            }
        if(sent){
        tabprod->insertRow(tabprod->rowCount());
        tabprod->setItem( tabprod->rowCount()-1,0,new QTableWidgetItem(QIcon(QPixmap(it->Get_Icon())),it->Get_Nome()));
        tabprod->setItem( tabprod->rowCount()-1,1,new QTableWidgetItem("x "+QString::number(it->get_Quantita())));
        tabprod->setItem( tabprod->rowCount()-1,2,new QTableWidgetItem("bottoni"));
        tabprod->setItem( tabprod->rowCount()-1,3,new QTableWidgetItem(QString::number(it->get_Quantita())+"x"+QString::number(it->Get_Price())+" ="+QString::number(it->Get_Price()*it->get_Quantita())));
        vp.push_back(it->clone());
        }
it->set_Quantita(1);
}
void Cart::ShowCartWindow(){
    open();
}
