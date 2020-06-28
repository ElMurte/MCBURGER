#include "restorant.h"
#include <QtDebug>
void Restorant::LoaddatafromJSON(){/*alloco la memoria per i prodotti e li legge dal file json*/
    Database::ReadProductfromJson<Product,Burger>("Burger",products);
    Database::ReadProductfromJson<Product,Patatine>("Patatine",products);
    Database::ReadProductfromJson<Product,Drink>("Drink",products);
    Database::ReadProductfromJson<Product,Sweet>("Sweet",products);
    /*MENU ??? */
    /*Employes*/
}

Restorant::Restorant(){
LoaddatafromJSON();

}

vector<Product*> Restorant::filterProuduct(const QString &qs,Size sz){
vector<Product*> r;
    if((sz)==undefined){
    for(auto it=products.begin();it!=products.end();it++){
        if((*it)->Get_Categorie().toLower().contains(qs.toLower()) ||  (*it)->Get_Nome().toLower().contains(qs.toLower()) )
            r.push_back(*it);
    }
    }
    else{//non filtra
        for(auto it=products.begin();it!=products.end();it++){
        if((*it)->Get_Categorie().toLower()==qs.toLower() && sz==(*it)->Get_Size())
            r.push_back(*it);
        }
    }
    return r;
}

unsigned int Restorant::addOrder(vector<Product *> &v){
orders.push_back(new Order(v));
for(auto it=v.begin();it!=v.end();it++){
    delete *it;
    v.erase(it);
    it--;
}
v.clear();
return Order::idord;
}
/*utility function*/





