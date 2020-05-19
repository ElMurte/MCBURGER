#ifndef PATATINE_H
#define PATATINE_H
#include"product.h"
class Patatine : public Product
{
private:

public:
    Patatine();
    Patatine* clone()const override;
};

#endif // PATATINE_H
