#include "productbutton.h"

ProductButton::ProductButton(const QString& cat,int pag,const QString& label,const QString& sicona, QWidget *parent) : QToolButton(parent),categorie(cat){
    /*connect(this,SIGNAL(clicked()),this,SLOT(cellEmitter()));*/
    this->setIcon(QIcon(sicona));
    setIconSize(QSize(140,100));
    setText(label);
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    page=pag;
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(this,SIGNAL(clicked()),this,SLOT(handleclick()));
    //connect(this,SIGNAL(),this,fakehandleclick());
}
void ProductButton::fakehandleclick(){
emit clickedCell(categorie);
}
void ProductButton::handleclick(){
emit clickedCell(page);
}
