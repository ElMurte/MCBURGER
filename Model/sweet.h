#ifndef SWEET_H
#define SWEET_H
#include "Model/product.h"

class Sweet:public Product{
private:
QString tipo;
public:
    Sweet();
    Sweet* clone() const override;
    void readInfoFromJson(const QJsonObject &json)override;
};

#endif // SWEET_H
