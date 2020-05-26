#include "drink.h"

Drink::Drink():Product("Drink"){

}
Drink* Drink::clone() const{//ovverride from Product
    return new Drink(*this);
}

void Drink::readInfoFromJson(const QJsonObject &json){
Product::readInfoFromJson(json);//leggo i valori di product

}
