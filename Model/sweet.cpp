#include "sweet.h"

Sweet::Sweet():Product("Sweet"){

}

Sweet *Sweet::clone() const{
return new Sweet(*this);
}
void Sweet::readInfoFromJson(const QJsonObject &json){
Product::readInfoFromJson(json);//leggo i valori di product
}
