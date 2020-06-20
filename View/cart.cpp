#include "cart.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPixmap>
#include <QPushButton>
#include <QFile>
Cart::Cart(QWidget* parent):QDialog(parent){
setObjectName("carello");
setLayout(new QVBoxLayout());

/*headerfinestra*/
layout()->addWidget(new QLabel("carello"));
QHBoxLayout*headertablayout=new QHBoxLayout;
headertablayout->addWidget(new QLabel("prodotto"));
headertablayout->addWidget(new QLabel("immagine-prodotto"));
headertablayout->addWidget(new QLabel("quantita"));
headertablayout->addWidget(new QLabel("prezzo"));
headertablayout->addWidget(new QLabel("+/-"));
QWidget*headertab=new QWidget();headertab->setLayout(headertablayout);

/*Carrello con i vari item*/
QScrollArea* pSA=new QScrollArea(this);
pSA->setLayout(new QVBoxLayout);
QWidget*pSAitem=new QWidget();
QLabel*imgprod=new QLabel;imgprod->setObjectName("imgprod");
QLabel* quant=new QLabel("x2");
QLabel* price=new QLabel("4.6 euro");
QPushButton*moreofthis=new QPushButton("+",pSAitem);moreofthis->setObjectName("btncart");
QPushButton*lessofthis=new QPushButton("-",pSAitem);lessofthis->setObjectName("btncart");
pSAitem->setLayout(new QHBoxLayout());pSAitem->setObjectName("prodottocarello");
imgprod->setAlignment(Qt::AlignCenter);
imgprod->setPixmap(QPixmap("Resources/images/Burger/big-mc.png"));
pSAitem->layout()->addWidget(new QLabel("BIG MC"));
pSAitem->layout()->addWidget(imgprod);
pSAitem->layout()->addWidget(quant);
pSAitem->layout()->addWidget(price);
pSAitem->layout()->addWidget(moreofthis);
pSAitem->layout()->addWidget(lessofthis);
pSA->layout()->addWidget(pSAitem);//cartitem


layout()->addWidget(headertab);
layout()->addWidget(pSA);
setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
QFile file("Resources/style/style.css");
file.open(QFile::ReadOnly);
QString filesheet=QLatin1String(file.readAll());
setStyleSheet(filesheet);
}

void Cart::ShowCartWindow(){
    open();
}
