#ifndef PATATINE_H
#define PATATINE_H
#include"product.h"
class Patatine : public Product
{
private:
Size size;
public:
    Patatine(Size=medium);
    Patatine* clone()const;
};

#endif // PATATINE_H
