#include "menubutton.h"

MenuButton::MenuButton(QString cat,QString label,QString sicona, QWidget *parent) : QPushButton(parent),icona(sicona){
    /*connect(this,SIGNAL(clicked()),this,SLOT(cellEmitter()));*/
    this->setIcon(QIcon(icona));
    setIconSize(QSize(85,85));
    setText(label);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

void MenuButton::cellEmitter(){
emit clickedCell(icona);
}
