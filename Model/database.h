#ifndef DATABASE_H
#define DATABASE_H
#include "Model/product.h"
#include "Model/burger.h"
#include "Model/sweet.h"
#include "Model/patatine.h"
#include "Model/drink.h"
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
using std::vector;using std::cout;

class Database{
private:
static QString dirproducts;
static QString diremployees;
static QJsonObject docprod;
static QJsonObject docempl;
public:
     void write(QJsonObject &json) const;
     template <class P,class C>
     static void readV(const QJsonArray &json,vector<P*>&);//utility function for readV()
     template<class P,class C>
     static void ReadProductfromJson(const QString & s, vector<P*>&v,const QJsonObject &json=docprod);
    /*********/
     //function to push C (concrtete class) into polimorf P* vector of type P
     static QJsonObject JsonreadFile(const QString& qs);
     template<class T> T whatis(const QJsonObject&);
};
template <class P,class C>
void Database::readV(const QJsonArray &json, vector<P*>&v){
    P*prod;
    for (int Index = 0; Index < json.size(); ++Index) {
        QJsonObject jsonObj = json[Index].toObject();
        prod=new C();
        prod->readInfoFromJson(jsonObj);/*chiamata polimorfa*/
        v.push_back(prod);
    }
}
template<class P,class C>
void Database::ReadProductfromJson(const QString & s, vector<P*>&v,const QJsonObject &json){
    if (json.contains(s) && json[s].isArray()) {
        QJsonArray jsonar = json[s].toArray();
        readV<P,C>(jsonar,v);
    }
}


#endif // DATABASE_H
