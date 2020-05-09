#ifndef BURGER_H
#define BURGER_H
#include "product.h"
#include <QJsonObject>
#include <iostream>
using std::cout;using std::endl;
class Burger : public Product
{
private:
Size size;
bool bacon;
bool glutenfree;
bool chicken;
public:
    Burger(Size =small,bool=false,bool =false,bool=false);
    Burger* clone() const;
    void write(QJsonObject &json) const;
    void printb(){
        cout<<nome<<endl<<description<<endl<<calories<<endl<<price<<endl;
    }
};

#endif // BURGER_H
