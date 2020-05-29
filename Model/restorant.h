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
     vector<Product*> filterProuduct(const QString& qs,Size sz=undefined );
};
#endif // RESTORANT_H
