#ifndef CAFFETTERIA_H
#define CAFFETTERIA_H
#include <Model/product.h>

class Caffetteria:public Product{
public:
    Caffetteria();
    Caffetteria* clone() const override;
    void readInfoFromJson(const QJsonObject &json)override;
};

#endif // CAFFETTERIA_H
