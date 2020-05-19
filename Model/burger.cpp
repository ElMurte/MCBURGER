#include "burger.h"

Burger::Burger():Product("Burger"){
}


Burger* Burger::clone() const{//ovverride from Product
    return new Burger(*this);
}

void Burger::write(QJsonObject &json) const{

}

void Burger::readInfoFromJson(const QJsonObject &json){
Product::readInfoFromJson(json);//leggo i valori di product
bacon=json["bacon"].toBool() ;
glutenfree=json["description"].toBool();
chicken=json["chicken"].toBool();
}
