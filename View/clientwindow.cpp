#include "clientwindow.h"
#include "View/menubutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextBrowser>
#include <QDialogButtonBox>
#include "Control/controller.h"
#include "View/productbutton.h"
#include <QToolButton>
#include <View/uigestioneordini.h>
#include <View/cashieorderitem.h>
void ClientWindow::addClientWidgets(){
addtopmenuwidgets();
addinitialButtonstoUILayout();
addLeftMenuButtons();

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

ClientWindow::ClientWindow( ControllerR *c, Cashier *cass,QWidget*parent)
    :McBurgerView(c,parent),cassiere(cass), menuproducts(new QScrollArea(this)),productviews(new QScrollArea(this)),
      UI(new QStackedLayout(productviews)),mainlayout(new QVBoxLayout(this)),topmenuwidget(new QWidget(this)),
      pointerproductwindow(new WindowAddProduct(controller,this)),cart(new Cart(cassiere,controller,this)),UIgestord(new UIGestioneOrdini(c,this))
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
    cart->accept();//avvenuto con successo
    cart->totale->setText("TOTALE : 0 euro");
    QString ordine=QString::number(i->Get_NumOrder());
    if(!dynamic_cast<Manager*>(cassiere))
    UIgestord->inprep->layout()->addWidget(new VisibleOrderItem(controller,i));
    else
    UIgestord->inprep->layout()->addWidget(new Orditem(controller,i));
    update();
}
void ClientWindow::orderready(Order*i){
    QString ordine=QString::number(i->Get_NumOrder());
    VisibleOrderItem*order=UIgestord->inprep->findChild<VisibleOrderItem*>(ordine);
    UIgestord->inprep->layout()->removeWidget(order);
    delete order;
    UIgestord->pronti->layout()->addWidget(new CashieOrderItem(controller,i));
    update();
}

void ClientWindow::orderComplete(Order *i){
    cassiere->ordercomplete(i);
    QString ordine=QString::number(i->Get_NumOrder());
    CashieOrderItem*order=UIgestord->pronti->findChild<CashieOrderItem*>(ordine);
    UIgestord->pronti->layout()->removeWidget(order);
    delete order;
    update();
}

void ClientWindow::showGestOrd(){
    UIgestord->showGestOrd();
}


void ClientWindow::addLeftMenuButtons(){
    QVector<MenuButton*> v;
    QWidget*t=new QWidget();
    QVBoxLayout* menu=new QVBoxLayout(t);
    v.push_back(new MenuButton("Burger",5,"Panini","Resources/images/Icons/burgericon.png"));
    v.push_back(new MenuButton("Drink",6,"Bibite","Resources/images/Icons/drinkicon.png"));
    v.push_back(new MenuButton("Patatine",7,"Patatine","Resources/images/Icons/patatineicon.png"));
    v.push_back(new MenuButton("Sweet",8,"Dolci","Resources/images/Icons/sweeticon.png"));
    v.push_back(new MenuButton("Caffe",12,"Caffe","Resources/images/Icons/caffeicon.png"));
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
    QScrollArea*t=new QScrollArea(this);
    QGridLayout*boxbottoni=new QGridLayout(t);t->setLayout(boxbottoni);
    MenuButton*vegan(new MenuButton("",1,"La tua Colazione","Resources/images/Icons/break-icon.png"));connect(vegan,SIGNAL(buildmylayoutbuttons()),controller,SLOT(getveganproducts()));
     MenuButton*salvaeuro=(new MenuButton("",2,"SalvaEuro","Resources/images/Icons/salvaeuro.png"));connect(salvaeuro,SIGNAL(buildmylayoutbuttons()),controller,SLOT(getsalvaeuro()));
     MenuButton*glutenfree=new MenuButton("",3,"Glutenfree","Resources/images/Icons/glf-icon.png");connect(glutenfree,SIGNAL(buildmylayoutbuttons()),controller,SLOT(getglfproducts()));
     MenuButton*dietetici(new MenuButton("",4,"Dietetici","Resources/images/Icons/diet-icon.png"));connect(dietetici,SIGNAL(buildmylayoutbuttons()),controller,SLOT(getdietetici()));
     v.push_back(vegan);v.push_back(salvaeuro);v.push_back(glutenfree);v.push_back(dietetici);
    for(auto p = std::make_pair(0, v.begin());p.second!=v.end();p.second++,p.first++){
        (*(p.second))->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        (*(p.second))->setObjectName("centralembtn");
     boxbottoni->addWidget((*p.second),p.first/2,p.first%2);
     (*p.second)->setObjectName("RightButtonAreaClient");
     //connect(*p.second,SIGNAL(clickedCell(const QString&)),controller,SLOT(FilterProductsonclick(QString)));
     connect(*p.second,SIGNAL(clickedCell(int)),UI,SLOT(setCurrentIndex(int)));
    }
    UI->addWidget(t);
    for(auto p =v.begin();p!=v.end();p++)
        emit (*p)->buildmylayoutbuttons();
    t->setWidgetResizable(true);
        t->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        t->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
}

void ClientWindow::createsubmenus(){
connect(this,SIGNAL(buildbuttons(vector<QString>)),controller,SLOT(FilterProductsonclick(vector<QString>)) );
vector<QString>costrfin;//vettore per costruire i layouts dei vari prodotti senza farlo ogni volta
costrfin.push_back("Burger");costrfin.push_back("Drink");
costrfin.push_back("Patatine");//costrfin.push_back("Sweet");

/*costrfin.push_back("Vegan");costrfin.push_back("SalvaEuro");costrfin.push_back("Glutenfree");costrfin.push_back("Dietetici");*/
emit buildbuttons(costrfin);
buildsubmenusweets();
vector<QString>costrfin1;
costrfin1.push_back("Brioche");costrfin1.push_back("Cake");costrfin1.push_back("Donut");costrfin1.push_back("Caffetteria");
emit buildbuttons(costrfin1);
}

void ClientWindow::addtopmenuwidgets(){
QWidget*tbtn=new MenuButton("",0,"","Resources/images/Icons/home-icon.png");
QPushButton*resetordine=new QPushButton(QPixmap("Resources/images/Icons/order-list-icon.png"),""); resetordine->setObjectName("menubtn");resetordine->setIconSize(QSize(85,85));
QPushButton*seecart=new QPushButton(QIcon(QPixmap("Resources/images/Icons/icon-cart.png")),"");seecart->setObjectName("menubtn");seecart->setIconSize(QSize(85,85));
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
        auto*btn=new ProductButton(cassiere,*it);
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
}

void ClientWindow::buildsubmenusweets(){
    QVector<MenuButton*> a;
    a.push_back(new MenuButton("Brioche",9,"Brioche","Resources/images/Sweet/croissant-vuoto.png"));
    a.push_back(new MenuButton("Cake",10,"Torte","Resources/images/Sweet/torta.png"));
    a.push_back(new MenuButton("Donut",11,"Ciambelle","Resources/images/Sweet/ciambella.png"));
QScrollArea*t=new QScrollArea(this);
QHBoxLayout*tl=new QHBoxLayout(t);
t->setLayout(tl);int indice=0;
 for(auto it=a.begin();it!=a.end();it++,indice++){
        tl->addWidget(*it);connect(*it,SIGNAL(clickedCell(int)),UI,SLOT(setCurrentIndex(int)));
 }
 UI->addWidget(t);
}


