#include "menubutton.h"

MenuButton::MenuButton(const QString& cat,const QString& label,const QString& sicona, QWidget *parent) : QPushButton(parent),categorie(cat){
    /*connect(this,SIGNAL(clicked()),this,SLOT(cellEmitter()));*/
    this->setIcon(QIcon(sicona));
    setIconSize(QSize(85,85));
    setText(label);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(this,SIGNAL(clicked()),this,SLOT(handleclick()));
}

void MenuButton::handleclick(){
emit clickedCell(categorie);
}
