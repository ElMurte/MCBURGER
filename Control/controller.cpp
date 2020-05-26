#include "controller.h"

ControllerR::ControllerR(Restorant *mod, QObject *parent) : QObject(parent),view(nullptr),model(mod){}

void ControllerR::set_View(ClientWindow *v){
    view=v;
}

void ControllerR::FilterProductsonclick(QString)
{

}

void ControllerR::Home()
{

}

void ControllerR::resetOrdinazione()
{

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

