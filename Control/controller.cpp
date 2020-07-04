#include "controller.h"
#include "View/menubutton.h"
#include "View/uicuoco.h"
#include "View/uimanager.h"
#include "View/loginui.h"
#include <QDebug>
ControllerR::ControllerR(Restorant *mod, QObject *parent) : QObject(parent),view(nullptr),model(mod){}

void ControllerR::set_View(ClientWindow *v){
    view=v;v->show();
}
void ControllerR::set_View(UIManager *m){
    view=m;m->show();
}

void ControllerR::set_Cuoco(UICuoco *c){
    viewcuoco=c;viewcuoco->open();
}
void ControllerR::FilterProductsonclick(const vector<QString>& qs){
    for(auto it=qs.begin();it!=qs.end();it++){

        /*if((*it).toLower()==(QString("Sweet").toLower()))
            emit newData(*it);
        if((*it).toLower()==(QString("Vegan").toLower()))
            emit newData(model->filterProuduct("",2));
        if((*it).toLower()==(QString("SalvaEuro").toLower()))
            emit newData(model->filterProuduct("",1));
        if((*it).toLower()==(QString("GlutenFree").toLower()))
            emit newData(model->filterProuduct("",0,true));
        if((*it).toLower()==(QString("Dietetici").toLower()))
            emit newData(model->filterProuduct("",0,true));*/

        else{
        vector<Product*>v=model->filterProuduct(*it);
        emit newData(v);
        }
    }
}

/*void ControllerR::getPointerProduct(const QString &qs){
        vector<Product*>v=model->filterProuduct(qs);
        Product* primo=*(v.begin());
        connect(this,SIGNAL(productdata(Product*)),view,SLOT(addWindowAddProduct(Product*)) );
             emit productdata(primo);
        //view->UpdateRightArea(a)
}*/

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
        //view->UpdateRightArea(a);
    emit newData(v);
    }
}


void ControllerR::Home(){

}

void ControllerR::resetOrdinazione(){

}
void ControllerR::createneworder(Order*o){
    //connetti sengnale ordine aggiunto alla vista di cuoco e di cassiere
       connect(this,SIGNAL(ordineaggiunto(Order*)),viewcuoco,SLOT(aggiornalistaord(Order*)));
       connect(this,SIGNAL(ordineaggiunto(Order*)),view,SLOT(aggiornalistaord(Order*)));
    Order* num=model->addOrder(o);
    emit ordineaggiunto(num);
    disconnect(this,SIGNAL(ordineaggiunto(Order*)),viewcuoco,SLOT(aggiornalistaord(Order*)));
    disconnect(this,SIGNAL(ordineaggiunto(Order*)),view,SLOT(aggiornalistaord(Order*)));
}
void ControllerR::orderready(Order*o){
    connect(this,SIGNAL(ordineprep(Order*)),view,SLOT(orderready(Order*)));
    connect(this,SIGNAL(ordineprep(Order*)),viewcuoco,SLOT(orderready(Order*)));
 emit ordineprep(o);
 disconnect(this,SIGNAL(ordineprep(Order*)),view,SLOT(orderready(Order*)));
 disconnect(this,SIGNAL(ordineprep(Order*)),viewcuoco,SLOT(orderready(Order*)));
}

void ControllerR::orderComplete(Order *o){
    connect(this,SIGNAL(orderCompleted(Order*)),view,SLOT(orderComplete(Order*)));
    emit orderCompleted(o);
    connect(this,SIGNAL(orderCompleted(Order*)),view,SLOT(orderComplete(Order*)));
}

void ControllerR::Checklogin(LoginUI*log,QString u, QString p){
Employee*pe= model->userexist(u,p);
    if(pe){

        if(pe->getRuolo()==cooker)
        set_Cuoco(new UICuoco(this,dynamic_cast<Cooker*>(pe)));
        if(dynamic_cast<Manager*>(pe)){
        if(!view)
        set_View(new UIManager(this,dynamic_cast<Manager*>(pe)));
        widgets.push_back(view);
        if(!viewcuoco)
            set_Cuoco(new UICuoco(this,model->findacooker()));
         }
        if(dynamic_cast<Cashier*>(pe)){
        if(!view)
        set_View(new ClientWindow(this,dynamic_cast<Cashier*>(pe)));
        widgets.push_back(view);
        }
        log->accept();
    }
    else
    log->reject();
}
