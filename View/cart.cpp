#include "cart.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPixmap>
#include <QPushButton>
#include <QFile>
#include <Model/product.h>
#include <Model/menu.h>
#include <View/addrembuttonscart.h>
Cart::Cart(ControllerR*c,QWidget* parent)
    :QDialog(parent),controller(&*c),mainchild(new QWidget(this)),tabprod(new QTableWidget(mainchild)),
      totale(new QLabel("ND"))
{
    setObjectName("cart");
    tabprod->setObjectName("tabcart");
    setLayout(new QVBoxLayout(this));
    QLabel*ql=new QLabel("Carello");
    layout()->addWidget(ql);ql->setAlignment(Qt::AlignCenter);
    QString a("prodotto");QString b("quantita");QString cc("+ / -");QString d("prezzo");
    QStringList ll(QStringList()<<a<<b<<cc<<d);
    tabprod->setColumnCount(4);
    tabprod->setHorizontalHeaderLabels(ll);
    layout()->addWidget(tabprod);
    layout()->addWidget(totale);
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
             QTableWidgetItem*qtwi=new QTableWidgetItem("x "+QString::number(q));
              QTableWidgetItem*qtwi1=new QTableWidgetItem(QString::number(q)+"x"+QString::number(it->Get_Price())+"="+QString::number(q*it->Get_Price()));
             tabprod->setItem(riga,1,qtwi);
             tabprod->setItem(riga,3,qtwi1);
             //qtwi->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
             //qtwi1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
            }
        if(sent){
            tabprod->insertRow(tabprod->rowCount());
            tabprod->setRowHeight(tabprod->rowCount()-1,200);
            QTableWidgetItem*nome=new QTableWidgetItem(QIcon(QPixmap(it->Get_Icon())),it->Get_Nome());
            QTableWidgetItem*quantita=new QTableWidgetItem("x "+QString::number(it->get_Quantita()));
            QTableWidgetItem*totaleparziae=new QTableWidgetItem(QString::number(it->get_Quantita())+"x"+QString::number(it->Get_Price())+" ="+QString::number(it->Get_Price()*it->get_Quantita()));
            nome->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
            quantita->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
            totaleparziae->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
            tabprod->setItem( tabprod->rowCount()-1,0,nome);
            tabprod->setColumnWidth(0,250);
            tabprod->setItem( tabprod->rowCount()-1,1,quantita);
            auto* pp=it->clone();vp.push_back(pp);
           tabprod->setCellWidget(tabprod->rowCount()-1,2,new AddRemButtonsCart(this,pp,tabprod->rowCount()-1,this));
            tabprod->setItem( tabprod->rowCount()-1,3,totaleparziae);
            }
        totale->setText("TOTALE: "+ QString::number(Get_totale()));
        tabprod->setMinimumWidth(650);
        tabprod->setMinimumHeight(400);
        it->set_Quantita(1);
}

void Cart::ShowCartWindow(){
    open();
}

double Cart::Get_totale() const
{
    double i=0;
        for(auto it=vp.begin();it!=vp.end();it++){
            i+=((*it)->Get_Price())*(*it)->get_Quantita();
        }
        for(auto it=vm.begin();it!=vm.end();it++){
            i+=(*it)->Get_Price();//manca quantita per menu
        }
        return i;
}
