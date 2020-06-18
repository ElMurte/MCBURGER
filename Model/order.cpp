#include "order.h"
unsigned int Order::idord=0;
double Order::Gettotale() const{
    double i=0;
    for(auto it=menuord.begin();it!=menuord.end();it++){
        i=i+(*it)->Get_Price();
    }
    for(auto it=prdsord.begin();it!=prdsord.end();it++){
        i=i+(*it)->Get_Price();
    }
    return i;
}

Order::Order(State pay){
    idord++; totalbill=Gettotale();
paytype=pay;
}

