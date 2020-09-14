#include "cart.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPixmap>
#include <QPushButton>
#include <QFile>
#include <Model/product.h>
#include <Model/menu.h>
#include <Control/controller.h>
#include <View/addrembuttonscart.h>
#include <Model/order.h>
#include <QMessageBox>
Cart::Cart(Cashier*cas,ControllerR*c,QWidget* parent)
    :QDialog(parent),cassiere(cas),controller(&*c),mainchild(new QWidget(this)),tabprod(new QTableWidget(mainchild)),
      totale(new QLabel("TOTALE: 0 euro"))
{
    setObjectName("cart");
    tabprod->setObjectName("tabcart");tabprod->setIconSize(QSize(120, 120));
    setLayout(new QVBoxLayout(this));
    QLabel*ql=new QLabel("Carello");
    QWidget*primo=new QWidget(this);primo->setLayout(new QHBoxLayout);
    QPushButton*resetcarel=new QPushButton(QIcon(QPixmap("Resources/images/Icons/reset-icon.png")),"reset");resetcarel->setObjectName("btnrescar");
    primo->layout()->addWidget(resetcarel);primo->layout()->addWidget(ql);
    layout()->addWidget(primo);ql->setAlignment(Qt::AlignCenter);
    QString a("prodotto");QString b("quantita");QString cc("+ / -");QString d("prezzo");
    QStringList ll(QStringList()<<a<<b<<cc<<d);
    tabprod->setColumnCount(4);
    tabprod->setHorizontalHeaderLabels(ll);
    layout()->addWidget(tabprod);
    layout()->addWidget(totale);totale->setAlignment(Qt::AlignRight);
    boxpushorder=new QDialogButtonBox(this);
    confirmordbtn=new QPushButton("Conferma");confirmordbtn->setObjectName("btnaddprodtocart");
    dontconfirmbtn=new QPushButton("Anulla");dontconfirmbtn->setObjectName("btnannprodtocart");
    boxpushorder->addButton(confirmordbtn,QDialogButtonBox::ButtonRole::AcceptRole);
    boxpushorder->addButton(dontconfirmbtn,QDialogButtonBox::ButtonRole::RejectRole);
    layout()->addWidget(boxpushorder);
    connect(confirmordbtn,SIGNAL(clicked()),this,SLOT(createneworder()));//TODO
    connect(this,SIGNAL(createneworder(Order*)),controller,SLOT(createneworder(Order*)));//TODO
    connect(dontconfirmbtn,SIGNAL(clicked()),this,SLOT(reject()));
    connect(resetcarel,SIGNAL(clicked()),this,SLOT(resetcarrello()));
}
void Cart::InsertRowProd(Product*it){
    double prezzoiniz=it->Get_Price();QString dim;bool havesize=false;
    if(it->Get_Size()==small){ it->SetPrice(it->Get_Price());
        dim=" small";havesize=true;
    }
    if(it->Get_Size()==medium){ it->SetPrice(it->Get_Price()+0.5);
        dim=" medium";havesize=true;
    }
    if(it->Get_Size()==big){ it->SetPrice(it->Get_Price()+1);
        dim=" big";havesize=true;
    }
        bool sent=true;
        for(auto pp=vp.begin();pp!=vp.end();pp++)
            if(*(*pp)==*it){
             sent=false;
             unsigned int q=(*pp)->get_Quantita();
             q=q+it->get_Quantita();
             (*pp)->set_Quantita(q);
             unsigned int riga=tabprod->findItems((*pp)->Get_Nome()+dim,Qt::MatchFlag::MatchExactly).first()->row();
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
            QTableWidgetItem*nome=new QTableWidgetItem(QIcon(QPixmap(it->Get_Icon())),it->Get_Nome()+dim);
            QTableWidgetItem*quantita=new QTableWidgetItem("x "+QString::number(it->get_Quantita()));
            QTableWidgetItem*totaleparziae=new QTableWidgetItem(QString::number(it->get_Quantita())+"x"+QString::number(it->Get_Price())+" ="+QString::number(it->Get_Price()*it->get_Quantita()));
            nome->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
            quantita->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
            totaleparziae->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
            tabprod->setItem( tabprod->rowCount()-1,0,nome);
            tabprod->setColumnWidth(0,250);
            tabprod->setItem( tabprod->rowCount()-1,1,quantita);
            auto* pp=it->clone();vp.push_back(pp);
            auto*widgetbotaddrem=new AddRemButtonsCart(this,pp,tabprod->rowCount()-1);
           tabprod->setCellWidget(tabprod->rowCount()-1,2,widgetbotaddrem);
            widgetbotadd.push_back(widgetbotaddrem);
            tabprod->setItem( tabprod->rowCount()-1,3,totaleparziae);
            }
        totale->setText("TOTALE: "+ QString::number(Get_totale())+" euro");
        tabprod->setMinimumWidth(700);
        tabprod->setMinimumHeight(480);
        it->set_Quantita(1);it->SetPrice(prezzoiniz);
        if(havesize)
            it->SetSize(small);
}

void Cart::createneworder(){
 Order*ord=cassiere->createneworder(vp);
    if(ord && controller->cucinaison()){
    emit createneworder(ord);
    accept();
    }
    else{
        QMessageBox a(this);
        if(!ord)
        a.setText("CARELLO VUOTO aggiungere dei prodotti prima");
        else a.setText("CUCINA non Avviata contattere il manager o un cuoco");
        a.exec();
    }
}

void Cart::resetcarrello(){
    if(!vp.empty()){
        vp.clear();
    while(tabprod->rowCount())//togli tutte le righe dalla tabella
    tabprod->removeRow(0);
    totale->setText("TOTALE : 0 euro");
    }
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


