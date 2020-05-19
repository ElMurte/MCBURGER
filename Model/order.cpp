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

Order::Order(Menu * omenu, Payment pay){
    idord++;
menuord.push_back(omenu->clone()); totalbill=Gettotale();
paytype=pay;
}

Order::Order(Product *oprod, Payment pay){
    idord++;
    prdsord.push_back(oprod->clone()); totalbill=Gettotale();
    paytype=pay;
}

Order::Order(Menu *omenu, Product * oprod, Payment pay){
    idord++;
    prdsord.push_back(oprod->clone());
    menuord.push_back(omenu->clone());
    totalbill=Gettotale();
    paytype=pay;
}
