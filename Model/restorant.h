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

public:
    Restorant();
     void printproducts();
     template<class C>
     vector<C> filterProuduct(const QString& qs,QString size="" );
};
template<class C>
vector<C> Restorant::filterProuduct(const QString &qs,QString sz){
vector<C> r;
    for(auto it=products.begin();it!=products.end();it++){
        if(sz!="")
        if((*it)->Get_Categorie().toLower()==qs.toLower() && ( (*it)->Get_Size()==sz ) )
            r.push_back(*it);
    }
return r;
}
#endif // RESTORANT_H
