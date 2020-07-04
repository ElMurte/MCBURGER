#include "controller.h"
#include "View/menubutton.h"
#include "View/uicuoco.h"
#include "View/uimanager.h"
#include "View/loginui.h"
#include "View/uiwatchorders.h"
#include <QErrorMessage>
#include <QMessageBox>
#include <QDebug>
ControllerR::ControllerR(Restorant *mod, QObject *parent) : QObject(parent),view(nullptr),model(mod){}

void ControllerR::set_View(ClientWindow *v){
    view=v;v->show();
}
void ControllerR::set_View(UIManager *m){
    view=m;m->show();
}

void ControllerR::set_Cuoco(UICuoco *c){
    viewcuoco=c;viewcuoco->show();
}
void ControllerR::FilterProductsonclick(const vector<QString>& qs){
    for(auto it=qs.begin();it!=qs.end();it++){
        vector<Product*>v=model->filterProuduct(*it);
        emit newData(v);
    }
}

void ControllerR::addthisprodtocart(Product *p){
    connect(this,SIGNAL(addProdtocart(Product*)),view,SLOT(AddProducttoCart(Product*)) );
    emit addProdtocart(p);
     disconnect(this,SIGNAL(addProdtocart(Product*)),view,SLOT(AddProducttoCart(Product*)) );
}

void ControllerR::FilterProductsonclick(const QString& qs){
    if(qs.toLower()==(QString("Sweet").toLower()))
        emit newData(qs);
    else{
    vector<Product*>v=model->filterProuduct(qs);
    QString test;
    emit newData(v);
    }
}
void ControllerR::createneworder(Order*o){
    //connetti sengnale ordine aggiunto alla vista di cuoco e di cassiere
       connect(this,SIGNAL(ordineaggiunto(Order*)),viewcuoco,SLOT(aggiornalistaord(Order*)));
       connect(this,SIGNAL(ordineaggiunto(Order*)),view,SLOT(aggiornalistaord(Order*)));
       connect(this,SIGNAL(ordineaggiunto(Order*)),viewclients,SLOT(addorder(Order*)));
    Order* num=model->addOrder(o);
    emit ordineaggiunto(num);
    disconnect(this,SIGNAL(ordineaggiunto(Order*)),viewcuoco,SLOT(aggiornalistaord(Order*)));
    disconnect(this,SIGNAL(ordineaggiunto(Order*)),view,SLOT(aggiornalistaord(Order*)));
    disconnect(this,SIGNAL(ordineaggiunto(Order*)),viewclients,SLOT(addorder(Order*)));
}
void ControllerR::orderready(Order*o){
    connect(this,SIGNAL(ordineprep(Order*)),view,SLOT(orderready(Order*)));
    connect(this,SIGNAL(ordineprep(Order*)),viewcuoco,SLOT(orderready(Order*)));
    connect(this,SIGNAL(ordineprep(Order*)),viewclients,SLOT(orderready(Order*)));
 emit ordineprep(o);
 disconnect(this,SIGNAL(ordineprep(Order*)),view,SLOT(orderready(Order*)));
 disconnect(this,SIGNAL(ordineprep(Order*)),viewcuoco,SLOT(orderready(Order*)));
 disconnect(this,SIGNAL(ordineprep(Order*)),viewclients,SLOT(orderready(Order*)));
}

void ControllerR::orderComplete(Order *o){
    connect(this,SIGNAL(orderCompleted(Order*)),view,SLOT(orderComplete(Order*)));
    connect(this,SIGNAL(orderCompleted(Order*)),viewclients,SLOT(orderComplete(Order*)));
    emit orderCompleted(o);
    connect(this,SIGNAL(orderCompleted(Order*)),view,SLOT(orderComplete(Order*)));
    connect(this,SIGNAL(orderCompleted(Order*)),viewclients,SLOT(orderComplete(Order*)));
}

void ControllerR::Checklogin(LoginUI*log,QString u, QString p){
Employee*pe= model->userexist(u,p);
    if(pe){

        if(dynamic_cast<Cooker*>(pe))
        set_Cuoco(new UICuoco(this,dynamic_cast<Cooker*>(pe)));
        if(dynamic_cast<Manager*>(pe)){
        if(!view)
        set_View(new UIManager(this,dynamic_cast<Manager*>(pe)));
         }
        if(dynamic_cast<Cashier*>(pe)){
        if(!view)
        set_View(new ClientWindow(this,dynamic_cast<Cashier*>(pe)));
        }
        log->accept();
        viewclients=new UIwatchOrders(this);
        viewclients->showGestOrd();
    }
    else{
        QMessageBox a(log);
        a.setText("Password e/o Username sbagliate");a.exec();
    }
}

void ControllerR::getveganproducts(){
    vector<Product*>v=model->getViewOfProducts(0,0,true);
    emit newData(v);
}

void ControllerR::getsalvaeuro(){
    vector<Product*>v=model->getViewOfProducts(0,1);
    emit newData(v);
}

void ControllerR::getglfproducts(){
    vector<Product*>v=model->getViewOfProducts(0,0,false,true);
    emit newData(v);
}

void ControllerR::getdietetici(){
    vector<Product*>v=model->getViewOfProducts(100);
    emit newData(v);
}

void ControllerR::CucinaAccesa(Cooker *c)
{
    if(!viewcuoco)
   viewcuoco=new UICuoco(this,c);

    viewcuoco->show();
    viewcuoco->activateWindow();
}
