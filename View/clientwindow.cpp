#include "clientwindow.h"
void ClientWindow::addMenu(){
menuproducts=new QScrollArea(this);
menuproducts->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Expanding);
menuproducts->setMinimumSize(400,720);
productviews=new QHBoxLayout(this);
addButtons();
}

void ClientWindow::addButtons(){
        MenuButton* button=new MenuButton(":/images/Icons/burgericon.png");//crea
        button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
                menuproducts->setWidget(button);
         //connect(button,SIGNAL(clickedCell(Qstring)),controller,SLOT(FilterProductsonclick(QString)) );
}

void ClientWindow::setRestorantStyle(){
    QFile file("./style/style.css");
    file.open(QFile::ReadOnly);
    QString filesheet=QLatin1String(file.readAll());
    setStyleSheet(filesheet);
}

ClientWindow::ClientWindow(ControllerR *c, QWidget*parent):QWidget(parent),controller(c){
    addMenu();
    this->setMinimumWidth(1080);
    this->setMinimumHeight(720);
    setRestorantStyle();

}

