#ifndef BURGER_H
#define BURGER_H
#include "product.h"
#include <QJsonObject>
#include <iostream>
using std::cout;using std::endl;
class Burger : public Product
{
private:
bool bacon;
bool glutenfree;
bool chicken;
public:
    Burger();
    Burger* clone() const override;
    void write(QJsonObject &json) const;
    void readInfoFromJson(const QJsonObject &json)override;
};

#endif // BURGER_H
