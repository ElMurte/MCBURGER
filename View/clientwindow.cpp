#include "clientwindow.h"
void ClientWindow::addClientWidgets(){
/*QSizePolicy QSP(QSizePolicy::Preferred,QSizePolicy::Preferred);
menuproducts->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
productviews->setSizePolicy(QSP);
menuproducts->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
menuproducts->setWidgetResizable(true);*/
productviews->setObjectName("RightAreaClient");
menuproducts->setObjectName("LeftAreaClient");
addMenuButtons();
addViewButtons();
UI->addWidget(menuproducts);
UI->addWidget(productviews);
}

void ClientWindow::addMenuButtons(){
    QVector<MenuButton*> v;
    QVBoxLayout* menu=new QVBoxLayout(this);
    v.push_back(new MenuButton("Burger","Panini","Resources/images/Icons/burgericon.png"));
    v.push_back(new MenuButton("Drink","Bibite","Resources/images/Icons/drinkicon.png"));
    v.push_back(new MenuButton("Patatine","Patatine","Resources/images/Icons/patatineicon.png"));
    v.push_back(new MenuButton("Sweet","Dolci","Resources/images/Icons/sweeticon.png"));
     v.push_back(new MenuButton("Caffe","Caffe","Resources/images/Icons/caffeicon.png"));
    for(auto it=v.begin();it!=v.end();it++){
     menu->addWidget((*it));
    connect(*it,SIGNAL(clickedCell(const QString&)),controller,SLOT(FilterProductsonclick(QString)));
    }
   menuproducts->setLayout(menu);
   //menuproducts->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
}
void ClientWindow::addViewButtons(){
    QVector<MenuButton*> v;
    QGridLayout* menu=new QGridLayout(this);
    v.push_back(new MenuButton("1","SalvaEuro","Resources/images/Icons/salvaeuro.png"));
     v.push_back(new MenuButton("Vegan","Vegan","Resources/images/Icons/vegan.png"));
     v.push_back(new MenuButton("1","SalvaEuro","Resources/images/Icons/salvaeuro.png"));
      v.push_back(new MenuButton("Vegan","Vegan","Resources/images/Icons/vegan.png"));
    for(auto p = std::make_pair(0, v.begin());p.second!=v.end();p.second++,p.first++){
     menu->addWidget((*p.second),p.first%2,p.first/2);
     (*p.second)->setAccessibleName("RightButtonAreaClient");
     connect(*p.second,SIGNAL(clickedCell(const QString&)),controller,SLOT(FilterProductsonclick(QString)));
    //connect(*p.second,SIGNAL(clickedCell(QString)),controller,SLOT(controller->FilterProductsonclick(QString)));
    }
   productviews->setLayout(menu);
   //menuproducts->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
}
void ClientWindow::setRestorantStyle(){
    QFile file("Resources/style/style.css");
    file.open(QFile::ReadOnly);
    QString filesheet=QLatin1String(file.readAll());
    setStyleSheet(filesheet);
}

ClientWindow::ClientWindow(ControllerR *c, QWidget*parent):QWidget(parent),controller(c),menuproducts(new QScrollArea(this)),productviews(new QScrollArea(this)),UI(new QHBoxLayout(this)){
    addClientWidgets();
    setMinimumWidth(1080);
    setMinimumHeight(720);
    setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    setRestorantStyle();
}

void ClientWindow::UpdateRightArea(QVector<MenuButton *> v){
    QGridLayout*menu=new QGridLayout(this);
    for(auto p = std::make_pair(0, v.begin());p.second!=v.end();p.second++,p.first++){
     menu->addWidget((*p.second),p.first%2,p.first/2);
     (*p.second)->setAccessibleName("RightButtonAreaClient");
     connect(*p.second,SIGNAL(clickedCell(const QString&)),controller,SLOT(FilterProductsonclick(QString)));
    //connect(*p.second,SIGNAL(clickedCell(QString)),controller,SLOT(controller->FilterProductsonclick(QString)));
    }
    delete productviews->layout();
    delete productviews;
    productviews=new QScrollArea(this);
    productviews->setLayout(menu);
    UI->addWidget(productviews);
}

