#include "controller.h"

ControllerR::ControllerR(Restorant *mod, QObject *parent) : QObject(parent),view(nullptr),model(mod){}

void ControllerR::set_View(ClientWindow *v){
    view=v;
}

void ControllerR::FilterProductsonclick(const QString& qs){
    vector<Product*>v=model->filterProuduct(qs);
    QString test;
    for(auto it=v.begin();it!=v.end();it++)
        test=test+(*it)->Get_Categorie();
    view->ShowErrorMessage(test);
}

void ControllerR::Home(){

}

void ControllerR::resetOrdinazione(){

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

