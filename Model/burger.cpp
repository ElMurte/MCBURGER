#include "burger.h"

Burger::Burger(Size s,bool b,bool g,bool c):size(s),bacon(b),glutenfree(g),chicken(c){
}


Burger* Burger::clone() const{//ovverride from Product
    return new Burger(*this);
}

void Burger::write(QJsonObject &json) const{

}
