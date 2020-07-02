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
#include"Model/database.h"//class to read data
//partial delcalration has a
using std::vector;using std::cout;
class Restorant{
private:
vector<Product*> products;
vector<Menu*> menus;
Dlist<Employee*> employees;//Container gerarchia G
vector<Order*> orders;
void LoaddatafromJSON();
public:
    Restorant();
     vector<Product*> filterProuduct(const QString& qs,Size sz=undefined );
     Employee* userexist(const QString& qs, const QString& qs2);
     Cooker* findacooker();
     Order* addOrder(Order*);
};
#endif // RESTORANT_H
