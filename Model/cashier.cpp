#include "cashier.h"

Cashier::Cashier():Employee(Role::cashier){

}
Cashier* Cashier::clone()const{
    return new Cashier(*this);
}

bool Cashier::ordercomplete(Order *i){
i->setState(State::complete);
return true;
}
