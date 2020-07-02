#include "cooker.h"

Cooker::Cooker():Employee(Role::cooker){

}
Cooker* Cooker::clone()const{
    return new Cooker(*this);
}

void Cooker::setstateready(Order *o){
    o->setState(ready);
}


