#include "productbutton.h"
#include "Model/product.h"
#include "View/windowaddproduct.h"
#include "Model/manager.h"
ProductButton::ProductButton(Cashier*cass,Product*p, QWidget *parent) : QToolButton(parent),cassiere(cass),prodp(p){
    this->setIcon(QIcon(p->Get_Icon()));
    setIconSize(QSize(190,120));
    setText(p->Get_Nome());
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(this,SIGNAL(clicked()),this,SLOT(fakehandleclick()));
    if(!prodp->getDisponibile())
    setStyleSheet("color:transparent;background:transparent;");

if(dynamic_cast<Manager*>(cassiere))
    connect(this,SIGNAL(rightClicked()),this,SLOT(onrightClick()));
}
void ProductButton::fakehandleclick(){
    if(prodp->getDisponibile())
    emit clickedCell(prodp);
}

void ProductButton::mouseReleaseEvent(QMouseEvent *e){

     if (e->button() == Qt::RightButton) emit rightClicked();
     if (e->button() == Qt::LeftButton) emit clicked();
}

void ProductButton::onrightClick(){
    if(prodp->getDisponibile()){
    prodp->setDisponibile(false);
    setStyleSheet("color:transparent;background:transparent;");
    }
    else{
        prodp->setDisponibile(true);
        setStyleSheet("color:black;background:whitesmoke;");
    }
}
