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
#include <View/uigestioneordini.h>
//UpdateRightArea(a);
/*auto*s=new ControllerR(*controller);
new ClientWindow(s);*/
//TODO: UPDATE VIEW WITH DATA IN products
void ClientWindow::addClientWidgets(){
addtopmenuwidgets();
addLeftMenuButtons();
addinitialButtonstoUILayout();
createsubmenus();
menuproducts->setObjectName("LeftAreaClient");
}

void ClientWindow::addWindowAddProduct(Product*p){
    pointerproductwindow->showWindow(p);
}

void ClientWindow::ShowCart(){
    cart->ShowCartWindow();
}

void ClientWindow::AddProducttoCart(Product *p){
    connect(this,SIGNAL(insertrow(Product*)),cart,SLOT(InsertRowProd(Product*)));
    emit insertrow(p);
    disconnect(this,SIGNAL(insertrow(Product*)),cart,SLOT(InsertRowProd(Product*)));
//messaggio di aggiunta avvenuta con successo
}

ClientWindow::ClientWindow(ControllerR *c, QWidget*parent)
    :McBurgerView(c,parent),menuproducts(new QScrollArea(this)),productviews(new QScrollArea(this)),
      UI(new QStackedLayout(productviews)),mainlayout(new QVBoxLayout(this)),topmenuwidget(new QWidget(this)),
      pointerproductwindow(new WindowAddProduct(controller,this)),cart(new Cart(controller,this)),UIgestord(new UIGestioneOrdini(c,this))
{
    addClientWidgets();
    QHBoxLayout*secondarigamainwidget=new QHBoxLayout(this);
    secondarigamainwidget->addWidget(menuproducts);secondarigamainwidget->addWidget(productviews);
        mainlayout->addWidget(topmenuwidget);
        mainlayout->addItem(secondarigamainwidget);
    setLayout(mainlayout);
    setRestorantStyle();
}

void ClientWindow::aggiornalistaord(Order *i){
    while(cart->tabprod->rowCount())//togli tutte le righe dalla tabella
    cart->tabprod->removeRow(0);
    cart->accept();//messaggio avvenuto con successo
    cart->totale->setText("TOTALE : 0 euro");
    QString ordine=QString::number(i->Get_NumOrder());
    UIgestord->addorder(i);
    update();
}
void ClientWindow::orderready(Order*i){
    QString ordine=QString::number(i->Get_NumOrder());
    Orditem*order=UIgestord->inprep->findChild<Orditem*>(ordine);
    UIgestord->inprep->layout()->removeWidget(order);
    UIgestord->pronti->layout()->addWidget(new Orditem(controller,i));
    update();
}

void ClientWindow::showGestOrd(){
    UIgestord->showGestOrd();
}


void ClientWindow::addLeftMenuButtons(){
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
}
void ClientWindow::addinitialButtonstoUILayout(){
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
     boxbottoni->addWidget((*p.second));
     (*p.second)->setObjectName("RightButtonAreaClient");
     //connect(*p.second,SIGNAL(clickedCell(const QString&)),controller,SLOT(FilterProductsonclick(QString)));
     connect(*p.second,SIGNAL(clickedCell(int)),UI,SLOT(setCurrentIndex(int)));
    }
    //productviews->setWidget(final);
    UI->addWidget(final);

}

void ClientWindow::createsubmenus(){
connect(this,SIGNAL(buildbuttons(vector<QString>)),controller,SLOT(FilterProductsonclick(vector<QString>)) );
vector<QString>costrfin;//vettore per costruire i layouts dei vari prodotti senza farlo ogni volta
costrfin.push_back("Burger");costrfin.push_back("Drink");
costrfin.push_back("Patatine");costrfin.push_back("Sweet");
costrfin.push_back("Brioche");costrfin.push_back("Cake");costrfin.push_back("Donut");
emit buildbuttons(costrfin);
}

void ClientWindow::addtopmenuwidgets(){
QWidget*tbtn=new MenuButton("",0,"","Resources/images/Icons/home-icon.png");
QWidget*resetordine=new MenuButton("",0,"","Resources/images/Icons/reset-icon.png");
QWidget*seecart=new MenuButton("",0,"","Resources/images/Icons/icon-cart.png");
connect(tbtn,SIGNAL(clickedCell(int)),UI,SLOT(setCurrentIndex(int)));
connect(seecart,SIGNAL(clicked()),this,SLOT(ShowCart()));
connect(resetordine,SIGNAL(clicked()),this,SLOT(showGestOrd()));
topmenuwidget->setLayout(new QHBoxLayout());

topmenuwidget->layout()->addWidget(tbtn);
topmenuwidget->layout()->addWidget(resetordine);
topmenuwidget->layout()->addWidget(seecart);
topmenuwidget->layout()->setAlignment(Qt::AlignLeft);
tbtn->setObjectName("btnlay");
seecart->setObjectName("btnlay");
resetordine->setObjectName("btnlay");
topmenuwidget->setMaximumHeight(130);
}
void ClientWindow::setRestorantStyle(){
    //style
    /*setMinimumWidth(1080);
    setMinimumHeight(720);*/
    menuproducts->setWidgetResizable(true);productviews->setWidgetResizable(true);
    productviews->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    productviews->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
    menuproducts->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    menuproducts->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
    QFile file("Resources/style/style.css");
    file.open(QFile::ReadOnly);
    QString filesheet=QLatin1String(file.readAll());
    setStyleSheet(filesheet);
}


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
        auto*btn=new ProductButton(*it);
           tmp->addWidget(btn);btn->setObjectName("productbutton");
            connect(btn,SIGNAL(clickedCell(Product*)),this,SLOT(addWindowAddProduct(Product*)) );
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
    /*menu?*/
    UI->addWidget(t);
    }
}
