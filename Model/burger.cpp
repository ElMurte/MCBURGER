#include "burger.h"

Burger::Burger():Product("Burger"){
}


Burger* Burger::clone() const{//ovverride from Product
    return new Burger(*this);
}

void Burger::writeInfoInJson(QJsonObject &json) const{
Product::writeInfoInJson(json);
json["bacon"]=bacon;
json["glutenfree"]=glutenfree;
json["chicken"]=chicken;
}


void Burger::readInfoFromJson(const QJsonObject &json){
Product::readInfoFromJson(json);//leggo i valori di product
bacon=json["bacon"].toBool();
glutenfree=json["glutenfree"].toBool();
chicken=json["chicken"].toBool();
}
