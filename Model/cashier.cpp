#include "cashier.h"

Cashier::Cashier():Employee(Role::Cashier){

}
class Cashier* Cashier::clone()const{
    return new Cashier(*this);
}
