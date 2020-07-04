#include "caffetteria.h"

Caffetteria::Caffetteria():Product("Cafetteria"){

}
Caffetteria* Caffetteria::clone() const{//ovverride from Product
    return new Caffetteria(*this);
}

void Caffetteria::readInfoFromJson(const QJsonObject &json){
Product::readInfoFromJson(json);//leggo i valori di product
}
