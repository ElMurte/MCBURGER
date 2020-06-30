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

unsigned int Order::Get_NumOrder(){
    return numordine;
}

Order::Order(vector<Product*>&v):prdsord(v),statetype(inpreparation),numordine(++idord){

}

void Order::setState(State s){
    statetype = s;
}

void Order::chiudiOrdine(){
        for (auto it=prdsord.begin();it!=prdsord.end();it++)
             delete *it;
        prdsord.clear();

        for (auto it=menuord.begin();it!=menuord.end();it++)
             delete *it;
        menuord.clear();
}

