#include "cashier.h"

Cashier::Cashier(){

}
Cashier* Cashier::clone()const{
    return new Cashier(*this);
}
