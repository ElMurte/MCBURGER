#include "restorant.h"
#include <QtDebug>
void Restorant::LoaddatafromJSON(){/*alloco la memoria per i prodotti e li legge dal file json*/
    Database::ReadProductfromJson<Product,Burger>("Burger",products);
    Database::ReadProductfromJson<Product,Patatine>("Patatine",products);
    Database::ReadProductfromJson<Product,Drink>("Drink",products);
    Database::ReadProductfromJson<Product,Sweet>("Sweet",products);
    Database::ReadEmployeefromJson<Employee,class Cooker>("Cooker",employees);
    Database::ReadEmployeefromJson<Employee,class Cashier>("Cashier",employees);
    Database::ReadEmployeefromJson<Employee,class Manager>("Manager",employees);
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

Order* Restorant::addOrder(vector<Product *> &v){
orders.push_back(new Order(v));
v.clear();
return *(--orders.end());
}
/*utility function*/





