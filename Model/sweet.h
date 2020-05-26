#ifndef SWEET_H
#define SWEET_H
#include "Model/product.h"

class Sweet:public Product{
private:

public:
    Sweet();
    Sweet* clone() const override;
    void readInfoFromJson(const QJsonObject &json)override;
};

#endif // SWEET_H
