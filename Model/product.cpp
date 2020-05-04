#include "product.h"
Product::Product(std::string nome, std::string description, unsigned short calor, float price)
:nome(nome),description(description),calories(calor),price(price){
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

void Product::read(const QJsonObject &json){
        nome=json["name"].toString().toUtf8().constData();
        description=json["description"].toString().toUtf8().constData();
        calories=json["calories"].toDouble();
        price=json["price"].toDouble();
}

