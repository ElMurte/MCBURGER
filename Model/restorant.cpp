#include "restorant.h"
#include <QtDebug>
void Restorant::LoaddatafromJSON(){/*alloco la memoria per i prodotti e li legge dal file json*/
    Database::ReadProductfromJson<Product,Burger>("Burger",products);
    Database::ReadProductfromJson<Product,Patatine>("Patatine",products);
    Database::ReadProductfromJson<Product,Drink>("Drink",products);
    Database::ReadProductfromJson<Product,Sweet>("Sweet",products);
    Database::ReadProductfromJson<Product,Caffetteria>("Caffetteria",products);
    Database::ReadEmployeefromJson<Employee,Cooker>("Cooker",employees);
    Database::ReadEmployeefromJson<Employee,Cashier>("Cashier",employees);
    Database::ReadEmployeefromJson<Employee,Manager>("Manager",employees);
}

Restorant::Restorant(){
LoaddatafromJSON();
}

vector<Product*> Restorant::filterProuduct(const QString &qs){
vector<Product*> r;
    for(auto it=products.begin();it!=products.end();it++){
        if((*it)->Get_Categorie().toLower().contains(qs.toLower()) ||  (*it)->Get_Nome().toLower().contains(qs.toLower()) )
            r.push_back(*it);
    }
    return r;
}

vector<Product *> Restorant::getViewOfProducts(unsigned int calories, unsigned int price, bool colaz, bool glutenfree){
    vector<Product*> r;
        if(calories>0){
            for(auto it=products.begin();it!=products.end();it++){
            if((*it)->Get_Calories()<=100)
                r.push_back(*it);
            }
        }
        if(price>0){
            for(auto it=products.begin();it!=products.end();it++){
            if((*it)->Get_Price()<=price)
                r.push_back(*it);
            }
        }
        if(colaz){
            for(auto it=products.begin();it!=products.end();it++){
            if(dynamic_cast<Caffetteria*>(*it) ||dynamic_cast<Sweet*>(*it) )
               r.push_back(*it);
              }
        }
        if(glutenfree){
            for(auto it=products.begin();it!=products.end();it++){
            if(dynamic_cast<Burger*>(*it) && static_cast<Burger*>(*it)->getGlutenfree())
               r.push_back(*it);
              }
        }
        return r;
}

Employee *Restorant::userexist(const QString &qs, const QString &qs2){
    for(auto it=employees.begin();it!=employees.end();it++){
    if((*it)->getNome()==qs && (*it)->getPassword()==qs2)
        return (*it);
    }
    return nullptr;
}

Order* Restorant::addOrder(Order*v){
orders.push_back(v);
return v;
}
