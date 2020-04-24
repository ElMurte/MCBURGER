#ifndef PATATINE_H
#define PATATINE_H
#include"product.h"
class Patatine : public Product
{
private:
Size size;
public:
    Patatine(Size=medium);
};

#endif // PATATINE_H
