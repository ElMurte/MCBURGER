#include "product.h"

Product::Product(const QString &c):categorie(c)
{

}
std::string Product::Get_Nome() const{
return nome;
}

std::string Product::Get_Description()const{
    return description;
}

unsigned short Product::Get_Calories() const{
    return calories;
}

float Product::Get_Price()const{
    return price;
}

Size Product::Get_Size() const{
    return size;
}

void Product::Set_Nome(const string& s){
    nome=s;
}

void Product::Set_Description(const string& dsc){
    description=dsc;
}

void Product::Set_Calories(const unsigned short & calor){
    calories=calor;
}

void Product::SetPrice(const float & prc){
    price=prc;
}

QString Product::Get_Categorie() const
{
    return categorie;
}

void Product::readInfoFromJson(const QJsonObject &json){
        nome=json["name"].toString().toUtf8().constData();
        description=json["description"].toString().toUtf8().constData();
        calories=json["calories"].toDouble();
        price=json["price"].toDouble();
        categorie=json["categories"].toString().toLower();
        size=Size(qRound(json["size"].toDouble()));
        icon=json["icon"].toString();
}

void Product::writeInfoInJson(QJsonObject &json) const{
        QString n(*(nome.begin())); QString d(*(description.begin()));
        json["name"]=n;
        json["description"]=d;
        json["calories"]=calories;
        json["price"]=price;
        json["categories"]=categorie;
        json["size"]=size;
}

