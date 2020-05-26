#include "menubutton.h"

MenuButton::MenuButton(QString sicona, QWidget *parent) : QPushButton(parent),icona(sicona){
    /*connect(this,SIGNAL(clicked()),this,SLOT(cellEmitter()));*/
    this->setIcon(QIcon(icona));
}

void MenuButton::cellEmitter(){
emit clickedCell(icona);
}
