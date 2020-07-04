#include "menubutton.h"
#include "QLabel"
#include "QVBoxLayout"
#include "QStylePainter"
#include "QStyleOptionButton"
MenuButton::MenuButton(const QString& cat,int pag,const QString& label,const QString& sicona, QWidget *parent) : QPushButton(parent),categorie(cat){
    /*connect(this,SIGNAL(clicked()),this,SLOT(cellEmitter()));*/
    this->setIcon(QIcon(sicona));
    setIconSize(QSize(100,100));
    setText(label);
    page=pag;
    setAutoDefault(false);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(this,SIGNAL(clicked()),this,SLOT(handleclick()));
}
void MenuButton::fakehandleclick(){//costruzione del bottone iniziale
emit clickedCell(categorie);
}
void MenuButton::handleclick(){//puntatore layout UI
emit clickedCell(page);
}
