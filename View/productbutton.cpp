#include "productbutton.h"
#include <QtDebug>
#include "Model/product.h"
#include "View/windowaddproduct.h"
ProductButton::ProductButton(Product*p, QWidget *parent) : QToolButton(parent),prodp(p){
    this->setIcon(QIcon(p->Get_Icon()));
    setIconSize(QSize(190,120));
    setText(p->Get_Nome());
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(this,SIGNAL(clicked()),this,SLOT(fakehandleclick()));
    if( ! ( p->getDisponibile() ) ){
       disconnect(this,SIGNAL(clicked()),this,SLOT(fakehandleclick()));
        setStyleSheet("color:transparent;background:transparent;");
    }
}
void ProductButton::fakehandleclick(){
    emit clickedCell(prodp);
}

void ProductButton::mouseReleaseEvent(QMouseEvent *e){
        if (e->button() == Qt::RightButton) emit rightClicked();
        else if (e->button() == Qt::LeftButton) emit clicked();
}

void ProductButton::onrightClick(){
    if(prodp->getDisponibile()){
    prodp->setDisponibile(false);
    disconnect(this,SIGNAL(clicked()),this,SLOT(fakehandleclick()));
    setStyleSheet("color:transparent;background:transparent;");
    }
    else{
        prodp->setDisponibile(true);
        connect(this,SIGNAL(clicked()),this,SLOT(fakehandleclick()));
        setStyleSheet("color:black;background:whitesmoke;");
    }
}
