#include "controller.h"
#include "View/menubutton.h"
ControllerR::ControllerR(Restorant *mod, QObject *parent) : QObject(parent),view(nullptr),model(mod){}

void ControllerR::set_View(ClientWindow *v){
    view=v;
}

ControllerR::ControllerR(const ControllerR &c):QObject(new QObject()),model(c.model){
//costruttore di copia che non fa la copia del campo dati view
//perchè bisogna usarlo in questo modo per simulare più istanze
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

void ControllerR::getPointerProduct(const QString &qs){
        vector<Product*>v=model->filterProuduct(qs);
        Product* primo=*(v.begin());
        connect(this,SIGNAL(productdata(Product*)),view,SLOT(addWindowAddProduct(Product*)) );
             emit productdata(primo);
        //view->UpdateRightArea(a)
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
       connect(this,SIGNAL(ordineaggiunto(unsigned int)),view,SLOT(aggiornalistaord(unsigned int)));
    unsigned int num=model->addOrder(v);
    emit ordineaggiunto(num);
    disconnect(this,SIGNAL(ordineaggiunto(unsigned int)),view,SLOT(aggiornalistaord(unsigned int)));
}





/*void Controller::Move(unsigned short x, unsigned short y){
    //provo sd eseguire la mossa
    try {model->Move(x,y);
        view->Update();
        if(model->winner() || ((model->countFrame(player1))+(model->countFrame(player2)))==9){
            view->ShowWinner();
            resetGame();
        }
    }
    catch (std::exception* exc) {
        view->ShowErrorMessage(exc->what());
    }
//se la mossa va a buon aggiorno la vista e controllo il vincitore
//oppure dovrei aggiornare la vista con qualche messaggio
}*/

