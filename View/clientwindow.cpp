#include "clientwindow.h"
void ClientWindow::addMenu(){
menuproducts=new QScrollArea(this);
menuproducts->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
menuproducts->show();
menuproducts->setMinimumSize(300,720);
menuproducts->setMaximumSize(QSize(1920,1080));
productviews=new QHBoxLayout(this);
addButtons();
}

void ClientWindow::addButtons(){
    QVector<MenuButton*> v;QVBoxLayout* menu=new QVBoxLayout(this);
    v.push_back(new MenuButton("Panino","Panini","Resources/images/Icons/burgericon.png"));
    v.push_back(new MenuButton("Drink","Bibite","Resources/images/Icons/drinkicon.png"));
    v.push_back(new MenuButton("Patatine","Patatine","Resources/images/Icons/patatineicon.png"));
    v.push_back(new MenuButton("Sweet","Dolci","Resources/images/Icons/sweeticon.png"));
     v.push_back(new MenuButton("Caffe","Caffe","Resources/images/Icons/caffeicon.png"));
    for(auto it=v.begin();it!=v.end();it++){
     menu->addWidget((*it));
     //connect(button,SIGNAL(clickedCell(Qstring)),controller,SLOT(FilterProductsonclick(QString)) );
    }
   menuproducts->setLayout(menu);
       //crea
       // MenuButton* buttoncaffe=new MenuButton("Resources/images/Icons/sweeticon.png");//crea
         //connect(button,SIGNAL(clickedCell(Qstring)),controller,SLOT(FilterProductsonclick(QString)) );
}

void ClientWindow::setRestorantStyle(){
    QFile file("Resources/style/style.css");
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

