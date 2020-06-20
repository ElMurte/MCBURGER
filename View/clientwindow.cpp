#include "clientwindow.h"
#include "View/menubutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextBrowser>
#include <QDialogButtonBox>
#include "Control/controller.h"
#include "View/productbutton.h"
#include <QtDebug>
void ClientWindow::addClientWidgets(){
addMenuButtons();
addViewButtons();
menuproducts->setObjectName("LeftAreaClient");
}
void ClientWindow::addWindowAddProduct(const QString& nome,const QString& imma,const QString& descriz,const double& prezzo){

    pointerproductwindow->showWindow(nome,imma,descriz,prezzo);
}
void ClientWindow::ShowCart(){
    cart->ShowCartWindow();
    //cart->
}
ClientWindow::ClientWindow(ControllerR *c, QWidget*parent):McBurgerView(c,parent),mainlayout(new QVBoxLayout(this)),pointerproductwindow(new WindowAddProduct(this)),cart(new Cart(this)){
    //connect(this,SIGNAL(destroyed()),this,SLOT(closeaddprodwin()));
    connect(this,SIGNAL(buildbuttons(vector<QString>)),controller,SLOT(FilterProductsonclick(vector<QString>)) );
    vector<QString>costrfin;//vettore per costruire i layouts dei vari prodotti senza farlo ogni volta
    costrfin.push_back("Burger");costrfin.push_back("Drink");
    costrfin.push_back("Patatine");costrfin.push_back("Sweet");
    costrfin.push_back("Brioche");costrfin.push_back("Cake");costrfin.push_back("Donut");

    menuproducts=new QScrollArea(this);productviews=new QScrollArea(this);

    UI=new QStackedLayout(productviews);
    addClientWidgets();//UI->addWidget();

    /*menu in alto*/
    QWidget* actionbuttons=new QWidget;
    QWidget*tbtn=new MenuButton("",0,"","Resources/images/Icons/home-icon.png");
    QWidget*resetordine=new MenuButton("",0,"","Resources/images/Icons/reset-icon.png");
    QWidget*seecart=new MenuButton("",0,"","Resources/images/Icons/icon-cart.png");
    connect(tbtn,SIGNAL(clickedCell(int)),UI,SLOT(setCurrentIndex(int)));
    connect(seecart,SIGNAL(clicked()),this,SLOT(ShowCart()));
    actionbuttons->setLayout(new QHBoxLayout());

    actionbuttons->layout()->addWidget(tbtn);
    actionbuttons->layout()->addWidget(resetordine);
    actionbuttons->layout()->addWidget(seecart);
    actionbuttons->layout()->setAlignment(Qt::AlignLeft);

    /*style menu*/
    tbtn->setObjectName("btnlay");
    seecart->setObjectName("btnlay");
    resetordine->setObjectName("btnlay");
    actionbuttons->setMaximumHeight(130);
    /**/
    QHBoxLayout*secondarigamainwidget=new QHBoxLayout(this);
    secondarigamainwidget->addWidget(menuproducts);secondarigamainwidget->addWidget(productviews);
    /*Mainlayout of clientwindow=menualto+menu+productsview*/
        mainlayout->addWidget(actionbuttons);
        mainlayout->addItem(secondarigamainwidget);
    emit buildbuttons(costrfin);
    setLayout(mainlayout);

    //style
    /*setMinimumWidth(1080);
    setMinimumHeight(720);*/
    menuproducts->setWidgetResizable(true);productviews->setWidgetResizable(true);
    productviews->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    productviews->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
    menuproducts->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    menuproducts->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
    setRestorantStyle();
    show();
    //
}

/*void ClientWindow::setnullptrtoaddprodwin(){
pointerproductwindow=nullptr;
}*/

