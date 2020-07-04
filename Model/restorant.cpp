#include "restorant.h"
#include <QtDebug>
void Restorant::LoaddatafromJSON(){/*alloco la memoria per i prodotti e li legge dal file json*/
    Database::ReadProductfromJson<Product,Burger>("Burger",products);
    Database::ReadProductfromJson<Product,Patatine>("Patatine",products);
    Database::ReadProductfromJson<Product,Drink>("Drink",products);
    Database::ReadProductfromJson<Product,Sweet>("Sweet",products);
    Database::ReadEmployeefromJson<Employee,Cooker>("Cooker",employees);
    Database::ReadEmployeefromJson<Employee,Cashier>("Cashier",employees);
    Database::ReadEmployeefromJson<Employee,Manager>("Manager",employees);
}

Restorant::Restorant(){
LoaddatafromJSON();

}

vector<Product*> Restorant::filterProuduct(const QString &qs, double price, bool glf){
vector<Product*> r;
    if((price)==0 && !glf){
    for(auto it=products.begin();it!=products.end();it++){
        if((*it)->Get_Categorie().toLower().contains(qs.toLower()) ||  (*it)->Get_Nome().toLower().contains(qs.toLower()) )
            r.push_back(*it);
    }
    }
    if(qs=="" && price>0){
        for(auto it=products.begin();it!=products.end();it++){
        if( price>=(*it)->Get_Price())
            r.push_back(*it);
        }
    }
    if(qs=="" && !price && glf ){
        for(auto it=products.begin();it!=products.end();it++){
        if( 200>=(*it)->Get_Calories())
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
Cooker *Restorant::findacooker(){
    for(auto it=employees.begin();it!=employees.end();it++){
    if(dynamic_cast<Cooker*>(*it))
        return dynamic_cast<Cooker*>(*it);
    }
    return nullptr;
}

Order* Restorant::addOrder(Order*v){
orders.push_back(v);
return v;
}
/*utility function*/





