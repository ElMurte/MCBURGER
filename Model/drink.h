#ifndef DRINK_H
#define DRINK_H
#include "Model/product.h"

class Drink: public Product{
private:

public:
    Drink();
    Drink* clone() const override;
    void write(QJsonObject &json) const;
    void readInfoFromJson(const QJsonObject &json)override;
};

#endif // DRINK_H