void ClientWindow::addMenuButtons(){
    QVector<MenuButton*> v;
    QWidget*t=new QWidget();
    QVBoxLayout* menu=new QVBoxLayout(t);
    v.push_back(new MenuButton("Burger",1,"Panini","Resources/images/Icons/burgericon.png"));
    v.push_back(new MenuButton("Drink",2,"Bibite","Resources/images/Icons/drinkicon.png"));
    v.push_back(new MenuButton("Patatine",3,"Patatine","Resources/images/Icons/patatineicon.png"));
    v.push_back(new MenuButton("Sweet",4,"Dolci","Resources/images/Icons/sweeticon.png"));
     v.push_back(new MenuButton("Caffe",5,"Caffe","Resources/images/Icons/caffeicon.png"));
    for(auto it=v.begin();it!=v.end();it++){
     connect(*it,SIGNAL(clickedCell(int)),UI,SLOT(setCurrentIndex(int)));
     menu->addWidget((*it));
        (*it)->setObjectName("menubtn");
    //connect(*it,SIGNAL(clickedCell(const QString&)),controller,SLOT(FilterProductsonclick(QString)));
    }
    t->setObjectName("leftWidgetArea");
    menuproducts->setWidget(t);
   //menuproducts->setLayout(menu);
}
void ClientWindow::addViewButtons(){
    QVector<MenuButton*> v;
    //QGridLayout* menu=new QGridLayout(productviews);
    //QScrollArea*t=new QScrollArea();
    QWidget*final=new QWidget;
    QHBoxLayout*boxbottoni=new QHBoxLayout(final);//t->setLayout(boxbottoni);
    v.push_back(new MenuButton("1",99,"SalvaEuro","Resources/images/Icons/salvaeuro.png"));
     v.push_back(new MenuButton("Vegan",20,"Vegan","Resources/images/Icons/vegan.png"));
     v.push_back(new MenuButton("1",30,"SalvaEuro","Resources/images/Icons/salvaeuro.png"));
      v.push_back(new MenuButton("Vegan",40,"Vegan","Resources/images/Icons/vegan.png"));
    for(auto p = std::make_pair(0, v.begin());p.second!=v.end();p.second++,p.first++){
        /*if(p.first%4==0){
            t=new QHBoxLayout();
            boxbottoni->addLayout(t);
        }*/
        //(*p.second)->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
     boxbottoni->addWidget((*p.second));
     (*p.second)->setObjectName("RightButtonAreaClient");
     //connect(*p.second,SIGNAL(clickedCell(const QString&)),controller,SLOT(FilterProductsonclick(QString)));
     connect(*p.second,SIGNAL(clickedCell(int)),UI,SLOT(setCurrentIndex(int)));
    }
    //productviews->setWidget(final);
    UI->addWidget(final);

}
void ClientWindow::setRestorantStyle(){
    QFile file("Resources/style/style.css");
    file.open(QFile::ReadOnly);
    QString filesheet=QLatin1String(file.readAll());
    setStyleSheet(filesheet);
}
/*void ClientWindow::UpdateRightArea(QVector<MenuButton *> v){
    QLayout*l=productviews->layout();
    QLayoutItem *child;
    while ((child = l->takeAt(0)) != nullptr) {
        delete child->widget(); // delete the widget
        delete child;   // delete the layout item

    }
    delete l;
    QHBoxLayout*boxbottoni=new QHBoxLayout(productviews);
    //QHBoxLayout*t;
    for(auto p = std::make_pair(0, v.begin());p.second!=v.end();p.second++,p.first++){
     if(p.first%4==0){
         t=new QHBoxLayout();
         boxbottoni->addLayout(t);
     }
     boxbottoni->addWidget((*p.second));
     (*p.second)->setIconSize(QSize(150,150));
     (*p.second)->setAccessibleName("RightButtonAreaClient");
     //connect(*p.second,SIGNAL(clickedCell(const QString&)),controller,SLOT(FilterProductsonclick(QString)));
    connect(*p.second,SIGNAL(clickedCell(int)),UI,SLOT(UI->setCurrentIndex(int)));
    }
    productviews->setLayout(boxbottoni);
    productviews->show();
}*/

void ClientWindow::updateFromData(const vector<Product *> &products){
    QVector<MenuButton*> a;int indice=0;
    //QHBoxLayout*tl=new QHBoxLayout;tl->addWidget(menuproducts);
    QScrollArea* sa=new QScrollArea();sa->setObjectName("RightAreaProd");
    QWidget*t=new QWidget();
    QVBoxLayout*boxbottoni=new QVBoxLayout();
    QHBoxLayout*tmp=nullptr;
    for(auto it=products.begin();it!=products.end();it++,indice++){
        if(indice%5==0){
            tmp=new QHBoxLayout();
            boxbottoni->addLayout(tmp);
        }
        auto*btn=new ProductButton((*it)->Get_Nome(),(*it)->Get_Nome(),(*it)->Get_Icon());
           tmp->addWidget(btn);btn->setObjectName("productbutton");
           connect(btn,SIGNAL(clickedCell(QString)),controller,SLOT(getPointerProduct(QString)));
    }
    t->setLayout(boxbottoni);
    t->layout()->setAlignment(Qt::AlignTop);t->layout()->setSpacing(40);
    sa->setWidget(t);
    UI->addWidget(sa);
    sa->setWidgetResizable(true);
        sa->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        sa->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
    //TODO: UPDATE VIEW WITH DATA IN products

}
void ClientWindow::updateFromData(const QString& qs){
    QVector<MenuButton*> a;
    if(qs=="Sweet"){
           a.push_back(new MenuButton("Brioche",5,"Brioche","Resources/images/Sweet/croissant-vuoto.png"));
           a.push_back(new MenuButton("Cake",6,"Torte","Resources/images/Sweet/torta.png"));
           a.push_back(new MenuButton("Donut",7,"Ciambelle","Resources/images/Sweet/ciambella.png"));
    QScrollArea*t=new QScrollArea(this);
    QHBoxLayout*tl=new QHBoxLayout(t);
    t->setLayout(tl);int indice=0;
        for(auto it=a.begin();it!=a.end();it++,indice++){
               tl->addWidget(*it);connect(*it,SIGNAL(clickedCell(int)),UI,SLOT(setCurrentIndex(int)));
        }
    UI->addWidget(t);
    }
    //UpdateRightArea(a);
    /*auto*s=new ControllerR(*controller);
    new ClientWindow(s);*/
    //TODO: UPDATE VIEW WITH DATA IN products
}
