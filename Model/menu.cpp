#include "menu.h"

Menu::Menu(Product *p,Size s):size(s){
    if(p){
        price=price+p->Get_Price();
        products.push_back(p);
    }
    else {
        price=0;
    }
}
