#include "burger.h"

Burger::Burger(Size s):size(s){
}

Burger* Burger::clone() const{//ovverride from Product
    return new Burger(*this);
}

void Burger::write(QJsonObject &json) const{

}
