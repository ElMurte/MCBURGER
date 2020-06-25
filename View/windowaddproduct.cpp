#include "windowaddproduct.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDialogButtonBox>
#include <QTextBrowser>
#include <QLabel>
#include <QFile>
#include <QPushButton>
#include <QCheckBox>
#include <Control/controller.h>
#include <Model/product.h>

WindowAddProduct::WindowAddProduct(ControllerR* c, QWidget *parent):QDialog(parent),controller(&*c),p(nullptr),
    picture(nullptr),name(nullptr),desc(nullptr),price(nullptr)
{

    setObjectName("WindowAddProd");
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QVBoxLayout*vbp=new QVBoxLayout(this);
    QScrollArea*sa=new QScrollArea(this);sa->setObjectName("areaaddprod");
    sa->setWidgetResizable(true);
    psa=new QWidget(sa);
    QVBoxLayout*sal=new QVBoxLayout;
    psa->setLayout(sal);
    sa->setWidget(psa);
    sa->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    sa->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    sa->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    sa->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
    vbp->addWidget(sa);

    quantita=new QLabel("0");//+ -
    QWidget*addrembox=new QWidget(this);addrembox->setLayout(new QHBoxLayout);
    QPushButton*moreofthis=new QPushButton("+");moreofthis->setObjectName("btncart");
    connect(moreofthis,SIGNAL(clicked()),this,SLOT(addquantita()));
    QPushButton*lessofthis=new QPushButton("-");lessofthis->setObjectName("btncart");
    connect(lessofthis,SIGNAL(clicked()),this,SLOT(remquantita()));
    addrembox->layout()->addWidget(moreofthis);
    addrembox->layout()->addWidget(quantita);
    addrembox->layout()->addWidget(lessofthis);
    vbp->addWidget(sa);
    vbp->addWidget(addrembox);
    //aggiungial carello annulla
    QDialogButtonBox*addcancelprod=new QDialogButtonBox;addcancelprod->setObjectName("addannprodbtns");
    QPushButton*addprodbtn=new QPushButton("Aggiungi");addprodbtn->setObjectName("btnaddprodtocart");
    QPushButton*cancelprodbtn=new QPushButton("Annulla");cancelprodbtn->setObjectName("btnannprodtocart");
    addcancelprod->addButton(addprodbtn,QDialogButtonBox::ButtonRole::AcceptRole);
    addcancelprod->addButton(cancelprodbtn,QDialogButtonBox::ButtonRole::RejectRole);
    connect(addprodbtn,SIGNAL(clicked()),this,SLOT(addProdtoCart()));
    connect(cancelprodbtn,SIGNAL(clicked()),this,SLOT(reject()));
    vbp->addWidget(addcancelprod);



    setLayout(vbp);
    QFile file("Resources/style/style.css");
    file.open(QFile::ReadOnly);
    QString filesheet=QLatin1String(file.readAll());
    setStyleSheet(filesheet);
}



void WindowAddProduct::showWindow(Product*p)
{
    if(name == nullptr) {
        picture=new QLabel(psa);picture->setObjectName("imgprodotto");
        name=new QLabel(psa);name->setObjectName("nomeprodotto");
        desc=new QTextBrowser(psa);desc->setObjectName("descprodotto");
        price=new QLabel(psa);
        price->setObjectName("prezzoprodotto");
        QLayout* sal = psa->layout();
        sal->addWidget(name);
        sal->addWidget(picture);
        sal->addWidget(desc);
        sal->addWidget(price);
    }
    this->p=p;
    //img = QPixmap("Resources/images/Burger/big-mc.png");//get immagine
    picture->setPixmap(p->Get_Icon());
    name->setText(p->Get_Nome());
    desc->setText(p->Get_Description());
    quantita->setText(QString::number(p->get_Quantita()));
    price->setText(QString::number(p->Get_Price())+" €");
    open();
}

void WindowAddProduct::remquantita(){
 uint q =quantita->text().toInt();
 q--;
if(q<1)
    q=1;
p->set_Quantita(q);
quantita->setText(QString::number(q));
}

void WindowAddProduct::addquantita(){
    uint q =quantita->text().toInt();
    q++;
   p->set_Quantita(q);
   quantita->setText(QString::number(q));
}

void WindowAddProduct::addProdtoCart(){
       connect(this,SIGNAL(addthisprod(Product*)),controller,SLOT(addthisprodtocart(Product*)));
    emit addthisprod(p);
    QDialog::accept();
       disconnect(this,SIGNAL(addthisprod(Product*)),controller,SLOT(addthisprodtocart(Product*)));
}

