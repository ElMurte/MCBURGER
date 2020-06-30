#include "controller.h"
#include "View/menubutton.h"
ControllerR::ControllerR(Restorant *mod, QObject *parent) : QObject(parent),view(nullptr),model(mod){}

void ControllerR::set_View(ClientWindow *v){
    view=v;v->show();
}

void ControllerR::set_Cuoco(UICuoco *c){
    viewcuoco=c;viewcuoco->show();
}
void ControllerR::set_Manager(UIManager *vm){
    viewmanager=vm;viewmanager->show();
}
void ControllerR::FilterProductsonclick(const vector<QString>& qs){
    for(auto it=qs.begin();it!=qs.end();it++){

        if((*it).toLower()==(QString("Sweet").toLower()))
            emit newData(*it);
        else{
        vector<Product*>v=model->filterProuduct(*it);
        QString test;
            //view->UpdateRightArea(a);
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
    connect(this,SIGNAL(addProdtocart(Product*)),viewmanager,SLOT(AddProducttoCart(Product*)) );
    emit addProdtocart(p);
     disconnect(this,SIGNAL(addProdtocart(Product*)),view,SLOT(AddProducttoCart(Product*)) );
     disconnect(this,SIGNAL(addProdtocart(Product*)),viewmanager,SLOT(AddProducttoCart(Product*)) );
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
void ControllerR::createneworder(vector<Product*>& v){
    //connetti sengnale ordine aggiunto alla vista di cuoco e di cassiere
       connect(this,SIGNAL(ordineaggiunto(Order*)),viewcuoco,SLOT(aggiornalistaord(Order*)));
       connect(this,SIGNAL(ordineaggiunto(Order*)),viewmanager->getcucina(),SLOT(aggiornalistaord(Order*)));
    Order* num=model->addOrder(v);
    emit ordineaggiunto(num);
    disconnect(this,SIGNAL(ordineaggiunto(Order*)),viewcuoco,SLOT(aggiornalistaord(Order*)));
    disconnect(this,SIGNAL(ordineaggiunto(Order*)),viewmanager->getcucina(),SLOT(aggiornalistaord(Order*)));
}
void ControllerR::orderready(Order*o){
    connect(this,SIGNAL(ordineprep(Order*)),view,SLOT(orderready(Order*)));
    connect(this,SIGNAL(ordineprep(Order*)),viewcuoco,SLOT(orderready(Order*)));
    connect(this,SIGNAL(ordineprep(Order*)),viewmanager,SLOT(orderready(Order*)));
    connect(this,SIGNAL(ordineprep(Order*)),viewmanager->getcucina(),SLOT(orderready(Order*)));
 emit ordineprep(o);
 disconnect(this,SIGNAL(ordineprep(Order*)),view,SLOT(orderready(Order*)));
 disconnect(this,SIGNAL(ordineprep(Order*)),viewcuoco,SLOT(orderready(Order*)));
 disconnect(this,SIGNAL(ordineprep(Order*)),viewmanager,SLOT(orderready(Order*)));
}
