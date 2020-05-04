#ifndef BURGER_H
#define BURGER_H
#include "product.h"
#include <QJsonObject>
class Burger : public Product
{
private:
Size size;
public:
    Burger(Size size=small);
    Burger* clone() const;
    void write(QJsonObject &json) const;
};

#endif // BURGER_H
