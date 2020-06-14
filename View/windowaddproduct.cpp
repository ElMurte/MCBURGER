#include "windowaddproduct.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDialogButtonBox>
#include <QTextBrowser>
#include <QLabel>
#include <QFile>
#include <QPushButton>
#include <QCheckBox>
WindowAddProduct::WindowAddProduct(const QString& nome,const QString& imma,const QString& descriz,const double& prezzo,QWidget *parent) : QWidget(parent){
    // p->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
     setObjectName("WindowAddProd");
     setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
     QVBoxLayout*vbp=new QVBoxLayout(this);
     QScrollArea*sa=new QScrollArea(this);sa->setObjectName("areaaddprod");
     sa->setWidgetResizable(true);
     QWidget*psa=new QWidget(sa);
     QVBoxLayout*sal=new QVBoxLayout;

     QPixmap img("Resources/images/Burger/big-mc.png");//get immagine
     QLabel* picture=new QLabel;picture->setPixmap(imma);picture->setObjectName("imgprodotto");
     QLabel* name=new QLabel(nome);name->setObjectName("nomeprodotto");
     QTextBrowser* desc=new QTextBrowser();desc->setText(descriz); desc->setObjectName("descprodotto");
     QLabel* price=new QLabel(QString::number(prezzo)+" €");price->setObjectName("prezzoprodotto");
     //QWidget*qwsa=new QWidget;qwsa->setLayout(new QVBoxLayout);
     sal->addWidget(name);
     sal->addWidget(picture);
     sal->addWidget(desc);
     sal->addWidget(price);
     psa->setLayout(sal);
     sa->setWidget(psa);
     sa->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
     sa->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
     sa->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
     sa->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
     vbp->addWidget(sa);
     vbp->addWidget(new QPushButton("ciao"));
     setLayout(vbp);
     QFile file("Resources/style/style.css");
     file.open(QFile::ReadOnly);
     QString filesheet=QLatin1String(file.readAll());
     setStyleSheet(filesheet);
     show();
}
