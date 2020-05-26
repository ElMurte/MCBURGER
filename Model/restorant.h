#ifndef RESTORANT_H
#define RESTORANT_H
#include "Model/product.h"
#include "Model/employee.h"
#include "Model/menu.h"
#include<vector>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
#include<QFile>
#include<QDir>
#include<QString>
#include "Model/order.h"
#include"Model/database.h"
//partial delcalration has a
using std::vector;using std::cout;
/*JSON
classes who build runtime data such as menus: from JSON
*/
class Restorant{
private:
vector<Product*> products;
vector<Menu*> menus;
Dlist<Employee*> employees;
vector<Order*> ordtemp;
vector<Order*> ordinprep;
vector<Order*> ordready;
void LoaddatafromJSON();
public:
    Restorant();
     void printproducts();
     template<class C>
     vector<C> filterProuduct(const QString& qs,Size sz=undefined );
};
template<class C>
vector<C> Restorant::filterProuduct(const QString &qs,Size sz){
vector<Product*> r;
    if((sz)==undefined){
    for(auto it=products.begin();it!=products.end();it++){
        if((*it)->Get_Categorie().toLower()==qs.toLower() )
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
#endif // RESTORANT_H
