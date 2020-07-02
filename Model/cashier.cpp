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

Order *Cashier::createneworder(vector<Product *> &v)
{   if(!v.empty()){
    Order*ordine=new Order(v);
    v.clear();//puntatori vettore passato
    return ordine;
    }
    return nullptr;
}
