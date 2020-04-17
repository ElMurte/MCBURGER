#include "product.h"

Product::Product(){}

std::string Product::Get_Nome() const{
return nome;
}

std::string Product::Get_Description()const{
return description;
}

float Product::Get_Price()const{
    return price;
}
