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
}
void ProductButton::fakehandleclick(){
emit clickedCell(prodp);
}
