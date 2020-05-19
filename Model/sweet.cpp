#include "sweet.h"

Sweet::Sweet():Product("Sweet"){

}
Sweet* Sweet::clone() const{//ovverride from Product
    return new Sweet(*this);
}

void Sweet::write(QJsonObject &json) const{

}

void Sweet::readInfoFromJson(const QJsonObject &json){
Product::readInfoFromJson(json);//leggo i valori di product

}
