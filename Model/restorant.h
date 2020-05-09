#ifndef RESTORANT_H
#define RESTORANT_H
#include "Model/product.h"
#include "Model/burger.h"
#include "Model/patatine.h"
#include "Model/employee.h"
#include "Model/menu.h"
#include<vector>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
#include<QFile>
#include<QDir>
class Order;//partial delcalration has a
using std::vector;using std::cout;
/*JSON
classes who build runtime data such as menus: from JSON
*/
class Restorant{
private:
Dlist<Product*> products;
Dlist<Menu*> menus;
Dlist<Employee*> employees;
vector<Order*> ordtemp;
vector<Order*> ordinprep;
vector<Order*> ordready;

public:
    Restorant();
    void readArrey(const QJsonArray &json);/*funzione di utilita leggibilità*/
     void read(const QJsonObject &json);
     void write(QJsonObject &json) const;
     void printproducts();

};

#endif // RESTORANT_H
