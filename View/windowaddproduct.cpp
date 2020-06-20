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

WindowAddProduct::WindowAddProduct(QWidget *parent):QDialog(parent),p(nullptr),
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
    QDialogButtonBox*addcancelprod=new QDialogButtonBox;addcancelprod->setObjectName("addannprodbtns");
    QAbstractButton*addprodbtn=new QPushButton("Aggiungi");addprodbtn->setObjectName("btnaddprodtocart");
    QPushButton*cancelprodbtn=new QPushButton("Annulla");cancelprodbtn->setObjectName("btnannprodtocart");
    addcancelprod->addButton(addprodbtn,QDialogButtonBox::ButtonRole::AcceptRole);
    addcancelprod->addButton(cancelprodbtn,QDialogButtonBox::ButtonRole::RejectRole);
    vbp->addWidget(addcancelprod);
    setLayout(vbp);
    QFile file("Resources/style/style.css");
    file.open(QFile::ReadOnly);
    QString filesheet=QLatin1String(file.readAll());
    setStyleSheet(filesheet);
}

bool WindowAddProduct::isthesame(Product* ptr)const{
    return(p->Get_Nome()==ptr->Get_Nome() && p->Get_Icon()==ptr->Get_Icon() && p->Get_Description()==ptr->Get_Description() && p->Get_Price()==ptr->Get_Price());
}


void WindowAddProduct::showWindow(const QString& nome,const QString& imma,const QString& descriz,const double& prezzo)
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
    //img = QPixmap("Resources/images/Burger/big-mc.png");//get immagine
    picture->setPixmap(imma);
    name->setText(nome);
    desc->setText(descriz);
    price->setText(QString::number(prezzo)+" €");
    open();
}
