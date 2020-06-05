#include "menubutton.h"

MenuButton::MenuButton(const QString& cat,int pag,const QString& label,const QString& sicona, QWidget *parent) : QPushButton(parent),categorie(cat){
    /*connect(this,SIGNAL(clicked()),this,SLOT(cellEmitter()));*/
    this->setIcon(QIcon(sicona));
    setIconSize(QSize(85,85));
    setText(label);
    page=pag;
    setAutoDefault(false);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(this,SIGNAL(clicked()),this,SLOT(handleclick()));
    //connect(this,SIGNAL(),this,fakehandleclick());
}
void MenuButton::fakehandleclick(){
emit clickedCell(categorie);
}
void MenuButton::handleclick(){
emit clickedCell(page);
}
