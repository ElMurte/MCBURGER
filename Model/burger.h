#ifndef BURGER_H
#define BURGER_H
#include "product.h"
class Burger : public Product
{
private:
Size size;
public:
    Burger(Size size=small);
    Burger* clone() const;
};

#endif // BURGER_H
